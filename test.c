#include <stdio.h>
#include <stdarg.h>
#include "printf.h"
#include "libft/includes/libft.h"

char	*ft_get_int(long long nb)
{
	char	*str;
	int		i;

	str = ft_strnew(20);
	i = 0;
	if (nb == -9223372036854775808)
	{
		strcpy(str, "-922337203685477580");
		nb = 8;
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb / ft_power(10, i) > 9)
		i++;
	str[ft_strlen(str)] = nb / ft_power(10, i) + '0';
	while (i > 0)
	{
		i--;
		str[ft_strlen(str)] = nb / ft_power(10, i) % 10 + '0';
	}
	return (str);
}

void    ft_lol(void)
{
    double   b;
    int precision;
    long long value;

    precision = 4;
    b = 10.5001;
    printf("%.*f\n", precision, b);
    value = (long long)b;
    b -= value;
    if (precision == 0 && b > 0.5)
        value += 1;
    ft_putnbr(value);
    if (precision > 0)
    {
        if (b < 0)
            b *= -ft_power(10, precision);
        else
            b *= ft_power(10, precision);
        value = (long long)b;
        b -= value;
        if (b > 0.5)
            value += 1;
    ft_putchar('.');
    ft_putstr(ft_get_int(value));
    }
}

void    ft_tet(void)
{
    double b;

    b = 10.35324;
    ft_putnbr(sizeof(b));
}

int main (void)
{
    ft_tet();
    return (0);
}