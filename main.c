#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
    float   f;
    int ret;
    int myret;

    f = 4;
    ret = printf("real %.5f\n", f);
    myret = ft_printf("fake %.5f\n", f);
    printf("ret: %d\n", ret);
    printf("myret: %d\n", myret);
    return (0);
}