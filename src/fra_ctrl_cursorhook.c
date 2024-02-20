/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_ctrl_cursorhook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/21 01:12:05 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static bool	fra_ctrl_cursorhook_move(t_cartes *move, \
	t_addr *new, t_addr *old, t_param *param)
{
	move->x = 0;
	move->y = 0;
	if (new->x < old->x)
		move->x = -UNIT_MOVE * param->speed / param->zoom;
	else if (new->x > old->x && old->x > VAL_INVAL)
		move->x = UNIT_MOVE * param->speed / param->zoom;
	if (new->y < old->y)
		move->y = UNIT_MOVE * param->speed / param->zoom;
	else if (new->y > old->y && old->y > VAL_INVAL)
		move->y = -UNIT_MOVE * param->speed / param->zoom;
	if (move->x == 0 && move->y == 0)
		return (false);
	return (true);
}

int	fra_ctrl_cursorhook(int x, int y, t_var *var)
{
	t_cartes	move;
	t_addr		new;

	if (!ft_hasflag(var->param->event, FLAG_CURSOR))
		return (false);
//debug_printf("cursor(%d, %d)\n", x, y);
	ft_addr_set(&new, x, y);
	if (fra_ctrl_cursorhook_move(&move, &new, \
		&var->param->cursor, var->param) \
		&& fra_ctrl_move(var, &move))
		var->param->event |= FLAG_DRAW | FLAG_PROMPT;
	var->param->cursor.x = x;
	var->param->cursor.y = y;
	return (true);
}
