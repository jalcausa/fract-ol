/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:54:32 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/26 22:12:30 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Returns the size of the given list lst
*/
int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		res;

	current = 0;
	if (!lst)
		return (0);
	res = 0;
	current = lst;
	while (current != NULL)
	{
		++res;
		current = current->next;
	}
	return (res);
}
