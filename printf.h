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

void    ft_get_int(long long nb, char **printstr);
void    ft_get_unsigned(unsigned long long nb, char **printstr);
void    ft_convbase(unsigned long long nb, unsigned long long base, char **printstr);
void    get_int(va_list arglst, char **printstr);
void    get_h_int(va_list arglst, char **printstr);
void    get_hh_int(va_list arglst, char **printstr);
void    get_l_int(va_list arglst, char **printstr);
void    get_ll_int(va_list arglst, char **printstr);
void    get_unsigned(va_list arglst, char **printstr);
void    get_h_unsigned(va_list arglst, char **printstr);
void    get_hh_unsigned(va_list arglst, char **printstr);
void    get_l_unsigned(va_list arglst, char **printstr);
void    get_ll_unsigned(va_list arglst, char **printstr);
void    get_octal(va_list arglst, char **printstr);
void    get_h_octal(va_list arglst, char **printstr);
void    get_hh_octal(va_list arglst, char **printstr);
void    get_l_octal(va_list arglst, char **printstr);
void    get_ll_octal(va_list arglst, char **printstr);
void    get_hex(va_list arglst, char **printstr);
void    get_h_hex(va_list arglst, char **printstr);
void    get_hh_hex(va_list arglst, char **printstr);
void    get_l_hex(va_list arglst, char **printstr);
void    get_ll_hex(va_list arglst, char **printstr);

#endif

/*


nieuwe idee:
    cast input to correct type using funtion array;
    cast input to void * and pass this to function of conversion type;
    this function converts void * to long long or unsigned long long and converts to str(ft_convbase, ft_get_int.c)
    mods get applied to str;
    print field_width;
    print str;

if string is entered for %d or an int for %s: segfault


make variadic funct ptr and have every print function interpit the type 

ft_putstr(char *str)
ft_putnbr(int)


 */