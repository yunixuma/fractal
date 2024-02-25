/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_ctrl_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/25 13:01:17 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

bool	fra_ctrl_param_constant(t_param *param, t_cartes *move)
{
	param->constant.y += move->y;
	param->constant.x += move->x;
	return (true);
}

bool	fra_ctrl_param_cycle(t_param *param, double ratio)
{
	int	cycle_bak;

	cycle_bak = param->cycle;
	param->cycle *= ratio;
	if (param->cycle > CYCLE_MAX)
		param->cycle = CYCLE_MAX;
	else if (param->cycle < CYCLE_MIN)
		param->cycle = CYCLE_MIN;
	if (param->cycle == cycle_bak)
		return (false);
	return (true);
}
