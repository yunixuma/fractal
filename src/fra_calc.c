/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/26 18:54:38 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fra_calc_mandelbrot(t_cartes c, t_cartes z, int depth)
{
	int			i;

	i = 0;
	while (i < depth)
	{
		if (z.x * z.x + z.y * z.y > LIMIT_SIZE)
			break ;
		ft_cartes_set(&z, z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y);
		i++;
	}
	return (i);
}

int	fra_calc_julia(t_cartes z, t_cartes c, int depth)
{
	int			i;

	i = 0;
	while (i < depth)
	{
		if (z.x * z.x + z.y * z.y > LIMIT_SIZE)
			break ;
		ft_cartes_set(&z, z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y);
		i++;
	}
	return (i);
}

int	fra_calc_burningship(t_cartes c, t_cartes z, int depth)
{
	int			i;
	t_cartes	tmp;

	i = 0;
	while (i < depth)
	{
		if (z.x * z.x + z.y * z.y > LIMIT_SIZE)
			break ;
		ft_cartes_set(&tmp, z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y);
		if (tmp.x < 0)
			tmp.x = -tmp.x;
		if (tmp.y < 0)
			tmp.y = -tmp.y;
		ft_cartes_set(&z, tmp.x, tmp.y);
		i++;
	}
	return (i);
}

int	fra_calc_newton(t_cartes z, t_cartes c, int depth)
{
	int			i;

	i = 0;
	while (i < depth)
	{
		if (z.x * z.x + z.y * z.y > LIMIT_SIZE)
			break ;
		ft_cartes_set(&z, z.x * z.x * z.x - 3 * z.x * z.y * z.y + c.x, \
			3 * z.x * z.x * z.y + z.y * z.y * z.y + c.y);
		i++;
	}
	if (i == depth)
		return (COLOR_BG);
	return (i);
}

int	fra_calc_sierpinski(t_cartes z, int depth)
{
	t_cartes	a;
	t_cartes	b;
	t_cartes	c;
	int			i;

	ft_cartes_set(&a, 0, 1);
	ft_cartes_set(&b, cos(ft_math_deg2rad(-120)), sin(ft_math_deg2rad(-120)));
	ft_cartes_set(&c, cos(ft_math_deg2rad(-30)), sin(ft_math_deg2rad(-30)));
	if (!ft_math_in_triangle(z, a, b, c))
		return (depth);
	i = 0;
	while (i++ < depth)
	{
		if (z.y >= (a.y + b.y) / 2)
		{
			ft_cartes_set(&b, (a.x + b.x) / 2, (a.y + b.y) / 2);
			ft_cartes_set(&c, (a.x + c.x) / 2, (a.y + c.y) / 2);
		}
		else if (z.x <= (b.x + c.x) / 2)
		{
			ft_cartes_set(&c, a.x, c.y);
			ft_cartes_set(&a, (a.x + b.x) / 2, (a.y + b.y) / 2);
		}
		else
		{
			ft_cartes_set(&b, a.y, b.y);
			ft_cartes_set(&a, (a.x + c.x) / 2, (a.y + c.y) / 2);
		}
		if (ft_math_in_triangle(z, a, b, c))
			return (i);
	}
	return (i);
}
