/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 20:43:34 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/18 17:37:19 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*saus;
	char	*dest;
	size_t	i;

	i = 0;
	saus = (char *)src;
	dest = (char *)dst;
	while (i < n)
	{
		dest[i] = saus[i];
		i++;
	}
	return (dst);
}
