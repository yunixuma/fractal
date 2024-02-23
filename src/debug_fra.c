/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_fra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/23 15:16:06 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_fractal.h"

void	debug_fra_ctrl(t_param *param)
{
	dprintf(FD_DEBUG, "param.\t");
	dprintf(FD_DEBUG, "x: % 7.3lf\t", param->coord.x);
	dprintf(FD_DEBUG, "y: % 7.3lf\t", param->coord.y);
	dprintf(FD_DEBUG, "     \t");
	dprintf(FD_DEBUG, "zoom: %lf\t", param->zoom);
	dprintf(FD_DEBUG, "key: %d\t", param->event);
//	dprintf(FD_DEBUG, "score: %d\n", param->score);
}

void	debug_fra_param(t_param *param)
{
	ssize_t	i;

	if (DEBUG_MODE == 0)
		return ;
	if (param == NULL)
		return ;
	dprintf(FD_DEBUG, "param\t%%p: %p\n", param);
	i = 0;
	while (i < N_PALLETE)
	{
		dprintf(FD_DEBUG, "color\t%3zd\t%#x\n", i, param->color[i]);
		i++;
	}
}
