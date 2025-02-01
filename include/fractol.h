/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:14:12 by jalcausa          #+#    #+#             */
/*   Updated: 2025/02/01 19:46:23 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"

# ifndef WIDTH
#  define WIDTH 700 // Ancho de la ventana
# endif

# ifndef HEIGHT
#  define HEIGHT 700 // Alto de la ventana
# endif

// Estructura para almacenar un número complejo (a + bi)
typedef struct s_cn
{
	double	a;
	double	b;
}	t_cn;

// Estructura para representar las coordenadas de un píxel
typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

// Estructura para las variables globales del sistema
typedef struct s_var
{
	mlx_t			*mlx; // Puntero al contexto MLX42
	mlx_image_t		*img; // Imagen para dibujar el fractal
	double			max_iters; // Num máximo de iteraciones
	int				(*form)(t_cn, int, t_cn); //  Puntero a función que calcula si el punto pertenece al fractal
	double			range; // Rango de valores complejos representados en pantalla
	t_cn			middle; // Punto central del área representada
	t_cn			julia; // Parámetro especial para Julia
	int				mx; // Coordenada x del ratón en pantalla
	int				my; // Coordenada y del ratón en pantalla
	int				colors; // Esquema de colores del fractal
}	t_var;

// Hooks
void	hook(void *param);
void	my_scrollhook(double xdelta, double ydelta, void *param);
void	my_curhook(double xpos, double ypos, void *param);
void	my_keyhook(mlx_key_data_t keydata, void *param);

//Utils
t_cn	ft_pixel_to_cn(t_var *vars, t_pixel pixel);
void	ft_print_fractals(t_var *vars);
double	ft_atof(char *str);

//Fractals
int		mandelbrot(t_cn c, int max_iter, t_cn args);
int		burningship(t_cn c, int max_iter, t_cn args);
int		julia(t_cn z, int max_iter, t_cn args);

#endif
