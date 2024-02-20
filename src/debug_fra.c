/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_fra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/21 00:12:48 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_fractal.h"

void	debug_fra_lst(t_list *lst)
{
	t_list	*ele;
	int		i;
	int		size;

	if (DEBUG_MODE == 0)
		return ;
	size = ft_lstsize(lst);
	ele = lst;
	dprintf(FD_DEBUG, "lst\t%%p: %p\tsize: %3d\n", ele, size);
	i = 0;
	while (ele != NULL && i < size)
	{
		dprintf(FD_DEBUG, "%3d\t", i);
		dprintf(FD_DEBUG, "%%p: %p\t", ele);
		dprintf(FD_DEBUG, "content: %s\t", (char *)ele->content);
		dprintf(FD_DEBUG, "next: %p\n", ele->next);
		ele = ele->next;
		i++;
	}
}

void	debug_fra_ctrl(t_param *param)
{
	dprintf(FD_DEBUG, "param.\t");
	dprintf(FD_DEBUG, "x: % 7.3lf\t", param->cartes.x);
	dprintf(FD_DEBUG, "y: % 7.3lf\t", param->cartes.y);
	dprintf(FD_DEBUG, "z: % 7.3lf\n", param->cartes.z);
	dprintf(FD_DEBUG, "     \t");
	dprintf(FD_DEBUG, "yaw: % 6.1lf\t", param->polar.yaw);
	dprintf(FD_DEBUG, "pitch: % 6.1lf\t", param->polar.pitch);
	dprintf(FD_DEBUG, "roll: % 6.1lf\n", param->polar.roll);
	dprintf(FD_DEBUG, "     \t");
	dprintf(FD_DEBUG, "zoom: %lf\t", param->zoom);
	dprintf(FD_DEBUG, "key: %d\t", param->event);
//	dprintf(FD_DEBUG, "score: %d\n", param->score);
}

void	debug_fra_countchr(int *arr)
{
	ssize_t	size;
	ssize_t	i;

	if (DEBUG_MODE == 0)
		return ;
	if (arr == NULL)
		return ;
	size = SIZE_CHRS_MAP;
	dprintf(FD_DEBUG, "counts\t%%p: %p\tsize: %zd\n", arr, size);
	i = 0;
	while (i < size)
	{
		dprintf(FD_DEBUG, "%3zd\t", i);
		dprintf(FD_DEBUG, "count: %d\n", arr[i]);
		i++;
	}
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
	while (i < N_TEXTURE)
	{
		dprintf(FD_DEBUG, "path\t%3zd\t", i);
		dprintf(FD_DEBUG, "%%p: %p\t{%s}\n", param->path[i], param->path[i]);
		i++;
	}
	i = 0;
	while (i < N_COLOR)
	{
		dprintf(FD_DEBUG, "color\t%3zd\t%#x\n", i, param->color[i]);
		i++;
	}
}
