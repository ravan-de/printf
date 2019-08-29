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

void	ft_putstr_prec(char *str, int precision)
{
	int i;

	i = 0;
	while (i < precision)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_capitalize(char *s)
{
	*s = ft_toupper(*s);
}

void	ft_alt(char **str, int conv, int len)
{
	if ((conv == 'x' || conv == 'X') && (*str)[len] != '0')
		*str = ft_strjoin("0x", *str);
	else if (conv == 'o' && (*str)[len] != '0')
		*str = ft_strjoin("0", *str);
}

int		ft_field_width(char **str, int field_width, int mods)
{
	char	*tempstr;
	int		len;

	len = field_width - ft_strlen(*str);
	if (len > 0)
	{
		if ((mods & 18) == 16)
			tempstr = ft_memset(ft_strnew(len), '0', len);
		else
			tempstr = ft_memset(ft_strnew(len), ' ', len);
		if ((mods & 2) == 2)
			*str = ft_strjoin(*str, tempstr);
		else
			*str = ft_strjoin(tempstr, *str);
		free(tempstr);
	}
	else
		len = 0;
	return (len);
}

void	ft_prec(char **str, t_flags *flags)
{
	char	*finalstr;
	char	*tempstr;
	int		len;

	finalstr = NULL;
	len = flags->precision - ft_strlen(*str);
	if ((flags->conversion == 'd' || flags->conversion == 'i' ||
	flags->conversion == 'u' || flags->conversion == 'o'
	|| flags->conversion == 'x' || flags->conversion == 'X') && len > 0)
	{
		tempstr = ft_memset(ft_strnew(len), '0', len);
		*str = ft_strjoin(tempstr, *str);
		free(tempstr);
	}
	if (len < 0)
		len = 0;
	if ((flags->mods & 18) == 16)
		len += ft_field_width(str, flags->field_width, flags->mods);
	if ((flags->mods & 1) == 1)
		ft_alt(str, flags->conversion, len);
	if ((flags->mods & 18) == 18)
		ft_field_width(str, flags->field_width, flags->mods);
}

void	ft_apply_mods(char *str, t_flags *flags)
{
	char	*finalstr;
	char	*tempstr;

	if ((flags->conversion == 'x' || flags->conversion == 'X') && (*str)[len] != '0')
		f
	ft_prec(&str, flags);
	if (flags->conversion == 'X')
		ft_striter(finalstr, ft_capitalize);
	if ((flags->mods & 4) == 4 && str[0] != '-')
		finalstr = ft_strjoin("+", str);
	if ((flags->mods & 12) == 8 && str[0] != '-')
		finalstr = ft_strjoin(" ", str);
	flags->len = ft_strlen(str);
	ft_putstr(str);
}

//nieuw plan: maak string van goeie lengte en kopier alles hier naartoe!