/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:35:11 by gozon             #+#    #+#             */
/*   Updated: 2024/09/18 11:53:27 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define IMAGE_WIDTH 800
# define IMAGE_HEIGHT 600
# define COLOR 0x34ebdbu

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_complex	upper_left_corner;
	double		step;
}	t_mlx;

typedef struct s_pixel
{
	int			coord_x;
	int			coord_y;
	t_complex	complex;
}	t_pixel;

typedef struct s_vars
{
	t_complex	c;
	double		threshold;
	int			iterations;
	char		type;
}	t_vars;

// Complex arithmetic

t_complex	add_complex(t_complex z1, t_complex z2);
t_complex	multiply_complex(t_complex z1, t_complex z2);
double		mod_square(t_complex z);

// Sequence calculations

int			calc_jmb(t_complex z0, t_complex c, int it, double thresh_sq);

// Image manipulation

void		color_image(t_mlx mlx, t_vars vars);

#endif
