/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:17:35 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/16 00:08:02 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		++i;
	}
	return (i + 1);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (ft_count_digits_unsigned(n));
}

int	ft_puthex(unsigned long int n, char c)
{
	char	*alphabet;
	int		res;

	res = 1;
	if (c == 'x')
		alphabet = "0123456789abcdef";
	else if (c == 'X')
		alphabet = "0123456789ABCDEF";
	if (n > 15)
	{
		res = res + ft_puthex(n / 16, c);
		write(1, &alphabet[n % 16], 1);
	}
	else
	{
		write(1, &alphabet[n], 1);
	}
	return (res);
}
