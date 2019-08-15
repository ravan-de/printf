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

#include "printf.h"

void    get_int(va_list arglst, char **printstr)
{
    int nb;

    nb = va_arg(arglst, int);
    ft_get_int((long long)nb, printstr);
}

void    get_h_int(va_list arglst, char **printstr)
{
    short nb;

    nb = (short)va_arg(arglst, int);
    ft_get_int((long long)nb, printstr);
}

void    get_hh_int(va_list arglst, char **printstr)
{
    signed char nb;

    nb = (signed char)va_arg(arglst, int);
    ft_get_int((long long)nb, printstr);
}

void    get_l_int(va_list arglst, char **printstr)
{
    long nb;

    nb = va_arg(arglst, long);
    ft_get_int((long long)nb, printstr);
}

void    get_ll_int(va_list arglst, char **printstr)
{
    ft_get_int(va_arg(arglst, long long), printstr);
}