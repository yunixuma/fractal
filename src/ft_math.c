/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/26 18:09:47 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_math.h"

double	ft_math_deg2rad(double deg)
{
	return (M_PI * deg / 180);
}

double	ft_math_rad2deg(double rad)
{
	return (rad * 180 / M_PI);
}

double	ft_math_angle_normalize(double deg)
{
	if (deg > 180)
		deg -= 360;
	else if (deg < -180)
		deg += 360;
	return (deg);
}

double	ft_math_area_triangle(t_cartes a, t_cartes b, t_cartes c)
{
	double	s;

	s = (b.x - c.x) * (a.y - c.y) - (b.y - c.y) * (a.x - c.x);
	if (s < 0)
		s = -s;
	return (s);
}

bool	ft_math_in_triangle(t_cartes z, t_cartes a, t_cartes b, t_cartes c)
{
	double		abc;
	double		zab;
	double		zbc;
	double		zca;

	abc = ft_math_area_triangle(a, b, c);
	zab = ft_math_area_triangle(z, a, b);
	zbc = ft_math_area_triangle(z, b, c);
	zca = ft_math_area_triangle(z, c, a);
	// if (abc == 0 || zab == 0 || zbc == 0 || zca == 0)
	// 	return (false);
	if (zab + zbc + zca - abc < 0.01)
		return (true);
	else
		return (false);
}

/*
double	ft_math_pf_deg(double deg, double (*pf)(double))
{
	return (pf(ft_math_deg2rad(deg)));
}
*/
