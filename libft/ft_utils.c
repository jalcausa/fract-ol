/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:02:47 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/16 00:08:09 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
	return (i);
}

int	ft_putptr(unsigned long int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (ft_putstr("0x0"));
	else
	{
		ft_putstr("0x");
		res = ft_puthex(n, 'x');
	}
	return (res + 2);
}

int	ft_count_digits(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		++i;
	}
	while (n >= 10)
	{
		n = n / 10;
		++i;
	}
	return (i + 1);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		count = ft_putnbr(-n) + 1;
	}
	else if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		++count;
	}
	return (count);
}
