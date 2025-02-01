/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:08:13 by jalcausa          #+#    #+#             */
/*   Updated: 2025/02/01 19:16:20 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#include "../include/fractol.h"

//Comprueba si se ha presionado la tecla escape
void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

// Si pulsamos c cambiamos los colores, nos movemos con las flechas
void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_var	*vars;

	vars = (t_var *)param;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		vars->colors *= 1.01;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		vars->middle.a += vars->range / 4;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		vars->middle.a -= vars->range / 4;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		vars->middle.b += vars->range / 4;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		vars->middle.b -= vars->range / 4;
	ft_print_fractals(vars);
	mlx_image_to_window(vars->mlx, vars->img, 0, 0);
}

// Actualiza la posición actual del ratón en la pantalla
void	my_curhook(double xpos, double ypos, void *param)
{
	t_var	*vars;

	vars = (t_var *)param;
	vars->mx = xpos;
	vars->my = ypos;
}

// Comprueba si se ha tocado la rueda del ratón y ajusta zoom
// Si se hace zoom se amplía el número de iteraciones para mostrar más detalles
// Si se reduce el zoom se reduce el número de iteraciones con un mínimo de 100 para mostrar menos detalles
void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_var	*vars;
	t_cn	p2;

	(void)xdelta;
	vars = (t_var *)param;
	p2 = ft_pixel_to_cn(vars, (t_pixel){vars->mx, vars->my});
	if (ydelta < 0)
	{
		vars->middle = (t_cn){(vars->middle.a + p2.a) / 2,
			(vars->middle.b + p2.b) / 2};
		vars->range *= 0.5;
		vars->max_iters *= 1.05;
	}
	else if (ydelta > 0)
	{
		vars->middle = (t_cn){2 * vars->middle.a - p2.a,
			2 * vars->middle.b - p2.b};
		vars->range *= 2;
		vars->max_iters *= 0.95;
		if (vars->max_iters < 100)
			vars->max_iters = 100;
	}
	ft_print_fractals(vars);
	mlx_image_to_window(vars->mlx, vars->img, 0, 0);
}
