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

char	*ldoubletostr(int sign, long double nb, char *predot, int precision)
{
	int		k;
	int		prelen;
	char	*str;

	k = 0;
	prelen = ft_strlen(predot);
	str = ft_strnew(sign + prelen + precision + 1);
	if (sign == 1)
		str[0] = '-';
	ft_strcpy(&str[sign], predot);
	while (k < precision)
	{
		if (k == 0)
			str[prelen + sign] = '.';
		nb *= 10;
		str[k + 1 + prelen + sign] = (uint64_t)nb + '0';
		nb -= (uint64_t)nb;
		k++;
	}
	return (rounding(&str, nb, precision, k));
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
	retstr = ft_strdup(ft_exceptions(nb));
	if (retstr != NULL)
		return (retstr);
	if (nb < 0 || 1.0 / nb == -1.0 / 0.0)
	{
		sign = 1;
		nb *= -1;
	}
	retstr = ft_utoa((uint64_t)nb);
	return (doubletostr(sign, nb - (uint64_t)nb, retstr, precision));
}
