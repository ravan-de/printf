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

char	*ft_decimals(double nb, int precision)
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
	if (nb > (double)0.5)
		val += 1;
	if (val == 0)
		return (ft_memset(ft_strnew(precision), '0', precision));
	return (ft_strjoin(ft_memset(ft_strnew(nul), '0', nul), ft_get_int(val)));
}

char	*ft_ldecimals(long double nb, int precision)
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
	if (val == 0)
		return (ft_memset(ft_strnew(precision), '0', precision));
	return (ft_strjoin(ft_memset(ft_strnew(nul), '0', nul), ft_get_int(val)));
}

char	*ft_get_double(double nb, int precision)
{
	char		*str;
	char		*decimals;
	char		*temp;
	long long	value;

	decimals = NULL;
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

char	*ft_get_ldouble(long double nb, int precision)
{
	char		*str;
	char		*decimals;
	char		*temp;
	long long	value;

	decimals = NULL;
	value = (long long)nb;
	nb -= value;
	if (precision == 0 && nb * ft_power(10, 6) > 0.5)
		value += 1;
	if (precision == 0 && nb * ft_power(10, 6)< -0.5)
		value -= 1;
	str = ft_get_int(value);
	if (precision > 0)
		decimals = ft_ldecimals(nb, precision);
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
