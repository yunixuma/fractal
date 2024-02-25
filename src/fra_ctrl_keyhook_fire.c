/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_param_keyhook_fire.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/20 20:37:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static bool	fra_ctrl_keyhook_fire_move(t_cartes *move, int key, \
	int speed, double zoom)
{
	double	polar;

	polar = 0;
	if (key == KEY_MOVERIGHT)
		polar += ANGLE_RIGHT * 3;
	else if (key == KEY_MOVELEFT)
		polar += ANGLE_RIGHT * 1;
	else if (key == KEY_MOVEUP)
		polar += ANGLE_RIGHT * 2;
	else if (key != KEY_MOVEDOWN)
		return (false);
	move->x = UNIT_MOVE * speed * zoom * sin(ft_math_deg2rad(polar));
	move->y = UNIT_MOVE * speed * zoom * -cos(ft_math_deg2rad(polar));
	return (true);
}

static bool	fra_ctrl_keyhook_fire_zoom(double *ratio, int key, int speed)
{
	*ratio = 1;
	if (key == KEY_WIDE)
		*ratio = UNIT_ZOOM * speed;
	else if (key == KEY_TELE)
		*ratio /= (UNIT_ZOOM * speed);
	else
		return (false);
	return (true);
}

static bool	fra_ctrl_keyhook_fire_cycle(double *ratio, int key)
{
	*ratio = 1;
	if (key == KEY_CYCLE_INCR)
		*ratio = UNIT_CYCLE;
	else if (key == KEY_CYCLE_DECR)
		*ratio /= UNIT_CYCLE;
	else
		return (false);
	return (true);
}

static bool	fra_ctrl_keyhook_fire_constant(t_cartes *move, int key, \
	int speed, double zoom)
{
	double	polar;

	polar = 0;
	if (key == KEY_REALPLUS)
		polar += ANGLE_RIGHT * 1;
	else if (key == KEY_REALMINUS)
		polar += ANGLE_RIGHT * 3;
	else if (key == KEY_IMAGPLUS)
		polar += ANGLE_RIGHT * 2;
	else if (key != KEY_IMAGMINUS)
		return (false);
	move->x = UNIT_PARAM * speed * zoom * sin(ft_math_deg2rad(polar));
	move->y = UNIT_PARAM * speed * zoom * -cos(ft_math_deg2rad(polar));
	return (true);
}

int	fra_ctrl_keyhook_fire(int key, t_var *var)
{
	t_cartes	move;

	if (!ft_hasflag(var->param->event, FLAG_KEY))
		return (false);
	if (fra_ctrl_keyhook_fire_move(&move, key, \
		var->param->speed, var->param->zoom) \
		&& fra_ctrl_move(var->param, &move))
		var->param->event |= FLAG_DRAW | FLAG_PROMPT;
	else if (fra_ctrl_keyhook_fire_zoom(&move.x, key, var->param->speed) \
		&& fra_ctrl_zoom(var->param, move.x))
		var->param->event |= FLAG_DRAW | FLAG_PROMPT;
	else if (fra_ctrl_keyhook_fire_constant(&move, key, \
		var->param->speed, var->param->zoom) \
		&& fra_ctrl_param_constant(var->param, &move))
		var->param->event |= FLAG_DRAW | FLAG_PROMPT;
	else if (fra_ctrl_keyhook_fire_cycle(&move.x, key) \
		&& fra_ctrl_param_cycle(var->param, move.x))
		var->param->event |= FLAG_DRAW | FLAG_PROMPT;
	else
		return (false);
	return (true);
}
