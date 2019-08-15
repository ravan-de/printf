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

void    ft_process_flags(va_list arglst, int mods, int field_width, int precision, int type)
{
	(void)precision;
	(void)mods;
	(void)field_width;
	char *printstr;

	printstr = ft_strnew(1000);
	void    (*funcs[20]) (va_list arglst, char **printstr);

	funcs[0] = get_int;
	funcs[1] = get_h_int;
	funcs[2] = get_hh_int;
	funcs[3] = get_l_int;
	funcs[4] = get_ll_int;
	funcs[5] = get_unsigned;
	funcs[6] = get_h_unsigned;
	funcs[7] = get_hh_unsigned;
	funcs[8] = get_l_unsigned;
	funcs[9] = get_ll_unsigned;
	funcs[10] = get_octal;
	funcs[11] = get_h_octal;
	funcs[12] = get_hh_octal;
	funcs[13] =  get_l_octal;
	funcs[14] = get_ll_octal;
	funcs[15] = get_hex;
	funcs[16] = get_h_hex;
	funcs[17] = get_hh_hex;
	funcs[18] = get_l_hex;
	funcs[19] = get_ll_hex;
	(*funcs[type]) (arglst, &printstr);
	ft_putstr(printstr);
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
		return (5);
	if (*str == 'o' || *str == 'O')
		return (10);
	if (*str == 'x')
		return (15);
	if (*str == 'x')
		return (6);
	if (*str == 'X')
		return (7);
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
		return (ft_convflags(&str[h]) + h);
	if (l >= 0 && h == 0)
		return (ft_convflags(&str[l]) + 2 + l);
	return (-1);
}

int ft_get_modflags(char *str, va_list arglst)
{
	size_t  i;
	int     mods;
	int     field_width;
	int     precision;

	i = 0;
	mods = 0;
	field_width = 0;
	(void)arglst;
	while (ft_getmods(&str[i]) != 0)
	{
		mods |= ft_getmods(&str[i]);
		i++;
	}
	if (str[i] > '0' && str[i] <= '9')
		field_width = ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		precision = ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	ft_process_flags(arglst, mods, field_width, precision, ft_typeflags(&str[i]));
	while (str[i] == 'l' || str[i] == 'h')
		i++;
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
	ft_printf("Zaanse mayo %x   %o\n", 242, 242);
	printf("Zaanse mayo %x   %o\n", 242, 242);
	return (1);
}
