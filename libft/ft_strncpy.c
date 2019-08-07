/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:40:09 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/01 19:36:15 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t a;
	size_t i;

	i = 0;
	a = 0;
	while (a != len)
	{
		if (src[i] != '\0')
		{
			dest[a] = src[i];
			i++;
		}
		else
			dest[a] = '\0';
		a++;
	}
	return (dest);
}
