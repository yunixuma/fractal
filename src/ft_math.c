/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/20 23:10:19 by Yoshihiro K      ###   ########.fr       */
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

/*
double	ft_math_pf_deg(double deg, double (*pf)(double))
{
	return (pf(ft_math_deg2rad(deg)));
}
*/
