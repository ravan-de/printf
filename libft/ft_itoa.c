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

static void	ft_getnb(int nb, int index, char *str)
{
	if (nb > 9)
	{
		ft_getnb(nb / 10, index - 1, str);
		nb = nb % 10;
	}
	nb += '0';
	str[index] = (char)nb;
}

static int	ft_len(int n)
{
	int count;

	count = 1;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_len(n);
	if (n < 0)
	{
		str = ft_strnew(len + 1);
		if (str == NULL)
			return (NULL);
		if (n == -2147483648)
			return (ft_strcpy(str, "-2147483648"));
		str[0] = '-';
		n *= -1;
		i = 1;
	}
	else
		str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	ft_getnb(n, len + i - 1, str);
	return (str);
}
