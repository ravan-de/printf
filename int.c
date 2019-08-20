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
#include "libft.h"

void    conv_int(va_list arglst, char **str, void (*f)(long long nb, char **str))
{
    (*f)((long long)va_arg(arglst, int), str);
}

void    conv_h_int(va_list arglst, char **str, void (*f)(long long nb, char **str))
{
    short   nb;

    nb = (short)va_arg(arglst, int);
    (*f)((long long)nb, str);
}

void    conv_hh_int(va_list arglst, char **str, void (*f)(long long nb, char **str))
{
    signed char nb;

    nb = (signed char)va_arg(arglst, int);
    (*f)((long long)nb, str);
}

void    conv_l_int(va_list arglst, char **str, void (*f)(long long nb, char **str))
{
    (*f)((long long)va_arg(arglst, long), str);
}

void    conv_ll_int(va_list arglst, char **str, void (*f)(long long nb, char **str))
{
    (*f)(va_arg(arglst, long long), str);
}