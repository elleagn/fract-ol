/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 08:44:36 by gozon             #+#    #+#             */
/*   Updated: 2024/09/25 09:40:55 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_vars	init_burningship(char **argv)
{
	t_vars	vars;

	if (argv[2])
	{
		ft_printf("Burning ship set does not take any parameters.\n");
		vars.type = 0;
	}
	else
	{
		vars.iterations = 100;
		vars.threshold = 4;
		vars.type = 'b';
	}
	return (vars);
}

t_vars	init_birdsofprey(char **argv)
{
	t_vars	vars;

	if (argv[2])
	{
		ft_printf("Birds of prey set does not take any parameters.\n");
		vars.type = 0;
	}
	else
	{
		vars.iterations = 100;
		vars.threshold = 4;
		vars.type = 'p';
	}
	return (vars);
}
