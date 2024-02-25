/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_ctrl_keyhook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/26 08:20:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fra_ctrl_keyhook_down(int key, t_var *var)
{
//debug_printf("key: %04x\n", key);
	var->param->key = key;
	var->param->event |= FLAG_KEY;
	return (true);
}

int	fra_ctrl_keyhook_up(int key, t_var *var)
{
	if (key == KEY_EXIT_1 || key == KEY_EXIT_2)
		return (fra_exit_mlx_break(var));
	else if (key == KEY_CURSOR && fra_ctrl_cursormode(var->param))
		var->param->event |= FLAG_PROMPT;
	else if (key == KEY_SPEED \
		&& fra_ctrl_speed(var->param))
		var->param->event |= FLAG_PROMPT;
	if (key != var->param->key)
		return (false);
	var->param->key = KEY_NONE;
//	if (key != KEY_CURSOR && key != KEY_SPEED)
	var->param->event &= ~FLAG_KEY;
	return (true);
}
