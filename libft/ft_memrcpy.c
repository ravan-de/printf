/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 15:00:28 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/02 15:04:41 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	char	*saus;
	char	*dest;
	size_t	i;

	i = n - 1;
	saus = (char *)src;
	dest = (char *)dst;
	while (i > 0)
	{
		dest[i] = saus[i];
		i--;
	}
	dest[i] = saus[i];
	return (dst);
}
