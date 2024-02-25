/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/25 13:04:35 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fra_calc_mandelbrot(t_cartes c, int *color, int cycle, t_cartes z)
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
	if (i == cycle)
		return (COLOR_BG);
	// return (ft_color_hsv2code((i % N_HUE) * (360 / N_HUE), 0xff, 0xff));
	return (color[i % N_COLOR]);
}

int	fra_calc_julia(t_cartes z, int *color, int cycle, t_cartes c)
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
	if (i == cycle)
		return (COLOR_BG);
	// return (ft_color_hsv2code((i % N_HUE) * (360 / N_HUE), 0xff, 0xff));
	return (color[i % N_COLOR]);
}
