/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:59:40 by gozon             #+#    #+#             */
/*   Updated: 2024/09/25 10:39:14 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_bonus.h>

double	atodouble(char *str)
{
	double	nbr;
	int		i;
	int		k;

	nbr = 0;
	i = 0;
	k = -1;
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = 10 * nbr + str[i] - 48;
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		nbr += pow(10, k) * (str[i] - 48);
		k--;
		i++;
	}
	return (nbr);
}

t_complex	atocomplex(char *real, char *imaginary)
{
	t_complex	complex;
	float		sign;

	sign = 1;
	if (real[0] == '-')
		sign = -1;
	if (real[0] == '-' || real[0] == '+')
		complex.real = sign * atodouble(&real[1]);
	else
		complex.real = atodouble(real);
	sign = 1;
	if (imaginary[0] == '-')
		sign = -1;
	if (imaginary[0] == '-' || imaginary[0] == '+')
		complex.imaginary = sign * atodouble(&imaginary[1]);
	else
		complex.imaginary = atodouble(imaginary);
	return (complex);
}

double	choose_threshold(t_complex c)
{
	double	mod;

	mod = mod_square(c);
	if (mod > 4)
		return (mod);
	else
		return (4);
}
