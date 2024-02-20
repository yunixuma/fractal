/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/21 01:19:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_math.h"

double	ft_math_distance_2d(t_cartes *pt1, t_cartes *pt2)
{
	double	dx;
	double	dy;

	if (!pt1 || !pt2)
		return (0);
	dx = pt1->x - pt2->x;
	dy = pt1->y - pt2->y;
	return (hypot(dx, dy));
}
