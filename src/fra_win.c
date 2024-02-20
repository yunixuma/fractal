/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/20 23:50:22 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fra_win_init(t_var *var)
{
	var->win = mlx_new_window(var->conn, \
		WIDTH_VISION, HEIGHT_VISION, STR_TITLE);
	if (var->win == NULL)
		return (ft_seterr(ERR_MLX));
	return (ERR_NOERR);
}

int	fra_win_draw_vision(t_var *var)
{
	fra_render_background(var);
	fra_render_fractal(var);
	mlx_put_image_to_window(var->conn, var->win, var->img[IDX_VISION].ptr, \
		ZERO_VISION, ZERO_VISION);
//debug_fra_ctrl(&var->param);
//debug_printf(".");
	return (ERR_NOERR);
}

/*
void	fra_win_draw_pixel(t_var *var, int x, int y, int color)
{
	t_addr	i;

	i.x = 0;
	while (i.x < SIZE_TILE)
	{
		i.y = 0;
		while (i.y < SIZE_TILE)
		{
			mlx_pixel_put(var->conn, var->win, \
				x * SIZE_TILE + i.x, y * SIZE_TILE + i.y, color);
			i.y++;
		}
		i.x++;
	}
}
*/

void	fra_win_destroy(t_var *var)
{
	if (var != NULL && var->conn != NULL && var->win != NULL)
		mlx_destroy_window(var->conn, var->win);
}
