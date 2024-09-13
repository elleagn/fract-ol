/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:35:11 by gozon             #+#    #+#             */
/*   Updated: 2024/09/13 10:49:52 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_vars
{
	t_complex	c;
	double		threshold_square;
	int			iterations;
}	t_vars;

t_complex	add_complex(t_complex z1, t_complex z2);
t_complex	multiply_complex(t_complex z1, t_complex z2);
double		mod_square(t_complex z);

#endif
