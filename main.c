#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
    #define FORMAT "Alleen maar %s mayo %.20f%c vet\n"
    printf(FORMAT, "zaanse", 0.3, '%');
    ft_printf(FORMAT, "zaanse", 0.3, '%');
    printf("%5%\n");
    ft_printf("%5%\n");
}