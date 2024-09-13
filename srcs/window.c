/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:23:52 by gozon             #+#    #+#             */
/*   Updated: 2024/09/13 10:45:08 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	close_window(void **param)
{
	mlx_destroy_window(param[0], param[1]);
	mlx_destroy_display(param[0]);
	free(param[0]);
	exit(0);
}

int	main(void)
{
	void	*params[2];

	params[0] = mlx_init();
	params[1] = mlx_new_window(params[0], 800, 500, "test");
	mlx_hook(params[1], 17, (1L << 17), close_window, params);
	mlx_loop(params[0]);
	return (0);
}
