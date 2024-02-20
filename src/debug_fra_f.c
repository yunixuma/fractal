/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_fra_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/20 20:11:45 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	debug_fra_f_polar(t_polar *polar)
{
	debug_printf("%%p: %p (", polar);
	debug_printf("r: %6.3lf, ", polar->roll);
	debug_printf("p: %6.3lf, ", polar->pitch);
	debug_printf("y: %6.3lf)\n", polar->yaw);
}

void	debug_fra_f_cartes(t_cartes *cartes)
{
	debug_printf("%%p: %p (", cartes);
	debug_printf("%6.3lf, ", cartes->x);
	debug_printf("%6.3lf, ", cartes->y);
	debug_printf("%6.3lf)\n", cartes->z);
}

void	debug_fra_f_vec(t_vec *vec)
{
	debug_printf("vec\t%%p: %p\n", vec);
	debug_printf("pos\t");
	debug_fra_f_cartes(&vec->pos);
	debug_printf("dir\t");
	debug_fra_f_cartes(&vec->dir);
}

void	debug_fra_f_vecs(t_opt *opt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < N_DIRECTION)
	{
		debug_printf("%zu(%#04x)\n", i, fra_idx2flag_direction(i));
		j = 0;
		while (opt->vecs[i][j].pos.z != VAL_INVAL)
		{
			debug_fra_f_vec(&opt->vecs[i][j]);
			j++;
		}
		i++;
	}
}
