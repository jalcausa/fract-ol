/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:14:12 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/29 22:39:08 by jalcausa         ###   ########.fr       */
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
//# include "../libft/libft.h"

# ifndef WIDTH
#  define WIDTH 1000 // Ancho de la ventana
# endif

# ifndef HEIGHT
#  define HEIGHT 1000 // Alto de la ventana
# endif

# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 100 // Iteraciones máximas en cálculo fractal
# endif

#endif
