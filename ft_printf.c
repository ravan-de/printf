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

int		ft_get_flags(char *str, va_list arglst)
{
	size_t	i;
	t_flags	flags;

	i = 0;
	flags.mods = 0;
	flags.field_width = 0;
	flags.precision = 6;
	while (ft_getmods(&str[i]) != 0)
	{
		flags.mods |= ft_getmods(&str[i]);
		i++;
	}
	i += ft_get_fieldwidth(&str[i], &flags);
	i += ft_get_precision(&str[i], &flags);
	i += ft_typeflags(&str[i], &flags);
	flags.conversion = ft_convflags(&str[i]);
	if (flags.conversion == -1)
		ft_putstr("flag_error");
	ft_process_flags(arglst, flags);
	return (i + 2);
}

int		ft_printf(char *str, ...)
{
	va_list	arglst;
	int		stri;

	stri = 0;
	va_start(arglst, str);
	while (str[stri] != '\0')
	{
		if (str[stri] == '%' && str[stri + 1] != '%')
			stri += ft_get_flags(&str[stri + 1], arglst);
		else
		{
			if (str[stri] == '%' && str[stri + 1] == '%')
				str++;
			ft_putchar(str[stri]);
			stri++;
		}
	}
	va_end(arglst);
	return (0);
}

//L with flags other than f segfaults