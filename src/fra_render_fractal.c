/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_render_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/26 14:33:29 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	fra_render_fractal(t_var *var)
{
	t_cartes	coord;
	t_addr		pixel;
	int			iter;

	pixel.x = 0;
	while (pixel.x < WIDTH_VISION)
	{
		pixel.y = 0;
		while (pixel.y < HEIGHT_VISION)
		{
			coord.x = (double)(pixel.x - WIDTH_VISION / 2) * var->param->zoom - var->param->coord.x;
			coord.y = (double)(pixel.y - HEIGHT_VISION / 2) * var->param->zoom - var->param->coord.y;
			if (var->param->type == TYPE_MANDELBROT)
				iter = fra_calc_mandelbrot(coord, var->param->constant, var->param->cycle);
			else if (var->param->type == TYPE_JULIA)
				iter = fra_calc_julia(coord, var->param->constant, var->param->cycle);
			else
				iter = fra_calc_sierpinski(coord, var->param->cycle);
			// color_code = var->fp[param->param->type](&coord, var->param->color);
			if (iter != var->param->cycle)
				fra_render_pixel(&var->img[IDX_VISION], var->param->color[iter % N_COLOR], &pixel);
			// fra_render_pixel(&var->img[IDX_VISION], ft_color_hsv2code((iter % N_HUE) * (360 / N_HUE), 0xff, 0xff), &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}
