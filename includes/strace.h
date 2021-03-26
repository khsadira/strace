#ifndef FT_PING_H
#define FT_PING_H

#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <linux/unistd.h>
#include <fcntl.h>

# include "../libft/includes/libft.h"

int         status;
struct      user_regs_struct regs;
pid_t       child;

void    clear_signal();
void    add_block_signal();
void    set_signal(int is_start);
char    *get_signal_name(int key);

int     trace_syscall();

int     get_errno_name(int key);

#endif