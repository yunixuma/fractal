/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_ctrl_clickhook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/26 18:58:16 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static bool	fra_ctrl_clickhook_focus(t_cartes *coord, int button, \
	t_param *param)
{
	if (button != BUTTON_FOCUS)
		return (false);
	coord->x = (-param->cursor.x + WIDTH_VISION / 2) * param->zoom;
	coord->y = (-param->cursor.y + HEIGHT_VISION / 2) * param->zoom;
	if (coord->x == 0 && coord->y == 0)
		return (false);
	return (true);
}

static bool	fra_ctrl_clickhook_zoom(t_cartes *coord, double *ratio, int key, \
	t_param *param)
{
	*ratio = 1;
	if (key == BUTTON_WIDE)
		*ratio = UNIT_ZOOM * param->speed;
	else if (key == BUTTON_TELE)
		*ratio /= (UNIT_ZOOM * param->speed);
	else
		return (false);
	coord->x = (-param->cursor.x + WIDTH_VISION / 2) * param->zoom;
	coord->y = (-param->cursor.y + HEIGHT_VISION / 2) * param->zoom;
	coord->x -= (-param->cursor.x + WIDTH_VISION / 2) * param->zoom * *ratio;
	coord->y -= (-param->cursor.y + HEIGHT_VISION / 2) * param->zoom * *ratio;
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
	double		ratio;

	ft_addr_set(&var->param->cursor, x, y);
//debug_printf("down\tcursor(%d, %d)\tbutton: %d\n", x, y, button);
	if (fra_ctrl_clickhook_focus(&coord, button, var->param) \
		&& fra_ctrl_move(var->param, &coord))
		var->param->event |= FLAG_DRAW | FLAG_PROMPT;
/*	else if (fra_ctrl_clickhook_zoom(&ratio, button, var->param->speed) \
		&& fra_ctrl_zoom(var->param, ratio))
		var->param->event |= FLAG_DRAW | FLAG_PROMPT;*/
	else if (fra_ctrl_clickhook_zoom(&coord, &ratio, button, var->param) \
		&& fra_ctrl_zoom(var->param, ratio) \
		&& fra_ctrl_move(var->param, &coord))
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
