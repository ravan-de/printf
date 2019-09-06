#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
    float   f;
    int ret;
    int myret;

    f = -5.5;
    ret = printf("real %.0f\n", f);
    myret = ft_printf("fake %.0f\n", f);
    printf("ret: %d\n", ret);
    printf("myret: %d\n", myret);
    return (0);
}