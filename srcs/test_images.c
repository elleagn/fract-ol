/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:27:32 by gozon             #+#    #+#             */
/*   Updated: 2024/09/18 17:43:35 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*img1;
	void	*img2;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 500, 500, "hello");
	img1 = mlx_new_image(mlx, 500, 500);
	mlx_put_image_to_window(mlx, window, img1, 0, 0);
	img2 = mlx_new_image(mlx, 500, 500);
	mlx_destroy_image(mlx, img1);
	mlx_put_image_to_window(mlx, window, img2, 0, 0);
}
