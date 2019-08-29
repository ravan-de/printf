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

#include "printf.h"
#include "libft.h"
#include <stdlib.h>

char	*ft_get_int(long long nb)
{
	char	*str;
	int		i;

	str = ft_strnew(20);
	i = 0;
	if (nb == -9223372036854775808)
	{
		ft_strcpy(str, "-922337203685477580");
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

char	*ft_get_uns(uint64_t nb)
{
	return (ft_convbase(nb, 10));
}

char	*ft_get_oct(uint64_t nb)
{
	return (ft_convbase(nb, 8));
}

char	*ft_get_hex(uint64_t nb)
{
	return (ft_convbase(nb, 16));
}

char	*ft_get_bin(uint64_t nb)
{
	return (ft_convbase(nb, 2));
}
