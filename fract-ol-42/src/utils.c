/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:58:07 by jalcausa          #+#    #+#             */
/*   Updated: 2025/02/02 19:50:06 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_cn	ft_pixel_to_cn(t_var *vars, t_pixel pixel)
{
	t_cn	c;

	c.a = vars->middle.a + 2 * vars->range * (pixel.x / (double)WIDTH - 0.5);
	c.b = vars->middle.b + 2 * vars->range * (pixel.y / (double)HEIGHT - 0.5);
	return (c);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		++i;
	}
	res = res * sign;
	return (res);
}

double	ft_atof(char *str)
{
	int		i;
	double	ret;
	double	n_deci;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
	{
		ret = (double)ft_atoi(str);
		return (ret);
	}
	str[i] = '\0';
	ret = (double)ft_atoi(str);
	n_deci = (double)ft_atoi(&str[i + 1]);
	while (n_deci > 1)
		n_deci /= 10;
	while (str[++i] == '0')
		n_deci /= 10;
	if (str[0] == '-')
		return (ret - n_deci);
	return (ret + n_deci);
}
