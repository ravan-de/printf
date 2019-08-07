/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 21:33:16 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/02 14:51:08 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*saus;
	unsigned char	*dest;
	size_t			i;

	i = 0;
	saus = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (n == 0)
		return (NULL);
	while (saus[i] != (unsigned char)c)
	{
		dest[i] = saus[i];
		if (i == n - 1)
			return (NULL);
		i++;
	}
	dest[i] = saus[i];
	return (ft_memchr(dst, c, n) + 1);
}
