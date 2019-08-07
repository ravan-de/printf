/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 21:29:53 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/26 13:06:47 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*meme;
	size_t	i;

	i = 0;
	meme = malloc(size);
	while (i < size && meme != NULL)
	{
		meme[i] = 0;
		i++;
	}
	return ((void *)meme);
}
