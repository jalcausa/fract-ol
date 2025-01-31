/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:07:10 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/15 14:08:20 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts an uppercase letter to a lowercase letter
int	ft_tolower(int l)
{
	if (l >= 'A' && l <= 'Z')
		return (l + 32);
	else
		return (l);
}
