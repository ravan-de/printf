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

# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int mods;
	int field_width;
	int precision;
	int type;
	int conversion;
}				t_flags;

char			*conv_int(va_list arglst, char *(*f)(long long nb));
char			*conv_h_int(va_list arglst, char *(*f)(long long nb));
char			*conv_hh_int(va_list arglst, char *(*f)(long long nb));
char			*conv_l_int(va_list arglst, char *(*f)(long long nb));
char			*conv_ll_int(va_list arglst, char *(*f)(long long nb));
char			*conv_un(va_list arglst, char *(*f)(uint64_t nb));
char			*conv_hu(va_list arglst, char *(*f)(uint64_t nb));
char			*conv_hhu(va_list arglst, char *(*f)(uint64_t nb));
char			*conv_lu(va_list arglst, char *(*f)(uint64_t nb));
char			*conv_llu(va_list arglst, char *(*f)(uint64_t nb));
char			*ft_get_uns(uint64_t nb);
char			*ft_get_oct(uint64_t nb);
char			*ft_get_hex(uint64_t nb);
char			*ft_get_bin(uint64_t nb);
char			*ft_convbase(uint64_t nb, uint64_t base);
char			*ft_get_int(long long nb);
char			*ft_get_double(double nb, int precision);
char    		*ft_get_ldouble(long double nb, int precision);

int				ft_getmods(char *str);
int				ft_get_fieldwidth(char *str, t_flags *flags);
int				ft_get_precision(char *str, t_flags *flags);
int				ft_typeflags(char *str, t_flags *flags);
int				ft_convflags(char *str);

#endif
