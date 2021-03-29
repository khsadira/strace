#include <stdio.h>
#include "strace.h"

static char    *get_cmd(char *file, char **env) {
    char    **path_line = NULL;
    char    **path_bin = NULL;

    if (ft_strlen(file) > 1 && file[0] != '.' && file[0] != '/') {
        int i = 0;
        
        while (env[i]) {
            path_line = ft_strsplit(env[i], '=');

            if (strcmp(path_line[0], "PATH") == 0) {
                path_bin = ft_strsplit(path_line[1], ':');

                int j = 0;
                while (path_bin[j]) {
                    path_bin[j] = ft_strfjoin(ft_strfjoin(path_bin[j], "/"), file);
                    
                    if (access(path_bin[j], F_OK) == 0) {
                        char *ret = strdup(path_bin[j]);
                        ft_free_array(path_bin);
                        ft_free_array(path_line);
                        return ret;
                    }

                    j++;
                }
                
                ft_free_array(path_bin);
            }

            ft_free_array(path_line);
            i++;
        }
    }
    return strdup(file);
}

static int open_test(char *file) {
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return 1;
    close(fd);

    return 0;
}

int     main(int ac, char **av, char **env) {
    char *cmd;

    if (ac < 2) {
        fprintf(stderr, "Usage : %s prog args\n", av[0]);
        exit(EXIT_FAILURE);
    }

    cmd = get_cmd(av[1], env);


    if (open_test(cmd)) {
        printf("ft_strace: Can't stat '%s': No such file or directory\n", cmd);
        exit(EXIT_FAILURE);
    }
    child = fork();

    if (child == -1) {
        strerror(errno);
    } else if (child == 0) {
        execve(cmd, &av[1], env);
    } else {
        clear_signal();
        do_trace();
    }
    free(cmd);
}