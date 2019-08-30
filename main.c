#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
    int ret;
    int myret;
    #define FORMAT "test %10d\n"
    
    ret = printf(FORMAT, 420);
    ft_putendl("");
    myret = ft_printf(FORMAT, 420);
    ft_putendl("");
    printf("ret: %d\n", ret);
    printf("myret: %d\n", myret);
    return (0);
}