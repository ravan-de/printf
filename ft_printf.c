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

#include <stdlib.h>
#include "libft.h"
#include "printf.h"

int		ft_get_flags(char *str, va_list arglst, t_flags *flags)
{
	size_t	i;

	i = 0;
	flags->mods = 0;
	flags->field_width = 0;
	flags->precision = -1;
	while (ft_getmods(&str[i]) != 0)
	{
		flags->mods |= ft_getmods(&str[i]);
		i++;
	}
	i += ft_get_fieldwidth(&str[i], flags);
	i += ft_get_precision(&str[i], flags);
	i += ft_typeflags(&str[i], flags);
	flags->conversion = ft_convflags(&str[i]);
	if (flags->conversion == -1)
		ft_putstr("flag_error");
	if (flags->conversion == 'f' && flags->precision == -1)
		flags->precision = 6;
	ft_process_flags(arglst, flags);
	return (i + 2);
}

int		ft_printf(char *str, ...)
{
	va_list	arglst;
	t_flags flags;
	int		stri;
	int		len;

	stri = 0;
	flags.len = 0;
	len = 0;
	va_start(arglst, str);
	while (str[stri] != '\0')
	{
		if (str[stri] == '%')
			stri += ft_get_flags(&str[stri + 1], arglst, &flags);
		else
		{
			ft_putchar(str[stri]);
			stri++;
			len++;
		}
	}
	va_end(arglst);
	return (flags.len + len);
}

//L with flags other than f segfaults