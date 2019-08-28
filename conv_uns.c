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

char	*conv_un(va_list arglst, t_get_uns func)
{
	return (func(va_arg(arglst, unsigned)));
}

char	*conv_hu(va_list arglst, t_get_uns func)
{
	unsigned short	nb;

	nb = (unsigned short)va_arg(arglst, unsigned);
	return (func(nb));
}

char	*conv_hhu(va_list arglst, t_get_uns func)
{
	unsigned char	nb;

	nb = (unsigned char)va_arg(arglst, unsigned);
	return (func(nb));
}

char	*conv_lu(va_list arglst, t_get_uns func)
{
	return (func(va_arg(arglst, unsigned long)));
}

char	*conv_llu(va_list arglst, t_get_uns func)
{
	return (func(va_arg(arglst, unsigned long)));
}
