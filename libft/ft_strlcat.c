/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:36:13 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/16 20:18:23 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Concatenates string src to string dst, given a max size of the resulting
string of dstsize and NULL terminating it. It returns the length of the 
string it tried to create, srclen + destlen
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	i;
	size_t	j;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (size <= destlen)
		return (size + srclen);
	i = destlen;
	j = 0;
	while (src[j] && i + j < (size - 1))
	{
		dest[i + j] = src [j];
		++j;
	}
	dest[i + j] = '\0';
	return (destlen + srclen);
}
