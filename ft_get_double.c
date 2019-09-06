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
#include "printf.h"

char	*ft_assemble_float(char **intstr, long long val, int zeros, int prec)
{
	char	*decstr;
	char	*str;

	if (val == 0)
	{
		str = ft_strnew(ft_strlen(*intstr) + 1 + prec);
		ft_strcpy(str, *intstr);
		str[ft_strlen(str)] = '.';
		ft_memset(&str[ft_strlen(str)], '0', prec);
		free(*intstr);
		return (str);
	}
	decstr = ft_get_int(val);
	str = ft_strnew(ft_strlen(*intstr) + 1 + zeros + ft_strlen(decstr));
	ft_strcpy(str, *intstr);
	str[ft_strlen(str)] = '.';
	ft_memset(&str[ft_strlen(str)], '0', zeros);
	ft_strcat(str, decstr);
	free(*intstr);
	free(decstr);
	return (str);
}

char	*ft_decimals(char **intstr, double nb, int precision)
{
	long long	val;
	int			i;
	int			nul;

	nul = 0;
	i = 0;
	if (nb < 0)
		nb *= -1;
	while (i < precision)
	{
		i++;
		nb *= 10;
		if ((long long)nb == 0)
			nul++;
	}
	val = (long long)nb;
	nb -= val;
	if (nb > 0.5)
		val += 1;
	return (ft_assemble_float(intstr, val, nul, precision));
}

char	*ft_ldecimals(char **intstr, long double nb, int precision)
{
	long long	val;
	int			i;
	int			nul;

	nul = 0;
	i = 0;
	if (nb < 0)
		nb *= -1;
	while (i < precision)
	{
		i++;
		nb *= 10;
		if ((long long)nb == 0)
			nul++;
	}
	val = (long long)nb;
	nb -= val;
	if (nb > 0.5)
		val += 1;
	return (ft_assemble_float(intstr, val, nul, precision));
}

char	*ft_get_double(double nb, int precision)
{
	char		*str;
	long long	value;

	value = (long long)nb;
	nb -= value;
	if (precision == 0 && nb > 0.5)
		value += 1;
	if (precision == 0 && nb < -0.5)
		value -= 1;
	if (precision == 0 && nb == 0.5 && (value + 1) % 2 == 0)
		value += 1;
	if (precision == 0 && nb == -0.5 && (value - 1) % 2 == 0)
		value -= 1;
	str = ft_get_int(value);
	if (precision > 0)
		str = ft_decimals(&str, nb, precision);
	return (str);
}

char	*ft_get_ldouble(long double nb, int precision)
{
	char		*str;
	long long	value;

	value = (long long)nb;
	nb -= value;
	if (precision == 0 && nb * ft_power(10, 6) > 0.5)
		value += 1;
	if (precision == 0 && nb * ft_power(10, 6) < -0.5)
		value -= 1;
	if (precision == 0 && nb == 0.5 && (value + 1) % 2 == 0)
		value += 1;
	if (precision == 0 && nb == -0.5 && (value - 1) % 2 == 0)
		value -= 1;
	str = ft_get_int(value);
	if (precision > 0)
		str = ft_ldecimals(&str, nb, precision);
	return (str);
}
