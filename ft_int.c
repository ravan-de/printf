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
#include "limits.h"
#include <stdlib.h>

void	ft_int(long long nb, char **str)
{
	int i;

	i = 0;
	if (nb == -9223372036854775808)
	{
		strcpy(*str, "-922337203685477580");
		nb = 8;
	}
	if (nb < 0)
	{
		(*str)[0] = '-';
		nb *= -1;
	}
	while (nb / ft_power(10, i) > 9)
		i++;
	(*str)[ft_strlen(*str)] = nb / ft_power(10, i) + '0';
	while (i > 0)
	{
		i--;
		(*str)[ft_strlen(*str)] = nb / ft_power(10, i) % 10 + '0';
	}
}
