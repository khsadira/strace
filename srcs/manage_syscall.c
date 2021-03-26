#include "strace.h"

static int print_start_syscall(int syscall) {
	printf("start\n%d", syscall);
    return 1;
}

static int print_end_syscall() {
    printf("end\n");    
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

int trace_syscall() {
    int     flag = 0;

    set_signal(1);
    while (1) {
        if (wait_syscall() != 0) {
            print_end_syscall();
            break;
        }
        ptrace(PTRACE_GETREGS, child, NULL, &regs);
        flag = flag ? print_end_syscall() : print_start_syscall(regs.orig_rax);
    }
    return 0;
}