/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 16:16:38 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/08 15:13:41 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t needlen;
	size_t h;

	h = 0;
	needlen = ft_strlen(need);
	if (len > ft_strlen(hay))
		len = ft_strlen(hay);
	if (needlen == 0)
		return ((char *)hay);
	if (len < needlen)
		return (NULL);
	while (h <= len - ft_strlen(need))
	{
		if (ft_strncmp(&hay[h], need, needlen) == 0)
			return ((char *)&hay[h]);
		h++;
	}
	return (NULL);
}
