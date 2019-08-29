#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
    int ret;
    int myret;
    #define FORMAT "test %#010x"
    
    ret = printf(FORMAT, 420);
    ft_putendl("");
    myret = ft_printf(FORMAT, 420);
    ft_putendl("");
    ft_printf("ret: %d\n", ret);
    ft_printf("myret: %d\n", myret);
    return (0);
}