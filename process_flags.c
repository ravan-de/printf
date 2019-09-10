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

#include "printf.h"
#include "libft.h"

void	ft_init_int(char *(*conv_i[5]) (va_list arglst, t_get_int func))
{
	conv_i[0] = conv_int;
	conv_i[1] = conv_h_int;
	conv_i[2] = conv_hh_int;
	conv_i[3] = conv_l_int;
	conv_i[4] = conv_ll_int;
}

void	ft_init_uns(char *(*conv_u[5]) (va_list arglst, t_get_uns func))
{
	conv_u[0] = conv_un;
	conv_u[1] = conv_hu;
	conv_u[2] = conv_hhu;
	conv_u[3] = conv_lu;
	conv_u[4] = conv_llu;
}

void    ft_process_extra(va_list arglst, t_flags *flags, char **str)
{
	if (flags->conv == 'c')
		*str = ft_memset(ft_strnew(1), (char)va_arg(arglst, int), 1);
	if (flags->conv == '%')
		*str = ft_memset(ft_strnew(1), '%', 1);
	if (flags->conv == 's')
		*str = ft_strdup(va_arg(arglst, char *));
	if (flags->conv == 'f' && flags->type != 5)
		*str = ft_get_double(va_arg(arglst, double), flags->prec);
	if (flags->conv == 'f' && flags->type == 5)
		*str = ft_get_ldouble(va_arg(arglst, long double), flags->prec);
}

void	ft_process_flags(va_list arglst, t_flags *flags)
{
	char	*(*conv_u[5]) (va_list arglst, t_get_uns func);
	char	*(*conv_i[5]) (va_list arglst, t_get_int func);
	char	*str;

	ft_init_uns(conv_u);
	ft_init_int(conv_i);
	if (flags->conv == 'i' || flags->conv == 'd')
		str = (*conv_i[flags->type])(arglst, ft_get_int);
	if (flags->conv == 'u')
		str = (*conv_u[flags->type])(arglst, ft_get_uns);
	if (flags->conv == 'o')
		str = (*conv_u[flags->type])(arglst, ft_get_oct);
	if (flags->conv == 'x' || flags->conv == 'X')
		str = (*conv_u[flags->type])(arglst, ft_get_hex);
	if (flags->conv == 'p')
		str = (*conv_u[4])(arglst, ft_get_hex);
	if (flags->conv == 'b')
		str = (*conv_u[flags->type])(arglst, ft_get_bin);
    ft_process_extra(arglst, flags, &str);
	ft_apply_mods(str, flags);
}