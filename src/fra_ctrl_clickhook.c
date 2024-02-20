/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_param_clickhook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/20 20:37:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static bool	fra_ctrl_clickhook_focus(t_cartes *coord, int button, \
	t_addr *cursor, t_param *param)
{
	if (button != BUTTON_FOCUS)
		return (false);
	coord->x = (cursor->x - WIDTH_VISION / 2) * param->speed / param->zoom;
	coord->y = (cursor->y - HEIGHT_VISION / 2) * param->speed / param->zoom;
//DD(turn->yaw);
//DD(turn->pitch);
	if (coord->x == 0 && coord->y == 0)
		return (false);
	return (true);
}

static bool	fra_ctrl_clickhook_zoom(double *zoom, int key, int speed)
{
	*zoom = 1;
	if (key == KEY_WIDE)
		*zoom = UNIT_ZOOM * speed;
	else if (key == KEY_TELE)
		*zoom /= (UNIT_ZOOM * speed);
	else
		return (false);
	return (true);
}

/*
int	fra_ctrl_clickhook_up(int button, int x, int y, t_var *var)
{
debug_printf("up\tcursor(%d, %d)\tbutton: %d\n", x, y, button);
	var->param->cursor.x = x;
	var->param->cursor.y = y;
	var->param->event &= ~FLAG_CLICK;
	return (ERR_NOERR);
}
*/

int	fra_ctrl_clickhook(int button, int x, int y, t_var *var)
{
	t_cartes	coord;
	t_addr		cursor;

	ft_addr_set(&cursor, x, y);
//debug_printf("down\tcursor(%d, %d)\tbutton: %d\n", x, y, button);
	if (fra_ctrl_clickhook_focus(&coord, button, &cursor, var->param) \
		&& fra_ctrl_move(var, &coord))
		var->param->event |= FLAG_DRAW | FLAG_PROMPT;
	else if (fra_ctrl_clickhook_zoom(&coord.x, button, var->param->speed) \
		&& fra_ctrl_zoom(var->param, coord.x))
		var->param->event |= FLAG_DRAW | FLAG_PROMPT;
	else if (button == BUTTON_SPEED \
		&& fra_ctrl_speed(var->param))
		var->param->event |= FLAG_PROMPT;
	var->param->cursor.x = x;
	var->param->cursor.y = y;
	if (button == BUTTON_CURSOR && fra_ctrl_cursormode(var->param))
		var->param->event |= FLAG_PROMPT;
	else
		var->param->event |= FLAG_CLICK;
	return (true);
}
