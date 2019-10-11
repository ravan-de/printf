/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 18:16:11 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/10 17:35:59 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_getnb(uint64_t nb, size_t index, char *str)
{
	if (nb > 9)
	{
		ft_getnb(nb / 10, index - 1, str);
		nb = nb % 10;
	}
	nb += '0';
	str[index] = (char)nb;
}

int		ft_len(uint64_t n)
{
	int count;

	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_utoa(uint64_t n)
{
	size_t	len;
	char	*str;

	len = ft_len(n);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	ft_getnb(n, len - 1, str);
	return (str);
}
