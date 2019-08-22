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

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "printf.h"

void	ft_capitalize(char *s)
{
	*s = ft_toupper(*s);
}

char	*ft_alt(char *str, t_flags flags)
{
	char *retstr;

	retstr = str;
	if ((flags.conversion == 'x' || flags.conversion == 'X') && str[0] != '0')
		retstr = ft_strjoin("0x", str);
	if (flags.conversion == 'o' && str[0] != '0')
		retstr = ft_strjoin("0", str);
	return (retstr);
}

void	ft_apply_mods(char *str, t_flags flags)
{
	char *finalstr;
	int len;


	if ((flags.mods & 1) == 1)
		finalstr = ft_alt(str, flags);
	else
		finalstr = str;
	if (flags.conversion == 'X')
		ft_striter(finalstr, ft_capitalize);
	if ((flags.mods & 4) == 4 && str[0] != '-')
		finalstr = ft_strjoin("+", str);
	if ((flags.mods & 12) == 8 && str[0] != '-')
		finalstr = ft_strjoin(" ", str);
	//field_width
	len = flags.field_width - ft_strlen(finalstr);
	if ((flags.mods & 2) == 2)
		ft_putstr(finalstr);
	while (len > 0)
	{
		if ((flags.mods & 18) == 16)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len--;
	}
	if ((flags.mods & 2) != 2)
		ft_putstr(finalstr);
}

void	ft_process_flags(va_list arglst, t_flags flags)
{
	char	*(*conv_i[5]) (va_list arglst, char *(*f)(long long nb));
	char	*(*conv_u[5]) (va_list arglst, char *(*f)(uint64_t nb));
	char	*str;

	conv_i[0] = conv_int;
	conv_i[1] = conv_h_int;
	conv_i[2] = conv_hh_int;
	conv_i[3] = conv_l_int;
	conv_i[4] = conv_ll_int;
	conv_u[0] = conv_un;
	conv_u[1] = conv_hu;
	conv_u[2] = conv_hhu;
	conv_u[3] = conv_lu;
	conv_u[4] = conv_llu;
	if (flags.conversion == 'i' || flags.conversion == 'd')
		str = (*conv_i[flags.type])(arglst, ft_get_int);
	if (flags.conversion == 'u')
		str = (*conv_u[flags.type])(arglst, ft_get_uns);
	if (flags.conversion == 'o')
		str = (*conv_u[flags.type])(arglst, ft_get_oct);
	if (flags.conversion == 'x' || flags.conversion == 'X')
		str = (*conv_u[flags.type])(arglst, ft_get_hex);
	if (flags.conversion == 'p')
		str = ft_strjoin("0x7fff", (*conv_u[0])(arglst, ft_get_hex));
	if (flags.conversion == 'b')
		str = (*conv_u[0])(arglst, ft_get_bin);
	if (flags.conversion == 'c')
	{
		str = ft_strnew(1);
		str[0] = (char)va_arg(arglst, int);
	}
	if (flags.conversion == 's')
		str = ft_strdup(va_arg(arglst, char *));
	if (flags.conversion == 'f' && flags.type != 5)
		str = ft_get_double(va_arg(arglst, double), flags.precision);
	if (flags.conversion == 'f' && flags.type == 5)
		str = ft_get_ldouble(va_arg(arglst, long double), flags.precision);
	ft_apply_mods(str, flags);
}

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
		exit;
	ft_process_flags(arglst, flags);
	return (i + 2);
}

void	ft_printf(char *str, ...)
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
}

int		main(void)
{
	int a;
	int i;
	double b;

	a = 10;
	i = 0;
	b = 10.123456789;
	ft_printf("Zaanse mayo %f\n", b);
	printf("Double test: %f\n", b);
	return (1);
}

//DONT FORGET THE PART OF THE MANPAGE BEFORE CONVERSIONS!!!!!!!