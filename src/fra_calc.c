/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/26 15:00:41 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fra_calc_mandelbrot(t_cartes c, t_cartes z, int cycle)
{
	int			i;

	i = 0;
	while (i < cycle)
	{
		if (z.x * z.x + z.y * z.y > LIMIT_SIZE)
			break ;
		ft_cartes_set(&z, z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y);
		i++;
	}
	return (i);
}

int	fra_calc_julia(t_cartes z, t_cartes c, int cycle)
{
	int			i;

	i = 0;
	while (i < cycle)
	{
		if (z.x * z.x + z.y * z.y > LIMIT_SIZE)
			break ;
		ft_cartes_set(&z, z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y);
		i++;
	}
	return (i);
}

double	ft_area_triangle(t_cartes a, t_cartes b, t_cartes c)
{
	double	s;
	s = (b.x - c.x) * (a.y - c.y) - (b.y - c.y) * (a.x - c.x);
	if (s < 0)
		s = -s;
	return (s);
}

bool	ft_in_triangle(t_cartes z, t_cartes a, t_cartes b, t_cartes c)
{
	double		abc;
	double		zab;
	double		zbc;
	double		zca;

	abc = ft_area_triangle(a, b, c);
	zab = ft_area_triangle(z, a, b);
	zbc = ft_area_triangle(z, b, c);
	zca = ft_area_triangle(z, c, a);
	if (abc == 0 || zab == 0 || zbc == 0 || zca == 0)
		return (false);
	else if (abc == zab + zbc + zca)
		return (true);
	else
		return (false);
}

int	fra_calc_sierpinski(t_cartes z, int cycle)
{
	t_cartes	a;
	t_cartes	b;
	t_cartes	c;
	int			i;

	ft_cartes_set(&a, 0, 1);
	ft_cartes_set(&b, -sin(ft_math_deg2rad(60)), -cos(ft_math_deg2rad(60)));
	ft_cartes_set(&c, sin(ft_math_deg2rad(60)), -cos(ft_math_deg2rad(60)));
	i = 0;
	while (i < cycle)
	{
		if (ft_in_triangle(z, a, b, c))
			break ;
		if (z.x > (b.x + c.x) / 2)
		{
			if (z.y < (b.y + a.y) / 2)
				ft_cartes_set(&b, (b.x + c.x) / 2, b.y);
			else
				ft_cartes_set(&b, (b.x + a.x) / 2, (b.y + a.y) / 2);
		}
		else
		{
			if (z.y < (b.y + a.y) / 2)
				ft_cartes_set(&b, (b.x + a.x) / 2, (b.y + a.y) / 2);
			else
				ft_cartes_set(&c, (b.x + c.x) / 2, c.y);
		}
		if (z.x > (a.x + c.x) / 2)
		{
			if (z.y < (b.y + a.y) / 2)
				ft_cartes_set(&b, (b.x + c.x) / 2, b.y);
			else
				ft_cartes_set(&b, (b.x + a.x) / 2, (b.y + a.y) / 2);
		}
		else
		{
			if (z.y < (b.y + a.y) / 2)
				ft_cartes_set(&b, (b.x + a.x) / 2, (b.y + a.y) / 2);
			else
				ft_cartes_set(&c, (b.x + c.x) / 2, c.y);
		}
		if (z.x > (a.x + b.x) / 2)
		{
			if (z.y < (b.y + a.y) / 2)
				ft_cartes_set(&b, (b.x + c.x) / 2, b.y);
			else
				ft_cartes_set(&b, (b.x + a.x) / 2, (b.y + a.y) / 2);
		}
		else
		{
			if (z.y < (b.y + a.y) / 2)
				ft_cartes_set(&b, (b.x + a.x) / 2, (b.y + a.y) / 2);
			else
				ft_cartes_set(&c, (b.x + c.x) / 2, c.y);
		}
		if (z.x > (a.x + c.x) / 2)
		{
			if (z.y < (c.y + a.y) / 2)
				ft_cartes_set(&b, (b.x + c.x) / 2, b.y);
			else
				ft_cartes_set(&b, (b.x + a.x) / 2, (b.y + a.y) / 2);
		}
		else
		{
			if (z.y < (b.y + a.y) / 2)
				ft_cartes_set(&b, (b.x + a.x) / 2, (b.y + a.y) / 2);
			else
				ft_cartes_set(&c, (b.x + c.x) / 2, c.y);
		}
		i++;
	}
	return (i);
}
