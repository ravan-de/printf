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

char	*lrounding(char **str, long double nb, int precision, unsigned k)
{
	char *retstr;

	if (precision == 0 && nb > 0.5)
		retstr = ft_strsum(*str, "1");
	else if (precision == 0 && nb == 0.5 && ((*str)[k - 1] - '0') % 2 != 0)
		retstr = ft_strsum(*str, "1");
	else if (precision > 0 && nb > 0.5)
		retstr = ft_strsum(*str, "1");
	else
		retstr = ft_strdup(*str);
	free(*str);
	return (retstr);
}

char	*ldoubletostr(int sign, long double nb, unsigned predot, int precision)
{
	unsigned	k;
	char		*str;
	int			dot;

	dot = 0;
	if (precision != 0)
		dot = 1;
	str = ft_strnew(sign + predot + dot + precision);
	if (sign == 1)
		str[0] = '-';
	k = sign;
	while (k < sign + predot + dot + precision)
	{
		if (k == predot + sign && precision > 0)
			str[k] = '.';
		else
		{
			nb *= 10;
			str[k] = '0' + (unsigned)nb;
			nb -= (unsigned)nb;
		}
		k++;
	}
	return (lrounding(&str, nb, precision, k));
}

char	*ft_lexceptions(long double nb)
{
	if (nb != nb)
		return ("NaN");
	if (nb == -1.0 / 0.0)
		return ("-inf");
	if (nb == 1.0 / 0.0)
		return ("inf");
	return (NULL);
}

char	*ft_get_ldouble(long double nb, int precision)
{
	char		*retstr;
	unsigned	predot;
	int			sign;

	sign = 0;
	predot = 0;
	retstr = ft_strdup(ft_lexceptions(nb));
	if (retstr != NULL)
		return (retstr);
	if (nb < 0 || 1.0 / nb == -1.0 / 0.0)
	{
		sign = 1;
		nb *= -1;
	}
	while (nb > 1)
	{
		nb /= 10;
		predot++;
	}
	if (predot == 0)
	{
		predot = 1;
		nb /= 10;
	}
	return (ldoubletostr(sign, nb, predot, precision));
}
