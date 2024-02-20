/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_render_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/21 00:10:18 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	fra_render_line(t_img *img, int color_code, t_addr *zero, t_polar *line)
{
	t_addr	addr;
	ssize_t	i;
	ssize_t	len;

	len = (ssize_t)line->radius;
	i = 0;
	while (i < len)
	{
		addr.x = zero->x + (ssize_t)(i * cos(line->angle));
		addr.y = zero->y + (ssize_t)(i * sin(line->angle));
		if (addr.x >= 0 && addr.x < img->width \
			&& addr.y > 0 && addr.y < img->height)
			img->data[img->width * addr.y + addr.x] = color_code;
		i++;
	}
}
