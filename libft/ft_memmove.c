/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:13:48 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/16 19:29:01 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Copies len bytes of src into dst managing overlapping
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	if (dst < src)
	{
		while (i < n)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			++i;
		}
	}
	else
	{
		while (n > 0)
		{
			*(char *)(dst + n - 1) = *(char *)(src + n - 1);
			--n;
		}
	}
	return (dst);
}
