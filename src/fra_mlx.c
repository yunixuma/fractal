/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/20 23:12:04 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fra_mlx_init(t_var *var)
{
	size_t	i;

	var->conn = mlx_init();
	if (!var->conn)
		return (ft_seterr(ERR_MLX));
	var->win = NULL;
	i = 0;
	while (i < N_IMAGE)
		var->img[i++].ptr = NULL;
	return (ERR_NOERR);
}

int	fra_mlx_hook(t_var *var)
{
	fra_ctrl_keyhook_fire(var->param->key, var);
	if (ft_hasflag(var->param->event, FLAG_DRAW))
		fra_win_draw_vision(var);
	if (ft_hasflag(var->param->event, FLAG_PROMPT))
		fra_print_status(var->param);
	var->param->event &= (FLAG_KEY | FLAG_CURSOR);
	var->param->event &= ~(FLAG_DRAW | FLAG_PROMPT);
	return (ERR_NOERR);
}

int	fra_mlx_loop(t_var *var)
{
	mlx_hook(var->win, EVENT_KEYDOWN, MASK_STRUCT << SHIFT_KEYDOWN, \
		&fra_ctrl_keyhook_down, var);
	mlx_hook(var->win, EVENT_KEYUP, MASK_STRUCT << SHIFT_KEYUP, \
		&fra_ctrl_keyhook_up, var);
	mlx_mouse_hook(var->win, &fra_ctrl_clickhook, var);
	mlx_hook(var->win, EVENT_MOUSEMOVE, MASK_STRUCT << SHIFT_MOUSEMOVE, \
		&fra_ctrl_cursorhook, var);
	mlx_hook(var->win, EVENT_DESTROY, MASK_STRUCT << SHIFT_DESTROY, \
		&fra_exit_mlx_break, var);
	mlx_expose_hook(var->win, &fra_win_draw_vision, var);
	mlx_loop_hook(var->conn, &fra_mlx_hook, var);
	mlx_loop(var->conn);
	return (fra_exit_mlx(var, ERR_NOERR));
}
