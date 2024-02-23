/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/23 15:26:55 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fra_calc_mandelbrot(t_cartes *coord, int *color)
{
	t_cartes	z;
	t_cartes	c;
	int			i;

	ft_cartes_init(&z);
	ft_cartes_copy(&c, coord);
	i = 0;
	while (i < MAX_ITERATION)
	{
		if (z.x * z.x + z.y * z.y > 4)
			break ;
		ft_cartes_set(&z, z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y);
		i++;
	}
	if (i == MAX_ITERATION)
		return (COLOR_BG);
	return (ft_color_hsv2code((i % N_CHROMA) * (360 / N_CHROMA), 0xff, 0xff));
	return (color[i % N_PALETTE]);
}

int	fra_calc_julia(t_cartes *coord, int *color, t_cartes *constant)
{
	t_cartes	z;
	t_cartes	c;
	int			i;

	ft_cartes_copy(&z, constant);
	ft_cartes_copy(&c, coord);
	i = 0;
	while (i < MAX_ITERATION)
	{
		if (z.x * z.x + z.y * z.y > 4)
			break ;
		ft_cartes_set(&z, z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y);
		i++;
	}
	if (i == MAX_ITERATION)
		return (COLOR_BG);
	return (ft_color_hsv2code((i % N_CHROMA) * (360 / N_CHROMA), 0xff, 0xff));
	return (color[i % N_PALETTE]);
}
