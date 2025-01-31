/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:17:25 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/18 18:56:34 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Divides the given string s in words using as a delimiter the char c and
returning an array of strings (words) using malloc
*/
static int	ft_count_words(char const *s, char c)
{
	int	n_words;

	n_words = 0;
	while (*s)
	{
		if (*s != c)
		{
			++n_words;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (n_words);
}

static char	*ft_malloc_str(const char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	str = (char *) malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		++i;
	}
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		n_words;
	int		i;

	n_words = ft_count_words(s, c);
	strs = (char **)malloc((n_words + 1) * sizeof(char *));
	if (!strs)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
		{
			strs[i] = ft_malloc_str(s, c);
			if (!strs[i])
				return (ft_free(strs, i));
			++i;
			while (*s && *s != c)
				++s;
		}
	}
	strs[i] = 0;
	return (strs);
}
