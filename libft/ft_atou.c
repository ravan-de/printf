/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 20:28:34 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/01 19:48:23 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

uint64_t	ft_atou(const char *str)
{
	size_t		i;
	uint64_t	tot;

	tot = 0;
	i = 0;
	while (ft_isspace(str[i]) != 0)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) != 0)
	{
		tot = tot * 10 + str[i] - '0';
		i++;
	}
	return (tot);
}
