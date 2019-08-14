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

void ft_get_int(long long nb, char **printstr)
{
    int c;
    int i;

    i = 0;
    c = 0;
    if (nb < 0)
    {
        (*printstr)[c] = '-';
        c++;
        nb *= -1;
    }
    while (nb / ft_recursive_power(10, i) > 9)
        i++;
    (*printstr)[c] = nb / ft_recursive_power(10, i) + '0';
    while (i > 0)
    {
        i--;
        c++;
        (*printstr)[c] =  nb / ft_recursive_power(10, i) % 10 + '0';
    }
}