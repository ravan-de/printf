/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 21:50:09 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/08 17:46:28 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	if (s[0] != c)
		words++;
	while (s[i + 1] != '\0' && s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			words++;
		i++;
	}
	return (words);
}

static size_t	ft_len(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char		**ft_nullcheck(char **words, size_t wordslen)
{
	size_t	word;
	int		null;

	word = 0;
	null = 0;
	while (word < wordslen)
	{
		if (words[word] == NULL)
			null = 1;
		word++;
	}
	word = 0;
	while (word < wordslen && null == 1)
	{
		if (words[word] != NULL)
			ft_strdel(&words[word]);
		word++;
	}
	if (null == 1)
	{
		free(words);
		words = NULL;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	chr;
	size_t	word;
	char	**words;

	chr = 0;
	word = 0;
	words = (char **)malloc(sizeof(char *) * ft_words(s, c) + 1);
	if (words == NULL || ft_strlen(s) == 0)
		return (NULL);
	if (s[0] != c)
	{
		words[0] = ft_strsub(s, 0, ft_len(s, c));
		word++;
	}
	while (word < ft_words(s, c))
	{
		if (s[chr] == c && s[chr + 1] != c)
		{
			words[word] = ft_strsub(s, chr + 1, ft_len(&s[chr + 1], c));
			word++;
		}
		chr++;
	}
	words[word] = NULL;
	return (ft_nullcheck(words, ft_words(s, c)));
}
