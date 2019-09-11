#include "printf.h"
#include "libft.h"
#include <stdio.h>

#define FORMAT " %.0f\n"

int main(void)
{
	double	f;
    int         ret;
    int         myret;

    f = 1.0 / 0.0;
    ret = printf(ft_strjoin("real", FORMAT), f);
    myret = ft_printf(ft_strjoin("fake", FORMAT), f);
    ft_printf("ret: %d\n", ret);
    ft_printf("myret: %d\n", myret);
    return (0);
}
