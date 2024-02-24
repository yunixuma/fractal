/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_render_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/24 22:58:50 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	fra_render_fractal(t_var *var)
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
			coord.x = (double)(pixel.x - WIDTH_VISION / 2) * var->param->zoom - var->param->coord.x;
			coord.y = (double)(pixel.y - HEIGHT_VISION / 2) * var->param->zoom - var->param->coord.y;
			if (var->param->type == TYPE_MANDELBROT)
				color_code = fra_calc_mandelbrot(coord, var->param->color);
			else
				color_code = fra_calc_julia(coord, var->param->color, var->param->constant);
			// color_code = var->fp[param->param->type](&coord, var->param->color);
			fra_render_pixel(&var->img[IDX_VISION], color_code, &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}
