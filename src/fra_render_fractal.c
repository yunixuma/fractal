/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_render_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/26 18:57:42 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	fra_render_fractal(t_var *var)
{
	t_cartes	coord;
	t_addr		pixel;
	int			depth;

	pixel.x = 0;
	while (pixel.x < WIDTH_VISION)
	{
		pixel.y = 0;
		while (pixel.y < HEIGHT_VISION)
		{
			coord.x = (double)(pixel.x - WIDTH_VISION / 2) \
				* var->param->zoom - var->param->coord.x;
			coord.y = (double)(pixel.y - HEIGHT_VISION / 2) \
				* var->param->zoom - var->param->coord.y;
			if (var->param->type == TYPE_MANDELBROT)
				depth = fra_calc_mandelbrot(coord, var->param->constant, \
					var->param->depth);
			else if (var->param->type == TYPE_JULIA)
				depth = fra_calc_julia(coord, var->param->constant, \
					var->param->depth);
			else if (var->param->type == TYPE_BURNINGSHIP)
				depth = fra_calc_burningship(coord, var->param->constant, \
					var->param->depth);
			else
				depth = fra_calc_sierpinski(coord, var->param->depth);
			// color_code = var->fp[param->param->type](&coord, var->param->color);
// DI(depth);
// DD(coord.x);
// DD(coord.y);
			fra_render_pixel(&var->img[IDX_VISION], \
				var->param->color[depth % N_COLOR], &pixel);
			// fra_render_pixel(&var->img[IDX_VISION], ft_color_hsv2code((depth % N_HUE) * (360 / N_HUE), 0xff, 0xff), &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}
