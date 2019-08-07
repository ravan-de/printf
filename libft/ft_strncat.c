/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 18:59:04 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/05 17:21:58 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t len;

	len = ft_strlen(s1);
	if (ft_strlen(s2) < n)
		n = ft_strlen(s2);
	if (n == 0)
		return (s1);
	ft_strncpy(&s1[len], s2, n);
	s1[len + n] = '\0';
	return (s1);
}
