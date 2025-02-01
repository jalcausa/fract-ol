/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:03:21 by jalcausa          #+#    #+#             */
/*   Updated: 2025/02/01 18:56:52 by jalcausa         ###   ########.fr       */
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
	// z(n+1) = z(n)² + c (Mirar fórmula libreta)
	while (i < max_iter && z2.a + z2.b < 4)
	{
		// Se calcula el cuadrado del complejo para la siguiente iteración
		z.b = 2 * z.a * z.b + c.b;
		z.a = z2.a - z2.b + c.a;
		// Se calcula el módulo del complejo para ver si diverge
		// Si sqrt(a² + b²) > 2 diverge => a²+b² > 4 diverge
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
	// Igual que Mandelbrot pero la constante se puede elegir
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
