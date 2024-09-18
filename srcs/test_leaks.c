/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:52:52 by gozon             #+#    #+#             */
/*   Updated: 2024/09/18 12:58:15 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
