#ifndef FT_STRACE_H
#define FT_STRACE_H

# include <sys/types.h>
# include <sys/ptrace.h>
# include <sys/user.h>
# include <sys/wait.h>
# include <sys/syscall.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <linux/unistd.h>
# include <fcntl.h>

# include "../libft/includes/libft.h"

# define SYSCALL_NUMBER 333


int         status;
struct      user_regs_struct regs;
pid_t       child;

void    clear_signal();
void    add_block_signal();
void    set_signal(int is_start);
char    *get_signal_name(int key);

int     do_trace();

int     get_errno_name(int key);


enum e_param {
	E_NONE   = 0,
	E_INT    = 1,
	E_UINT   = 2,
	E_PTR    = 3,
	E_STR    = 4,
	E_STRUCT = 5,
    E_SPE    = 6
};

typedef struct		s_syscall {
	char const *const			sys_name;
	int const					sys_argc;
	enum e_param const          sys_argv[7];
}					t_syscall;

extern t_syscall const syscall_table[SYSCALL_NUMBER];

#endif