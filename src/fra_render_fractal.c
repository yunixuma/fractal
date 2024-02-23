/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_render_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/23 14:43:27 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	fra_render_mandelbrot(t_var *var)
{
	t_cartes	coord;
	t_addr		pixel;
	int			color_code;

	pixel.x = var->param->coord.x;
	while (pixel.x < WIDTH_VISION)
	{
		pixel.y = var->param->coord.y;
		while (pixel.y < HEIGHT_VISION)
		{
			coord.x = (double)(pixel.x - WIDTH_VISION / 2) * var->param->zoom - var->param->coord.x;
			coord.y = (double)(pixel.y - HEIGHT_VISION / 2) * var->param->zoom - var->param->coord.y;
			color_code = fra_calc_mandelbrot(&coord, var->param->color);
			// color_code = var->fp[param->param->type](&coord, var->param->color);
			fra_render_pixel(&var->img[IDX_VISION], color_code, &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}

static void	fra_render_julia(t_var *var)
{
	t_cartes	coord;
	t_addr		pixel;
	int			color_code;

	pixel.x = var->param->coord.x;
	while (pixel.x < WIDTH_VISION)
	{
		pixel.y = var->param->coord.y;
		while (pixel.y < HEIGHT_VISION)
		{
			coord.x = (double)(pixel.x - WIDTH_VISION / 2) * var->param->zoom - var->param->coord.x;
			coord.y = (double)(pixel.y - HEIGHT_VISION / 2) * var->param->zoom - var->param->coord.y;
			color_code = fra_calc_julia(&coord, var->param->color, &var->param->constant);
			// color_code = var->fp[param->param->type](&coord, var->param->color);
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
	if (var->param->type == TYPE_JULIA)
		fra_render_julia(var);
}
