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

char	*conv_int(va_list arglst, t_get_int func)
{
	return (func(va_arg(arglst, int)));
}

char	*conv_h_int(va_list arglst, t_get_int func)
{
	short	nb;

	nb = (short)va_arg(arglst, int);
	return (func(nb));
}

char	*conv_hh_int(va_list arglst, t_get_int func)
{
	signed char	nb;

	nb = (signed char)va_arg(arglst, int);
	return (func(nb));
}

char	*conv_l_int(va_list arglst, t_get_int func)
{
	return (func(va_arg(arglst, long)));
}

char	*conv_ll_int(va_list arglst, t_get_int func)
{
	return (func(va_arg(arglst, long long)));
}
