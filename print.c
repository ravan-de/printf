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

#include "printf.h"

void	ft_get_int(void *input, char **printstr)
{
    ft_int((long long)*(long long *)(input), printstr);
}

void    ft_get_uns(void *input, char **printstr)
{
    ft_convbase(*(unsigned long long *)(input), 10, printstr);
}

void    ft_get_oct(void *input, char **printstr)
{
    ft_convbase(*(unsigned long long *)(input), 8, printstr);
}

void    ft_get_hex(void *input, char **printstr)
{
    ft_convbase(*(unsigned long long *)(input), 16, printstr);
}