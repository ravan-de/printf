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

/*	ft_print_flags(t_flags flags)
{
	void	(*print[4]) (void *input, char **printstr);

	print[0] = ft_get_int;
	print[1] = ft_get_uns;
	print[2] = ft_get_oct;
	print[3] = ft_get_hex;
	(*print[flags.conversion]) (input, &printstr);
	ft_putstr(printstr);
}*/

void    ft_process_flags(va_list arglst, t_flags flags)
{
	void	(*convs[5]) (va_list arglst, char **str, void (*f)(long long nb, char **str));
	char	*str;
	
	str = ft_strnew(1000);
	convs[0] = conv_int;
	convs[1] = conv_h_int;
	convs[2] = conv_hh_int;
	convs[3] = conv_l_int;
	convs[4] = conv_ll_int;
	//convs[5] = conv_unsigned;
	//convs[6] = conv_h_unsigned;
	//convs[7] = conv_hh_unsigned;
	//convs[8] = conv_l_unsigned;
	//convs[9] = conv_ll_unsigned;
	if (flags.conversion == 0)
		(*convs[flags.type]) (arglst, &str, ft_int);
	ft_putstr(str);
}

/*void ft_fieldwidth(char *str)
{
	size_t len;

	len = 0;
	len = field_width - ft_strlen(str);
	while (len > 0)
	{
		if (ft_strchr(flags, '0') != NULL)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len--;
	}
}*/

int ft_getmods(char *str)
{
	if (*str == '#')
		return (1);
	if (*str == '-')
		return (2);
	if (*str == '+')
		return (4);
	if (*str == ' ')
		return (8);
	if (*str == '0')
		return (16);
	return (0);
}

int ft_convflags(char *str)
{
	if (*str == 'd' || *str == 'i')
		return (0);
	if (*str == 'u')
		return (1);
	if (*str == 'o')
		return (2);
	if (*str == 'x')
		return (3);
	if (*str == 'X')
		return (4);
	return (-5);
}

int ft_typeflags(char *str)
{
	int h;
	int l;

	h = 0;
	l = 0;
	while (str[h + l] == 'h')
		h++;
	while (str[h + l] == 'l')
		l++;
	if (h >= 0 && l == 0)
		return (h);
	if (l > 0 && h == 0)
		return (2 + l);
	return (-1);
}

int ft_get_modflags(char *str, va_list arglst)
{
	size_t  i;
	t_flags flags;

	i = 0;
	flags.mods = 0;
	flags.field_width = 0;
	while (ft_getmods(&str[i]) != 0)
	{
		flags.mods |= ft_getmods(&str[i]);
		i++;
	}
	if (str[i] > '0' && str[i] <= '9')
		flags.field_width = ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		flags.precision = ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	flags.type = ft_typeflags(&str[i]);
	while (str[i] == 'l' || str[i] == 'h')
		i++;
	flags.conversion = ft_convflags(&str[i]);
	ft_process_flags(arglst, flags);
	return (i + 2);
}

void ft_printf(char *str, ...)
{
	va_list arglst;
	int     stri;

	stri = 0;
	va_start(arglst, str);
	while (str[stri] != '\0')
	{
		if (str[stri] == '%')
			stri += ft_get_modflags(&str[stri + 1], arglst);
		else
		{
			ft_putchar(str[stri]);
			stri++;
		}
	}
	va_end(arglst);
}

int main(void)
{
	ft_printf("Zaanse mayo %hd\n", 2147483647);
	printf("Zaanse mayo %hd\n", 2147483647);
	return (1);
}
