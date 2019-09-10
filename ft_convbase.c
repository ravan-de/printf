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
#include <stdlib.h>

char	*ft_convbase(uint64_t nb, uint64_t base)
{
	char	*str;
	int		i;
	int		c;

	c = 0;
	i = 0;
	while (nb / ft_power(base, i) >= base)
		i++;
	str = ft_strnew(i + 1);
	if (nb / ft_power(base, i) > 9)
		str[c] = nb / ft_power(base, i) + 87;
	else
		str[c] = nb / ft_power(base, i) + 48;
	while (i > 0)
	{
		i--;
		c++;
		if (nb / ft_power(base, i) % base > 9)
			str[c] = nb / ft_power(base, i) % base + 87;
		else
			str[c] = nb / ft_power(base, i) % base + 48;
	}
	return (str);
}
