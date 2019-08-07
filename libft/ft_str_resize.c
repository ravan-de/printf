/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 17:58:55 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/26 14:13:08 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_str_resize(char *ptr, size_t newsize)
{
	char	*newptr;

	newptr = ft_strnew(newsize);
	if (newptr == NULL || ptr == NULL)
		return (newptr);
	ft_strncpy(newptr, ptr, newsize);
	newptr[newsize] = '\0';
	ft_strdel(&ptr);
	return (newptr);
}
