/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:49:38 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/19 22:57:59 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Writes the given string in the given file descriptor ending it with a newline
*/
void	ft_putendl_fd(char *s, int fd)
{
	if (s != 0)
		ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
