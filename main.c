#include "printf.h"
#include "libft.h"
#include <stdio.h>

#define FORMAT " %p\n"

int main(void)
{
    static int  a;
    int         b;
    int         ret;
    int         myret;

    a = 20;
    b = 20;
    ret = printf(ft_strjoin("real", FORMAT), &b);
    myret = ft_printf(ft_strjoin("fake", FORMAT), &b);
    ft_printf("ret: %d\n", ret);
    ft_printf("myret: %d\n", myret);
    return (0);
}