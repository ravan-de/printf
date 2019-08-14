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
void    get_int(va_list arglst, char **printstr);
void    get_h_int(va_list arglst, char **printstr);
void    get_hh_int(va_list arglst, char **printstr);
void    get_l_int(va_list arglst, char **printstr);
void    get_ll_int(va_list arglst, char **printstr);

#endif

/*

if string is entered for %d or an int for %s: segfault


make variadic funct ptr and have every print function interpit the type 

ft_putstr(char *str)
ft_putnbr(int)


 */