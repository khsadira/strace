#include "strace.h"

static unsigned long long int select_register(int i) {
	switch(i) {
		case 0:
            return regs.rdi;
		case 1:
            return regs.rsi;
		case 2:
            return regs.rdx;
		case 3:
            return regs.r10;
		case 4:
            return regs.r8;
		case 5:
            return regs.r9;
		default:
            return 0;
	}
}


static int	is_print(char c) {
	if (ft_isprint(c) || c == '\n') {
		return (1);
	}
	return (0);
}

static int	is_printable(char *str) {
	int i = -1;

	while (str && str[++i]) {
		if  (!is_print(str[i])) {
			return (0);
        }
	}
	if (i == 0) {
		return (0);
    }
	return (1);
}

static void get_data(long reg) {
	char 	message[10000] = {0};
	char 	*temp = message;
	long 	res = 100;
	int 	i = 0;
	
	while (i < 8) {
		res = ptrace(PTRACE_PEEKDATA, child, reg + (i * 8), NULL);
		memcpy(temp, &res, 8);
		temp += 8;
        i++;
	}
	if (!errno) {
		is_printable(message) ? printf("\"%s\"", (message)) : printf("%p", &message);
    } else {
		printf("%ld", reg);
    }
}

static void 	get_array_data(unsigned long addr, t_syscall const syscall) {
	int		len;
	char	**tmp;

	len = 0;
	tmp = (char **)addr;
	while (tmp && tmp[len])
		len++;
	if (len > syscall.sys_argc)
		printf("[*/ %d vars */]", len);
	else {
		printf("[");
		get_data(regs.rdi);
		printf("]");
	}
}

static int print_syscall(t_syscall const syscall) {
	printf("%s(", syscall.sys_name);

    int i = 0;
	while (i < syscall.sys_argc) {
		if (regs.rdi == 0 && i == 0)
			regs.orig_rax == SYS_exit_group ? printf("0") : syscall.sys_argv[0] == E_INT ? printf("0") : printf("NULL");
		else {
			switch (syscall.sys_argv[i]) {
				case E_INT:
                    printf("%lld", select_register(i));
					break;
				case E_UINT:
                    printf("%llu", select_register(i));
					break;
				case E_STR:
                    get_data(select_register(i));
					break;
				case E_SPE:
                    get_array_data(select_register(i), syscall);
					break;
				case E_PTR:
                    get_data(select_register(i));
					break;
				case E_STRUCT:
                    select_register(i) ? printf("{ 0x%llx }", select_register(i)) : printf("NULL");
					break;
				default:
                    printf("ERROR");
					break;
			}
		}
		i + 1 < syscall.sys_argc ? printf(", ") : printf(")");
        i++;
	}
	return 1;
}

static int print_syscall_ret() {
	if (regs.orig_rax == SYS_exit_group || WSTOPSIG(status) == SIGSEGV){
		if (WIFEXITED(status))
			printf("= ? \n+++ exited with %d +++\n", WEXITSTATUS(status));
		else if (WIFSTOPPED(status))
			printf("+++ killed by %s +++\n%s\n", get_signal_name(WSTOPSIG(status)), sys_siglist[WSTOPSIG(status)]);
	}
	else if ((long)regs.rax == -1)
		printf(" = ?\n");
	else if ((long)regs.rax == -516)
		printf(" = ? ERESTART_RESTARTBLOCK (Interrupted by signal)\n");
	else if ( (long)regs.rax < -1) {
		printf(" = -1 ");
		get_errno_name((long)regs.rax);
		printf("\n");
	}
	else if ((long)regs.rax > 10000 || (long)regs.rax < -1000)
		printf(" = %p\n", &regs.rax);
	else
		printf(" = %lld\n", regs.rax);

	return 0;
}

static int wait_syscall() {
    set_signal(0);
    if (WIFEXITED(status)) {
        return 1; 
    } else if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80) {
        return 0;
    } else if (WIFSTOPPED(status)) {
        if (WSTOPSIG(status) != SIGTRAP) {
            printf("--- %s ---\n", get_signal_name(WSTOPSIG(status)));
            if (WSTOPSIG(status) == SIGSEGV) {
                return 1;
            }
            set_signal(0);
        }
    }
    if ((WIFSIGNALED(status) || WTERMSIG(status)) && (WEXITSTATUS(status) == SIGINT || WEXITSTATUS(status) == SIGHUP)) {
            printf("./ft_strace : Process detached : %d\n", child);
            exit(EXIT_FAILURE);
    }
    return 0;
}

static int manage_syscall(int flag, unsigned long long rax) {
	return flag ? print_syscall_ret() : print_syscall(syscall_table[rax]);
}

int do_trace() {
    int     flag = 0;

    set_signal(1);
    while (1) {
        if (wait_syscall()) {
            print_syscall_ret();
            break;
        }
        ptrace(PTRACE_GETREGS, child, NULL, &regs);
		flag = manage_syscall(flag, regs.orig_rax);
    }
    return 0;
}