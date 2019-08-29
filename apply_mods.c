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

void	ft_capitalize(char *s)
{
	*s = ft_toupper(*s);
}

char	*ft_alt(char *str, int conv, int len)
{
	char	*retstr;

	if (len < 0)
		len = 0;
	retstr = NULL;
	if ((conv == 'x' || conv == 'X') && str[len] != '0')
		retstr = ft_strjoin("0x", str);
	else if (conv == 'o' && str[len] != '0')
		retstr = ft_strjoin("0", str);
	return (retstr);
}

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

char	*ft_prec(char *str, int precision, int conv, int mods)
{
	char	*finalstr;
	char	*tempstr;
	char	*tempstr2;
	int		len;

	finalstr = NULL;
	len = precision - ft_strlen(str);
	if ((conv == 'd' || conv == 'i' || conv == 'u' || conv == 'o' 
	|| conv == 'x' || conv == 'X') && len > 0)
	{
		tempstr = ft_memset(ft_strnew(len), '0', len);
		tempstr2 = ft_strjoin(tempstr, str);
		free(tempstr);
	}
	else
		tempstr2 = str;
	if ((mods & 1) == 1)
		finalstr = ft_alt(tempstr2, conv, len);
	if (finalstr == NULL)
		return (tempstr2);
	free(tempstr2);
	return (finalstr);
}

void	ft_field_width(char *str, t_flags *flags)
{
	char	*tempstr;
	//char	*tempstr2;
	int		len;

	len = flags->field_width - ft_strlen(str);
	if (len > 0)
	{
		if ((flags->mods & 18) == 16)
			tempstr = ft_memset(ft_strnew(len), '0', len);
		else
			tempstr = ft_memset(ft_strnew(len), ' ', len);
		if ((flags->mods & 2) == 2)
			str = ft_strjoin(str, tempstr);
		else
			str = ft_strjoin(tempstr, str);
		free(tempstr);
		return (str);
	}
}

void	ft_apply_mods(char *str, t_flags *flags)
{
	char	*finalstr;
	char	*tempstr;

	finalstr = ft_prec(str, flags->precision, flags->conversion, flags->mods);
	if (flags->conversion == 'X')
		ft_striter(finalstr, ft_capitalize);
	if ((flags->mods & 4) == 4 && str[0] != '-')
		finalstr = ft_strjoin("+", str);
	if ((flags->mods & 12) == 8 && str[0] != '-')
		finalstr = ft_strjoin(" ", str);
	flags->len = ft_strlen(str);
	ft_putstr(str);
}