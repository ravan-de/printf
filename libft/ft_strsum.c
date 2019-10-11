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

int		ft_skipdot(int digit, char **retstr, char *bigstr)
{
	while (digit != 0 && ft_isdigit(bigstr[digit - 1]) == 0)
	{
		(*retstr)[digit] = bigstr[digit - 1];
		digit--;
	}
	return (digit);
}

char	*ft_sum(int digit, char *bigstr, char *smallstr, int dif)
{
	char	*retstr;
	int		sum;
	int		carry;

	carry = 0;
	retstr = ft_memset(ft_strnew(digit + 1), '0', digit + 1);
	while (digit >= 0)
	{
		sum = 0;
		digit = ft_skipdot(digit, &retstr, bigstr);
		if (digit > dif)
			sum = bigstr[digit - 1] + smallstr[digit - dif - 1] - 96 + carry;
		else if (digit != 0)
			sum = bigstr[digit - 1] - '0' + carry;
		else
			sum = carry;
		carry = sum / 10;
		sum %= 10;
		retstr[digit] = sum + '0';
		digit--;
	}
	return (retstr);
}

char	*ft_strsum(char *s1, char *s2)
{
	char	*str;
	char	*ret;
	int		len1;
	int		len2;
	int		i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len2 > len1)
		str = ft_sum(len2, s2, s1, len2 - len1);
	else
		str = ft_sum(len1, s1, s2, len1 - len2);
	while (str[i] == '0')
		i++;
	ret = ft_strsub(str, i, ft_strlen(str) - i);
	free(str);
	return (ret);
}
