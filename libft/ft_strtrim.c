/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:28:38 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/17 17:55:17 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Removes the characters that appear in set from the beggining and end of s1
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		++s1;
	if (*s1 == '\0')
		return (ft_strdup(""));
	i = ft_strlen((char *)s1) - 1;
	while (i > 0 && ft_strchr(set, s1[i]))
		--i;
	return (ft_substr((char *)s1, 0, i + 1));
}
