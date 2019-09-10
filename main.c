#include "printf.h"
#include "libft.h"
#include <stdio.h>

#define FORMAT "%#.o\n"

int main(void)
{
    long long   b;
    int         ret;
    int         myret;

    b = 9223372036854775807;
    ret = printf(ft_strjoin("real", FORMAT), 0);
    myret = ft_printf(ft_strjoin("fake", FORMAT), 0);
    ft_printf("ret: %d\n", ret);
    ft_printf("myret: %d\n", myret);
    return (0);
}