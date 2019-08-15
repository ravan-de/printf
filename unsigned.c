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

void    get_unsigned(va_list arglst, char **printstr)
{
    unsigned nb;

    nb = va_arg(arglst, unsigned);
    ft_get_unsigned((unsigned long long)nb, printstr);
}

void    get_h_unsigned(va_list arglst, char **printstr)
{
    unsigned short nb;

    nb = (unsigned short)va_arg(arglst, int);
    ft_get_unsigned((unsigned long long)nb, printstr);
}

void    get_hh_unsigned(va_list arglst, char **printstr)
{
    unsigned char nb;

    nb = (unsigned char)va_arg(arglst, int);
    ft_get_unsigned((unsigned long long)nb, printstr);
}

void    get_l_unsigned(va_list arglst, char **printstr)
{
    unsigned long nb;

    nb = va_arg(arglst, unsigned long);
    ft_get_unsigned((unsigned long long)nb, printstr);
}

void    get_ll_unsigned(va_list arglst, char **printstr)
{
    ft_get_unsigned(va_arg(arglst, unsigned long long), printstr);
}