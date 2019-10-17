/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/30 14:35:14 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/07/30 14:35:16 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_str_rev(char **str)
{
	char	*revstr;
	size_t	len;
	size_t	i;

	len = ft_strlen(*str);
	revstr = ft_strnew(len);
	i = 0;
	while ((*str)[i] != '\0')
	{
		revstr[len - i - 1] = (*str)[i];
		i++;
	}
	free(*str);
	*str = revstr;
}
