/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 18:44:35 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/18 17:39:03 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL || src == NULL)
		return (NULL);
	if (len < 1)
		return (dst);
	if (src > dst)
		ft_memcpy(dst, src, len);
	if (src < dst)
		ft_memrcpy(dst, src, len);
	return (dst);
}
