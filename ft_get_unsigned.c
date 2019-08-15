/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/30 14:35:14 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/07/30 14:35:16 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_get_unsigned(unsigned long long nb, char **printstr)
{
	size_t i;
    size_t c;

	i = 0;
    c = 0;
	while (nb / ft_power(10, i) > 9)
		i++;
	(*printstr)[ft_strlen(*printstr)] = nb / ft_power(10, i) + '0';
	while (i > 0)
	{
		i--;
        c++;
		(*printstr)[c] = nb / ft_power(10, i) % 10 + '0';
	}
}