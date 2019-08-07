/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 16:42:35 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/04 18:17:09 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t i;
	size_t start;

	i = 0;
	if (s[i] == 0)
		return ((char *)s);
	while (ft_isspace(s[i]) != 0)
	{
		i++;
		if (s[i] == '\0')
			return ("");
	}
	start = i;
	i = ft_strlen(s) - 1;
	while (ft_isspace(s[i]) != 0)
		i--;
	if (ft_strsub(s, start, i + 1 - start) == NULL)
		return (NULL);
	return (ft_strsub(s, start, i + 1 - start));
}
