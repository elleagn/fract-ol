/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:39:52 by gozon             #+#    #+#             */
/*   Updated: 2024/09/25 11:51:42 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_bonus.h>

void	first_ulc_and_step(t_complex *ulc, double *step, t_vars vars)
{
	ulc->imaginary = sqrt(vars.threshold);
	ulc->real = -IMAGE_WIDTH * ulc->imaginary / IMAGE_HEIGHT;
	*step = -2 * ulc->real / IMAGE_WIDTH;
}

int	main(int argc, char **argv)
{
	t_params	params;
	double		step;
	t_complex	ulc;

	if (argc < 2)
		return (parsing_error(NULL), 0);
	params.vars = parsing(argc, argv);
	if (params.vars.type == 0)
		return (1);
	params.mlx = create_window();
	if (!params.mlx)
		return (1);
	first_ulc_and_step(&ulc, &step, params.vars);
	draw_fractal(params.mlx, params.vars, ulc, step);
	mlx_hooks(params);
	mlx_loop(params.mlx->mlx);
	return (0);
}
