#include <stdio.h>
#include "printf.h"
#include "libft/includes/libft.h"

int main (void)
{
    t_flags flag;
    char c;

    c = 'p';
    flag = c;
    ft_putnbr(flag);
    ft_putendl("");
    flag = P;
    ft_putnbr(flag);
    ft_putendl("");
    //printf("test:%lD", 2342353240);
    return (0);
}