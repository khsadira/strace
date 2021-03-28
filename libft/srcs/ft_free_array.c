#include "libft.h"
#include <stdlib.h>

int ft_free_array(char **array) {
    int i = 0;
    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
    return 0;
}