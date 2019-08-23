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

int		ft_get_precision(char *str, t_flags *flags)
{
	size_t i;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		flags->precision = ft_atoi(&str[i]);
		if (flags->precision < 0)
			flags->precision = 6;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int		ft_get_fieldwidth(char *str, t_flags *flags)
{
	int i;

	i = 0;
	if (str[i] > '0' && str[i] <= '9')
		flags->field_width = ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
    return (i);
}

int		ft_getmods(char *str)
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

int		ft_typeflags(char *str, t_flags *flags)
{
	int h;
	int l;

	h = 0;
	l = 0;

	if (*str == 'L')
	{
		flags->type = 5;
		return (1);
	}
	while (str[h + l] == 'h' && h < 2)
		h++;
	while (str[h + l] == 'l' && l < 2)
		l++;
	if (h >= 0 && l == 0)
		flags->type = h;
	else if (l > 0 && h == 0)
		flags->type = 2 + l;
	else
		return (0);
	return (h + l);
}

int		ft_convflags(char *str)
{
	if (*str == 'd' || *str == 'i' || *str == 'c' || *str == 's' || *str == 'p'
	|| *str == 'u' || *str == 'o' || *str == 'x' || *str == 'X' || *str == 'b'
	|| *str == 'f')
		return (*str);
	return (-1);
}