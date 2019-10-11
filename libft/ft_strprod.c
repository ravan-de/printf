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

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_multiply(char *str, int nb, int iter)
{
	char	*retstr;
	int		len;
	int		prod;
	int		carry;

	len = ft_strlen(str);
	carry = 0;
	retstr = ft_memset(ft_strnew(len + iter + 1), '0', len + iter + 1);
	while (len >= 0)
	{
		prod = 0;
		if (len != 0)
			prod = (str[len - 1] - 48) * nb + carry;
		else
			prod = carry;
		carry = 0;
		if (prod >= 10)
		{
			carry = prod / 10;
			prod %= 10;
		}
		retstr[len] = prod + 48;
		len--;
	}
	return (retstr);
}

char	*ft_prod(int digit, char *bigstr, char *smallstr)
{
	char	*retstr;
	char	*temp;
	char	*prod;
	int		iter;
	int		i;

	iter = 0;
	retstr = ft_memset(ft_strnew(digit + 1), '0', digit + 1);
	while (digit > 0)
	{
		i = 0;
		prod = ft_multiply(smallstr, bigstr[digit - 1] - 48, iter);
		temp = ft_strdup(retstr);
		free(retstr);
		retstr = ft_strsum(temp, prod);
		free(temp);
		free(prod);
		digit--;
		iter++;
	}
	return (retstr);
}

char	*ft_strprod(char *s1, char *s2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len2 > len1)
		return (ft_prod(len2, s2, s1));
	return (ft_prod(len1, s1, s2));
}
