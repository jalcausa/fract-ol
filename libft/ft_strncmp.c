/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:04:22 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/16 20:25:31 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compares the given strings in lexicographical order (by their ASCII value)
with a maximun of n chars in both strings
Retruns 0 if they are equal, a positive value is s1>s2 and a negative if s1<s2
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		else
			++i;
	}
	if (i < n)
		return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
	else
		return (0);
}
