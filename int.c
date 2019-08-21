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

char    *conv_int(va_list arglst, char *(*f)(long long nb))
{
    return ((*f)((long long)va_arg(arglst, int)));
}

char    *conv_h_int(va_list arglst, char *(*f)(long long nb))
{
    short   nb;

    nb = (short)va_arg(arglst, int);
    return((*f)((long long)nb));
}

char    *conv_hh_int(va_list arglst, char *(*f)(long long nb))
{
    signed char nb;

    nb = (signed char)va_arg(arglst, int);
    return((*f)((long long)nb));
}

char    *conv_l_int(va_list arglst, char *(*f)(long long nb))
{
    return((*f)((long long)va_arg(arglst, long)));
}

char    *conv_ll_int(va_list arglst, char *(*f)(long long nb))
{
    return ((*f)(va_arg(arglst, long long)));
}