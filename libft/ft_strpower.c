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

#include "libft.h"
#include <stdlib.h>

char	*ft_strpower(char *nbstr, int power)
{
	char	*retstr;
	char	*temp;

	if (power == 0)
		return (ft_memset(ft_strnew(1), '1', 1));
	if (power == 1)
		return (ft_strdup(nbstr));
	retstr = ft_strprod(nbstr, nbstr);
	power--;
	while (power > 1)
	{
		temp = ft_strdup(retstr);
		free(retstr);
		retstr = ft_strprod(temp, nbstr);
		free(temp);
		power--;
	}
	return (retstr);
}
