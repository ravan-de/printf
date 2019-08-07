/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 15:36:33 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/05 17:21:46 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t len;

	len = ft_strlen(s1) + ft_strlen(s2);
	ft_strcpy(ft_strchr(s1, 0), s2);
	s1[len] = '\0';
	return (s1);
}
