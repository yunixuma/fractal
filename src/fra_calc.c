/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/25 15:31:16 by ykosaka          ###   ########.fr       */
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
	if (i == cycle)
		return (COLOR_BG);
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
	if (i == cycle)
		return (COLOR_BG);
	return (i);
}

int	fra_calc_newton(t_cartes z, t_cartes c, int cycle)
{
	int			i;

	i = 0;
	while (i < cycle)
	{
		if (z.x * z.x + z.y * z.y > LIMIT_SIZE)
			break ;
		ft_cartes_set(&z, z.x * z.x * z.x - 3 * z.x * z.y * z.y + c.x, \
			3 * z.x * z.x * z.y + z.y * z.y * z.y + c.y);
		i++;
	}
	if (i == cycle)
		return (COLOR_BG);
	return (i);
}
