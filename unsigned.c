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

void    *conv_unsigned(va_list arglst)
{
    void        *ret;
    unsigned    nb;

    nb = va_arg(arglst, unsigned);
    ret = &nb;
    return (ret);
}

void    *conv_h_unsigned(va_list arglst)
{
    void            *ret;
    unsigned short  nb;

    nb = (unsigned short)va_arg(arglst, unsigned);
    ret = &nb;
    return (ret);
}

void    *conv_hh_unsigned(va_list arglst)
{
    void            *ret;
    unsigned char   nb;

    nb = (unsigned char)va_arg(arglst, unsigned);
    ret = &nb;
    return (ret);
}

void    *conv_l_unsigned(va_list arglst)
{
    void            *ret;
    unsigned long   nb;

    nb = va_arg(arglst, unsigned long);
    ret = &nb;
    return (ret);
}

void    *conv_ll_unsigned(va_list arglst)
{
    void                *ret;
    unsigned long long  nb;

    nb = va_arg(arglst, unsigned long long);
    ret = &nb;
    return (ret);
}