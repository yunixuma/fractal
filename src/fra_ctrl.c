/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/21 07:55:36 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

bool	fra_ctrl_speed(t_param *param)
{
	if (param->speed >= MAX_SPEED)
		param->speed = UNIT_SPEED;
	else if (param->speed + UNIT_SPEED >= MAX_SPEED)
		param->speed = MAX_SPEED;
	else
		param->speed += UNIT_SPEED;
	return (true);
}

bool	fra_ctrl_move(t_var *var, t_cartes *move)
{
	// if (!fra_ctrl_move_valid(var->param->map, move, &var->param->cartes))
	// 	return (false);
	var->param->coord.y += move->y;
	var->param->coord.x += move->x;
//debug_printf("move: (%6.3lf, %6.3lf)\n", move->x, move->y);
//debug_printf("cartes: (%6.3lf, %6.3lf)\n", var->param->cartes.x, var->param->cartes.y);
	return (true);
}

bool	fra_ctrl_zoom(t_param *param, double zoom_ply)
{
	double	zoom_bak;

	zoom_bak = param->zoom;
	param->zoom *= zoom_ply;
	if (param->zoom > ZOOM_MAX)
		param->zoom = ZOOM_MAX;
	else if (param->zoom < ZOOM_MIN)
		param->zoom = ZOOM_MIN;
	if (param->zoom == zoom_bak)
		return (false);
	return (true);
}

bool	fra_ctrl_cursormode(t_param *param)
{
	if (ft_hasflag(param->event, FLAG_CURSOR))
		param->event &= ~FLAG_CURSOR;
	else
		param->event |= FLAG_CURSOR;
	return (true);
}

/*
bool	fra_ctrl_judge(t_var *var)
{
	if (var->param->map[(size_t)var->param->cartes.y][(size_t)var->param->cartes.x] \
		!= CHRS_MAP[IDX_SOUTH])
		return (false);
	else if (ft_mapseek_exist(var->param->map, CHRS_MAP[IDX_EAST]))
		return (false);
	return (true);
}
*/