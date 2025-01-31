/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:51:46 by jalcausa          #+#    #+#             */
/*   Updated: 2024/09/19 00:00:37 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The last increment of res is for the last digit, in case the number is negative
we need another one for the - sign
*/
static int	ft_len(int n)
{
	int	res;
	int	i;

	res = 0;
	i = n;
	while (i > 9 || i < -9)
	{
		++res;
		i = i / 10;
	}
	++res;
	if (n >= 0)
		return (res);
	else
		return (res + 1);
}

/*
Returns a string representating the given int with a - sign in the first 
position in case it is negative 
*/
char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_len(n);
	i = len - 1;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		res[i--] = n % 10 + '0';
		n = n / 10;
	}
	res[len] = '\0';
	return (res);
}
