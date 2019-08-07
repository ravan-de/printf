/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 19:29:28 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/04 21:03:24 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t lendst;

	i = 0;
	lendst = ft_strlen(dst);
	if (size <= lendst)
		return (ft_strlen(src) + size);
	ft_strncat(dst, (char *)src, size - lendst - 1);
	if (size < lendst + ft_strlen(src) + 1)
		return (lendst + ft_strlen(src));
	return (ft_strlen(dst));
}
