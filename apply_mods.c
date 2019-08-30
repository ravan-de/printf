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

char	*ft_get_extra(char *str, t_flags *flags)
{
	if ((flags->mods & 1) == 1)
	{
		if ((flags->conv == 'x' || flags->conv == 'X') && str[0] != '0')
			return ("0x");
		if (flags->conv == 'o' && str[0] != '0')
			return ("0");
	}
	if ((flags->mods & 4) == 4 && str[0] != '-')
		return ("+");
	if ((flags->mods & 12) == 8 && str[0] != '-')
		return (" ");
	return (NULL);
}

char	*ft_fill(char *str, char *extrastr, t_flags *flags)
{
	char	*ret;
	int		strlen;
	int		extralen;

	extralen = 0;
	strlen = ft_strlen(str);
	if (extrastr != NULL)
		extralen = ft_strlen(extrastr);
	ret = ft_strnew(flags->width + flags->prec + strlen + extralen);
	if ((flags->mods & 18) == 16)
	{
		if (extrastr != NULL)
			ft_strcpy(&ret[ft_strlen(ret)], extrastr);
		ft_memset(&ret[ft_strlen(ret)], '0', flags->width + flags->prec);
	}
	if ((flags->mods & 18) == 0)
		ft_memset(&ret[ft_strlen(ret)], ' ', flags->width);
	if (extrastr != NULL && (flags->mods & 18) != 16)
		ft_strcpy(&ret[ft_strlen(ret)], extrastr);
	if (flags->prec > 0 && (flags->mods & 18) != 16)
		ft_memset(&ret[ft_strlen(ret)], '0', flags->prec);
	ft_strcpy(&ret[ft_strlen(ret)], str);
	if ((flags->mods & 2) == 2)
		ft_memset(&ret[ft_strlen(ret)], ' ', flags->width);
	return (ret);
}

void	ft_apply_mods(char *str, t_flags *flags)
{
	char	*finalstr;
	char	*extrastr;
	int		strlen;

	strlen = ft_strlen(str);
	extrastr = ft_get_extra(str, flags);
	if (extrastr != NULL)
		flags->width -= ft_strlen(extrastr);
	if (flags->width < 0)
		flags->width = 0;
	if ((flags->conv == 'd' || flags->conv == 'i' ||
	flags->conv == 'u' || flags->conv == 'o'
	|| flags->conv == 'x' || flags->conv == 'X'))
	{
		if (flags->prec > strlen)
			flags->prec = flags->prec - strlen;
	}
	if (flags->width - flags->prec > strlen)
		flags->width -= strlen + flags->prec;
	finalstr = ft_fill(str, extrastr, flags);
	if (flags->conv == 'X')
		ft_striter(finalstr, ft_capitalize);
	flags->len = ft_strlen(finalstr);
	ft_putstr(finalstr);
}
