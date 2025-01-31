/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:18:41 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/17 18:01:34 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Returns the result of concatenating string s2 to string s1 (s1 + s2)
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		++i;
		++j;
	}
	res[i] = '\0';
	return (res);
}
