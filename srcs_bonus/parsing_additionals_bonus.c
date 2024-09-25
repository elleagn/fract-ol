/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_additionals_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 08:44:36 by gozon             #+#    #+#             */
/*   Updated: 2024/09/25 11:26:43 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_bonus.h>

t_vars	init_burningship(char **argv)
{
	t_vars	vars;

	if (argv[2])
	{
		parsing_error(&vars);
		vars.type = 0;
	}
	else
	{
		vars.threshold = 4;
		vars.type = 'b';
	}
	return (vars);
}

t_vars	init_birdsofprey(char **argv)
{
	t_vars	vars;

	if (argv[2])
		parsing_error(&vars);
	else
	{
		vars.threshold = 4;
		vars.type = 'p';
	}
	return (vars);
}
