/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_ctrl_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/03 15:36:13 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

bool	fra_ctrl_param_constant(t_param *param, t_cartes *move)
{
	param->constant.y += move->y;
	param->constant.x += move->x;
	return (true);
}

bool	fra_ctrl_param_depth(t_param *param, double ratio)
{
	int	depth_bak;

	depth_bak = param->depth;
	param->depth *= ratio;
	if (param->depth > DEPTH_MAX)
		param->depth = DEPTH_MAX;
	else if (param->depth < DEPTH_MIN)
		param->depth = DEPTH_MIN;
	if (param->depth == depth_bak)
		return (false);
	return (true);
}
