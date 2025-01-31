/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:03:30 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/15 14:08:16 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts a lowercase letter to an uppercase letter
int	ft_toupper(int l)
{
	if (l >= 'a' && l <= 'z')
		return (l - 32);
	else
		return (l);
}
