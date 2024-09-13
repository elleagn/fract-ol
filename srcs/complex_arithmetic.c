/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_arithmetic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:34:48 by gozon             #+#    #+#             */
/*   Updated: 2024/09/13 10:49:02 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	add_complex(t_complex z1, t_complex z2)
{
	t_complex	sum;

	sum.real = z1.real + z2.real;
	sum.imaginary = z1.imaginary + z2.imaginary;
	return (sum);
}

t_complex	multiply_complex(t_complex z1, t_complex z2)
{
	t_complex	product;

	product.real = z1.real * z2.real - z1.imaginary * z2.imaginary;
	product.imaginary = z1.real * z2.imaginary + z1.imaginary * z2.real;
	return (product);
}

double	mod_square(t_complex z)
{
	return (z.real * z.real + z.imaginary * z.imaginary);
}
