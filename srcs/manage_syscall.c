#include "strace.h"

int     wait_for_syscall() {
    while (1) {
        set_sigs(0);
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
                set_sigs(0);
            }
        }
        if ((WIFSIGNALED(status) || WTERMSIG(status)) && (WEXITSTATUS(status) == SIGINT || WEXITSTATUS(status) == SIGHUP)) {
                printf("./ft_strace : Process detached : %d\n", child);
                exit(EXIT_FAILURE);
        }
        return 0;
    }
}

int     trace_syscall() {
    int     flag = 0;

    set_sigs(1);
    while (1) {
        if (wait_for_syscall() != 0) {
            break;
        }
        ptrace(PTRACE_GETREGS, child, NULL, &regs);
    }
    return 0;
}