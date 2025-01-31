/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:47:44 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/16 19:46:30 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates enough memory for string s1, copies it and return a pointer to it
*/
char	*ft_strdup(const char *s1)
{
	size_t		n;
	size_t		i;
	char		*res;

	n = ft_strlen(s1);
	res = (char *)malloc((n + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < n + 1)
	{
		res[i] = (char)s1[i];
		++i;
	}
	return (res);
}
