/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:14:12 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/31 11:09:33 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# ifndef WIDTH
#  define WIDTH 1000 // Ancho de la ventana
# endif

# ifndef HEIGHT
#  define HEIGHT 1000 // Alto de la ventana
# endif

# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 100 // Iteraciones máximas en cálculo fractal
# endif

// Estructura para gestionar la conexión entre MLX42 y la imagen
typedef struct s_img
{
	mlx_t		*mlx; // Puntero al contexto MLX42
	mlx_image_t	*img; // Puntero a la imagen renderizada
}	t_img;

// Estructura para almacenar parámetros de color del fractal
typedef struct s_color_scheme
{
	int	shift; // Desplazamiento de color (efectos dinámicos)
	int	r_set, g_set, b_set; // Valores base RGB
	int	hue; // Tono (para esquemas HSV)
	int	saturation; // Saturación (para esquemas HSV)
	int	brightness; // Brillo (para esquemas HSV)
	int	contrast; // Contraste
	int	c;
	int	x;
	int	m; // Variables temporales para cálculo del color
	int r;
	int g;
	int b; // Componentes RGB finales
	int	palette; // Índice de la paleta de colores
}	t_color_scheme;

// Estructura para contener el estado actual del programa
typedef struct s_fractol
{
	t_img			img; // Contexto MLX42 e imagen
	char			*name; // Nombre del fractal (mandelbrot / julia)
	int				x;
	int				y; // Coordenadas del píxel actual
	double			m_zi;
	double			m_zr; // Valores iniciales de z para Mandelbrot (z0 = 0)
	double			j_ci;
	double			j_cr; // Parte imaginaria y real de la constante c para Julia
	double			max_i;
	double			max_r; // Límites máximos del plano complejo
	double			min_i;
	double			min_r; // Límites mínimos del plano complejo
	double			pi;
	double			pr; // Paso/paso entre píxeles (delta para escalar coordenadas)
	int				error; // Código de error
	int				n; // Número de iteraciones actuales
	double			zoom_factor; // Factor de zoom
	t_color_scheme	cs; // Esquema de color actual
}	t_fractol;

enum	e_error
{
	OK = 0,
	ARGS_FAIL = 1,
	MLX_FAIL = 2
};

#endif
