/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:56:32 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/05 17:37:14 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == 0)
			return (NULL);
		i++;
	}
	return ((char *)&str[i]);
}
