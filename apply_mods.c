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

const char	*ft_get_extra(char *str, t_flags *flags)
{
	if ((flags->mods & 1) == 1)
	{
		if ((flags->conversion == 'x' || flags->conversion == 'X') && str[0] != '0')
			return ("0x");
		if (flags->conversion == 'o' && str[0] != '0')
			return ("0");
	}
	if ((flags->mods & 4) == 4 && str[0] != '-')
		return ("+");
	if ((flags->mods & 12) == 8 && str[0] != '-')
		return (" ");		
	return (NULL);
}

char	*ft_fill_str(char *str, const char *extrastr, t_flags *flags, int preclen, int width)
{
	char	*finalstr;
	int		strlen;
	int		extralen;

	extralen = 0;
	strlen = ft_strlen(str);
	if (extrastr != NULL)
		extralen = ft_strlen(extralen);
	finalstr = ft_strnew(width + preclen + strlen + extralen);
	if ((flags->mods & 18) == 16)
	{
		if (extrastr != NULL)
			ft_strcpy(&finalstr[ft_strlen(finalstr)], extrastr);
		ft_memset(&finalstr[ft_strlen(finalstr)], '0', width + preclen);
	}
	if ((flags->mods & 2) != 2)
		ft_memset(&finalstr[ft_strlen(finalstr)], ' ', width);
	if (extrastr != NULL && (flags->mods & 18) != 16)
		ft_strcpy(&finalstr[ft_strlen(finalstr)], extrastr);
	if (preclen > 0 && (flags->mods & 18) != 16)
		ft_memset(&finalstr[ft_strlen(finalstr)], '0', preclen);
	ft_strcpy(&finalstr[ft_strlen(finalstr)], str);
	if ((flags->mods & 2) == 2)
		ft_memset(&finalstr[ft_strlen(finalstr)], ' ', width);
	return (finalstr);
}

void	ft_apply_mods(char *str, t_flags *flags)
{
	char		*finalstr;
	const char	*extrastr;
	int			strlen;
	int			width;
	int			preclen;

	width = 0;
	preclen = 0;
	strlen = ft_strlen(str);
	extrastr = ft_get_extra(str, flags);
	if (extrastr != NULL)
		flags->field_width -= ft_strlen(extrastr);
	if ((flags->conversion == 'd' || flags->conversion == 'i' ||
	flags->conversion == 'u' || flags->conversion == 'o'
	|| flags->conversion == 'x' || flags->conversion == 'X'))
	{
		if (flags->precision > strlen)
			preclen = flags->precision - strlen;
	}
	if (flags->field_width - preclen > strlen)
		width = flags->field_width - strlen - preclen;
	finalstr = ft_fill_str(str, extrastr, flags, preclen, width);
	if (flags->conversion == 'X')
		ft_striter(finalstr, ft_capitalize);
	flags->len = ft_strlen(finalstr);
	ft_putstr(finalstr);
}

//nieuw plan: maak string van goeie lengte en kopier alles hier naartoe!