#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
    int ret;
    int myret;
    #define FORMAT "test %2%\n"
    
    ret = printf(FORMAT);
    myret = ft_printf(FORMAT);
    printf("ret: %d\n", ret);
    printf("myret: %d\n", myret);
    return (0);
}

//if str[0] == '0' don't add extra 0