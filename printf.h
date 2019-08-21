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
#include <stdlib.h>

typedef struct  s_flags
{
    int mods;
    int field_width;
    int precision;
    int type;
    int conversion;
}               t_flags;

char    *conv_int(va_list arglst, char *(*f)(long long nb));
char    *conv_h_int(va_list arglst, char *(*f)(long long nb));
char    *conv_hh_int(va_list arglst, char *(*f)(long long nb));
char    *conv_l_int(va_list arglst, char *(*f)(long long nb));
char    *conv_ll_int(va_list arglst, char *(*f)(long long nb));
char    *conv_un(va_list arglst, char *(*f)(uint64_t nb));
char    *conv_hu(va_list arglst, char *(*f)(uint64_t nb));
char    *conv_hhu(va_list arglst, char *(*f)(uint64_t nb));
char    *conv_lu(va_list arglst, char *(*f)(uint64_t nb));
char    *conv_llu(va_list arglst, char *(*f)(uint64_t nb));
char    *ft_get_uns(uint64_t nb);
char    *ft_get_oct(uint64_t nb);
char    *ft_get_hex(uint64_t nb);
char    *ft_convbase(uint64_t nb, uint64_t base);
char    *ft_get_int(long long nb);

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