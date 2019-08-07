/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 16:16:38 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/05 17:37:42 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t h;
	size_t needlelen;

	h = 0;
	needlelen = ft_strlen(needle);
	if (needlelen == 0)
		return ((char *)haystack);
	if (ft_strlen(haystack) < needlelen)
		return (NULL);
	while (haystack[h + needlelen - 1] != 0)
	{
		if (ft_strncmp(&haystack[h], needle, needlelen) == 0)
			return ((char *)&haystack[h]);
		h++;
	}
	return (NULL);
}
