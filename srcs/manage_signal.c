#include "strace.h"

void    add_block_signal() {
    sigset_t    sig_blocker;

    sigaddset(&sig_blocker, SIGQUIT);
    sigaddset(&sig_blocker, SIGHUP);
    sigaddset(&sig_blocker, SIGINT);
    sigaddset(&sig_blocker, SIGPIPE);
    sigaddset(&sig_blocker, SIGTERM);
    sigprocmask(SIG_BLOCK, &sig_blocker, NULL);
}

void    clear_signal() {
    sigset_t    empty;

    sigemptyset(&empty);
    sigprocmask(SIG_SETMASK, &empty, NULL);
}

void    set_sigs(int is_start) {
    ptrace(PTRACE_SYSCALL, child, 0, 0);
    ptrace(PTRACE_SEIZE, child, 0, 0);

    if (is_start) {
        ptrace(PTRACE_INTERRUPT, child, 0, 0);
    }
    
    waitpid(child, &status, 0);
    clear_signal();
    add_block_signal();
    ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
}

char *get_signal_name(int key) {
	switch (key) {
		case (SIGHUP):
			return "SIGHUP";
		case (SIGINT):
			return "SIGINT";
		case (SIGQUIT):
			return "SIGQUIT";
		case (SIGILL):
			return "SIGILL";
		case (SIGTRAP):
			return "SIGTRAP";
		case (SIGABRT):
			return "SIGABRT";
		case (SIGBUS):
			return "SIGBUS";
		case (SIGFPE):
			return "SIGFPE";
		case (SIGKILL):
			return "SIGKILL";
		case (SIGUSR1):
			return "SIGUSR1";
		case (SIGSEGV):
			return "SIGSEGV";
		case (SIGUSR2):
			return "SIGUSR2";
		case (SIGPIPE):
			return "SIGPIPE";
		case (SIGALRM):
			return "SIGALRM";
		case (SIGTERM):
			return "SIGTERM";
		case (SIGCHLD):
			return "SIGCHLD";
		case (SIGCONT):
			return "SIGCONT";
		case (SIGSTOP):
			return "SIGSTOP";
		case (SIGTSTP):
			return "SIGTSTP";
		case (SIGTTIN):
			return "SIGTTIN";
		case (SIGTTOU):
			return "SIGTTOU";
		case (SIGURG):
			return "SIGURG";
		case (SIGXCPU):
			return "SIGXCPU";
		case (SIGVTALRM):
			return "SIGVTALRM";
		case (SIGPROF):
			return "SIGPROF";
		case (SIGWINCH):
			return "SIGWINCH";
		case (SIGPOLL):
			return "SIGPOLL";
		case (SIGPWR):
			return "SIGPWR";
		case (SIGSYS):
			return "SIGSYS";
		default:
			return "unknow signal";
	}
}