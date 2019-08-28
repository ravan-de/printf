/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/30 14:35:14 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/07/30 14:35:16 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_decimals(double nb, int precision)
{
    long long value;

    if (nb < 0)
        nb *= -ft_power(10, precision);
    else
        nb *= ft_power(10, precision);
    value = (long long)nb;
    nb -= value;
    if (nb > 0.5)
        value += 1;
    return (ft_get_int(value));
}

char    *ft_get_double(double nb, int precision)
{
    ft_putstr("test");
    char        *str;
    char        *decimals;
    char        *temp;
    long long   value;

    decimals = NULL;
    value = (long long)nb;
    nb -= value;
    if (precision == 0 && nb > 0.5)
        value += 1;
    if (precision == 0 && nb < 0.5)
        value -= 1;
    str = ft_get_int(value);
    if (precision > 0)
        decimals = ft_decimals(nb, precision);
    if (decimals != NULL)
    {
        temp = ft_strjoin(str, ".");
        free(str);
        str = ft_strjoin(temp, decimals);
        free(temp);
        free(decimals);
    }
    return (str);
}