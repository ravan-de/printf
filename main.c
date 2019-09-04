#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
    int ret;
    int myret;
    #define FORMAT "test %#.0x\n"
    
    ret = printf(FORMAT, 1);
    myret = ft_printf(FORMAT, 1);
    printf("ret: %d\n", ret);
    printf("myret: %d\n", myret);
    return (0);
}

//if str[0] == '0' don't add extra 0;