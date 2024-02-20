/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/20 23:15:01 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static bool	fra_img_init_empty(t_var *var, t_img *img, int width, int height)
{
//debug_printf("width: %d\theight: %d\n", width, height);
	img->ptr = mlx_new_image(var->conn, width, height);
//DP(img->ptr);
	img->width = width;
	img->height = height;
	img->data = (int *)mlx_get_data_addr(img->ptr, \
		&img->bpp, &img->len, &img->endian);
	return (true);
}

int	fra_img_init(t_var *var)
{
	size_t	i;

	i = 0;
	while (i < N_IMAGE)
	{
		fra_img_init_empty(var, &var->img[i], WIDTH_VISION, HEIGHT_VISION);
		i++;
	}
	i = 0;
	while (i < N_IMAGE)
	{
		if (var->img[i++].ptr == NULL)
			return (ft_seterr(ERR_OPEN));
	}
	return (ERR_NOERR);
}

void	fra_img_clear(t_img *img, int color_code, int width, int height)
{
	t_addr	i;

	i.y = 0;
	while (i.y < height)
	{
		i.x = 0;
		while (i.x < width)
		{
			img->data[i.y * width + i.x] = color_code;
			i.x++;
		}
		i.y++;
	}
}

void	fra_img_destroy(t_var *var)
{
	size_t	i;

	if (var == NULL)
		return ;
	i = 0;
	while (i < N_IMAGE)
	{
		if (var->img[i].ptr != NULL)
			mlx_destroy_image(var->conn, var->img[i].ptr);
		i++;
	}
}
