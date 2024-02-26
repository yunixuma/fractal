/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cartes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/26 18:56:33 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_cartes_init(t_cartes *pt)
{
	if (!pt)
		return ;
	pt->x = 0;
	pt->y = 0;
}

void	ft_cartes_set(t_cartes *pt, double x, double y)
{
	if (!pt)
		return ;
	pt->x = x;
	pt->y = y;
}

void	ft_cartes_copy(t_cartes *dst, t_cartes *src)
{
	if (!dst)
		return ;
	if (!src)
		ft_cartes_init(dst);
	dst->x = src->x;
	dst->y = src->y;
}
