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

void    get_hex(va_list arglst, char **printstr)
{
    unsigned nb;

    nb = va_arg(arglst, unsigned);
    ft_convbase((unsigned long long)nb, 16, printstr);
}

void    get_h_hex(va_list arglst, char **printstr)
{
    unsigned short nb;

    nb = (unsigned short)va_arg(arglst, int);
    ft_convbase((unsigned long long)nb, 16, printstr);
}

void    get_hh_hex(va_list arglst, char **printstr)
{
    unsigned char nb;

    nb = (unsigned char)va_arg(arglst, int);
    ft_convbase((unsigned long long)nb, 16, printstr);
}

void    get_l_hex(va_list arglst, char **printstr)
{
    unsigned long nb;

    nb = va_arg(arglst, unsigned long);
    ft_convbase((unsigned long long)nb, 16, printstr);
}

void    get_ll_hex(va_list arglst, char **printstr)
{
    ft_convbase(va_arg(arglst, unsigned long long), 16, printstr);
}