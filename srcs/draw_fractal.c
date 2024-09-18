/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:37:45 by gozon             #+#    #+#             */
/*   Updated: 2024/09/18 17:34:11 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_img	create_new_img(t_img img, t_vars vars, double zoom, t_mlx *mlx)
{
	t_img	new_img;

	if (!new_img.img)
		return (perror("mlx_new_image"), close_window(mlx), img);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
			&new_img.line_length, &new_img.endian);
	if (zoom == 0)
	{
		new_img.img = mlx_new_image(mlx->mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
		new_img.upper_left_corner.imaginary = sqrt(vars.threshold);
		new_img.upper_left_corner.real = -IMAGE_WIDTH
			* new_img.upper_left_corner.imaginary / IMAGE_HEIGHT;
		new_img.step = -2 * new_img.upper_left_corner.real / IMAGE_WIDTH;
		printf("%f \n", new_img.step);
	}
	else
	{
		new_img = img;
		new_img.upper_left_corner.real
			= img.upper_left_corner.real / zoom;
		new_img.upper_left_corner.imaginary
			= img.upper_left_corner.imaginary / zoom;
		new_img.step = img.step / zoom;
	}
	return (new_img);
}

void	draw_fractal(t_mlx *mlx, t_vars vars, double zoom)
{
	t_img	new_img;

	new_img = create_new_img(mlx->img, vars, zoom, mlx);
	color_image(new_img, vars);
	mlx_put_image_to_window(mlx->mlx, mlx->window, new_img.img, 0, 0);
	if (mlx->img.img)
	{
		ft_printf("before destruction");
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		ft_printf("before destruction");
	}
	mlx->img = new_img;
}

int	main(void)
{
	t_vars	vars;
	t_mlx	*mlx;

	vars.c.real = -0.8;
	vars.c.imaginary = 0.156;
	vars.iterations = 100;
	vars.threshold = 4;
	vars.type = 'j';
	if (vars.type == 0)
		return (1);
	mlx = create_window();
	if (!mlx)
		return (1);
	draw_fractal(mlx, vars, 0);
	mlx_hooks(mlx, vars);
	mlx_loop(mlx->mlx);
	return (0);
}
