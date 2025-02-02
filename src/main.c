/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:22:29 by jalcausa          #+#    #+#             */
/*   Updated: 2025/02/02 16:19:13 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_print_fractals(t_var *vars)
{
	t_pixel	pixel;
	t_cn	complex;
	int		iter;

	(void)pixel;
	(void)vars;
	// Recorremos la imagen fila por fila
	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			complex = ft_pixel_to_cn(vars, pixel);
			// Se evalúa si el punto pertenece o no al conjunto
			iter = vars->form(complex, vars->max_iters, vars->julia);
			// Pinta el píxel con un color que depende de las iteraciones
			mlx_put_pixel(vars->img, pixel.x, pixel.y, iter * vars->colors);
			pixel.x++;
		}
		pixel.y++;
	}
	mlx_image_to_window(vars->mlx, vars->img, 0, 0);
}

t_var	*ft_init_vars(void)
{
	t_var	*vars;

	// Se reserva memoria para la estructura vars
	vars = malloc(sizeof(t_var));
	if (!vars)
		return (0);
	// Se inicializa la ventana
	vars->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!vars->mlx)
	{
		free(vars);
		exit(0);
	}
	// Se crea una imagen del mismo tamaño que la ventana
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	// Max numero de iteraciones para calcular si pertenece al conjunto
	vars->max_iters = 100;
	// Rango que se verá inicialmente del fractal: 2.5 en todas direcciones
	vars->range = 2.5;
	// Color predeterminado para puntos del fractal
	vars->colors = 65468784;
	// Centro del ratón
	vars->mx = 0;
	vars->my = 0;
	return (vars);
}

void	ft_check_args(int argc, char **argv, t_var *vars)
{
	// Si el usuario no ingresó 1 o 2 se muestra mensaje de ayuda
	if (argc == 1 || (argv[1][0] != '1'
		&& argv[1][0] != '2' && argv[1][0] != '3'))
	{
		write(1, "1... Mandelbrot\n2... Julia\n3... Burningship\n", 44);
		exit(0);
	}
	// Si ingresó 1 se incializa vars para mandelbrot
	if (argv[1][0] == '1')
	{
		vars->middle = (t_cn){-1, 0};
		vars->form = mandelbrot;
	}
	// Si ingresó 2 se inicializa vars para julia
	else if (argv[1][0] == '2')
	{
		vars->middle = (t_cn){0, 0};
		vars->form = julia;
		vars->julia = (t_cn){-0.4, 0.6};
		if (argc == 4)
			vars->julia = (t_cn){ft_atof(argv[2]), ft_atof(argv[3])};
	}
	// Si ingresó 3 se inicializa para burningship
	else if (argv[1][0] == '3')
	{
		vars->middle = (t_cn){-1, 0};
		vars->form = burningship;
	}
}

int	main(int argc, char **argv)
{
	t_var	*vars;

	vars = ft_init_vars();
	ft_check_args(argc, argv, vars); // Se verifican los argumentos y se configura vars-->form
	ft_print_fractals(vars); // Se dibuja el fractal
	// Se registran las funciones de eventos
	mlx_loop_hook(vars->mlx, &hook, vars->mlx); // Para redibujar
	mlx_key_hook(vars->mlx, &my_keyhook, vars); // Para teclas
	mlx_cursor_hook(vars->mlx, &my_curhook, vars); // Para el ratón
	mlx_scroll_hook(vars->mlx, &my_scrollhook, vars); // Para zoom
	mlx_loop(vars->mlx); // Inicia el bucle de eventos
	free(vars); // Libera la estructura vars
	return (0);
}