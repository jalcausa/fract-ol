/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:03:21 by jalcausa          #+#    #+#             */
/*   Updated: 2025/02/02 19:47:44 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot(t_cn c, int max_iter, t_cn args)
{
	t_cn		z;
	t_cn		z2;
	int			i;

	(void)args;
	z.a = 0;
	z.b = 0;
	z2.a = 0;
	z2.b = 0;
	i = 0;
	while (i < max_iter && z2.a + z2.b < 4)
	{
		z.b = 2 * z.a * z.b + c.b;
		z.a = z2.a - z2.b + c.a;
		z2.a = z.a * z.a;
		z2.b = z.b * z.b;
		i++;
	}
	if (i == max_iter)
		return (0);
	return (i);
}

int	julia(t_cn z, int max_iter, t_cn args)
{
	t_cn	z2;
	int		i;
	t_cn	c;

	z2.a = z.a * z.a;
	z2.b = z.b * z.b;
	c = args;
	i = 0;
	while (i < max_iter && z2.a + z2.b < 4)
	{
		z.b = 2 * z.a * z.b + c.b;
		z.a = z2.a - z2.b + c.a;
		z2.a = z.a * z.a;
		z2.b = z.b * z.b;
		i++;
	}
	if (i == max_iter)
		return (0);
	return (i);
}

int	burningship(t_cn c, int max_iter, t_cn args)
{
	t_cn	z;
	t_cn	z2;
	int		i;
	double	prod;

	(void)args;
	z.a = 0;
	z.b = 0;
	z2.a = 0;
	z2.b = 0;
	i = 0;
	while (i < max_iter && z2.a + z2.b < 4)
	{
		prod = z.a * z.b;
		if (prod < 0)
			prod = -prod;
		z.b = 2 * prod + c.b;
		z.a = z2.a - z2.b + c.a;
		z2.a = z.a * z.a;
		z2.b = z.b * z.b;
		i++;
	}
	if (i == max_iter)
		return (0);
	return (i);
}
