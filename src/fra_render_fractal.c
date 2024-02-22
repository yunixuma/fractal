/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_render_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/22 09:08:30 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fra_calc_mandelbrot(t_cartes *coord, int *color)
{
	t_cartes	z;
	t_cartes	c;
	// int			i;

	ft_cartes_init(&z);
	ft_cartes_copy(&c, coord);
	return (color[(int)((c.x - z.y) * (c.y - z.x)) % N_COLOR]);
	// i = 0;
	// while (i < MAX_ITERATION)
	// {
	// 	i++;
	// }
	// return (fra_define_color(i));
}

void	fra_render_mandelbrot(t_var *var)
{
	t_cartes	coord;
	t_addr		pixel;
	int			color_code;

	pixel.x = 0;
	while (pixel.x < WIDTH_VISION)
	{
		pixel.y = 0;
		while (pixel.y < HEIGHT_VISION)
		{
			coord.x = (double)(pixel.x - WIDTH_VISION / 2) / var->param->zoom;
			coord.y = (double)(pixel.y - HEIGHT_VISION / 2) / var->param->zoom;
			color_code = fra_calc_mandelbrot(&coord, var->param->color);
			fra_render_pixel(&var->img[IDX_VISION], color_code, &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}

void	fra_render_fractal(t_var *var)
{
	if (var->param->type == TYPE_MANDELBROT)
		fra_render_mandelbrot(var);
	// else if (var->param->type == TYPE_JULIA)
	// 	fra_render_julia(var);
}
