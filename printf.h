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

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>

typedef struct  s_flags
{
    int mods;
    int field_width;
    int precision;
    int type;
    int conversion;
}               t_flags;

void    conv_int(va_list arglst, char **str, void (*f)(long long nb, char **str));
void    conv_h_int(va_list arglst, char **str, void (*f)(long long nb, char **str));
void    conv_hh_int(va_list arglst, char **str, void (*f)(long long nb, char **str));
void    conv_l_int(va_list arglst, char **str, void (*f)(long long nb, char **str));
void    conv_ll_int(va_list arglst, char **str, void (*f)(long long nb, char **str));
//void    conv_unsigned(va_list arglst);
//void    conv_h_unsigned(va_list arglst);
//void    conv_hh_unsigned(va_list arglst);
//void    conv_l_unsigned(va_list arglst);
//void    conv_ll_unsigned(va_list arglst);
void    ft_get_int(void *input, char **printstr);
void    ft_get_uns(void *input, char **printstr);
void    ft_get_oct(void *input, char **printstr);
void    ft_get_hex(void *input, char **printstr);
void    ft_int(long long nb, char **printstr);
void    ft_convbase(unsigned long long nb, unsigned long long base, char **printstr);

#endif

/*


nieuwe idee:
    cast input to correct type using funtion array;
    cast input to void * and pass this to function of conversion type;
    this function converts void * to long long or unsigned long long and converts to str(ft_convbase, ft_conv_int.c)
    mods get applied to str;
    print field_width;
    print str;

if string is entered for %d or an int for %s: segfault


make variadic funct ptr and have every print function interpit the type 

ft_putstr(char *str)
ft_putnbr(int)


 */