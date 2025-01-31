/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:11:59 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/17 09:45:41 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Does the same thing as malloc but initializing all bytes in the memory with 0
num indicates the number of elements to asign and size the size of each one
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	if (count != 0 && size > __SIZE_MAX__ / count)
		return (0);
	res = (void *)malloc(count * size);
	if (!res)
		return (0);
	i = 0;
	while (i < count * size)
		((unsigned char *)res)[i++] = 0;
	return (res);
}
