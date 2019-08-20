#include <stdio.h>
#include <stdarg.h>
#include "printf.h"
#include "libft/includes/libft.h"

void    ft_lol(char *str, ...)
{
    va_list arglst;
    void    *ptr;
    short     temp;

    va_start(arglst, str);
    temp = (short)va_arg(arglst, int);
    ptr = &temp;
    ft_putnbr(*(short *)(ptr));
}

int main (void)
{
    ft_lol("test", 32777);
    printf("%hi", 32777);
    return (0);
}