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
	char	*finalstr;
	int		len;


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