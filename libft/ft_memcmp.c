/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 17:40:13 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/02 16:20:31 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*saus1;
	unsigned char	*saus2;
	size_t			i;

	i = 0;
	saus1 = (unsigned char *)s1;
	saus2 = (unsigned char *)s2;
	if (n < 1)
		return (0);
	while (saus1[i] == saus2[i] && i < n - 1)
		i++;
	return (saus1[i] - saus2[i]);
}
