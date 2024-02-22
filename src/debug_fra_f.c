/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_fra_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/22 09:04:54 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	debug_fra_f_cartes(t_cartes *cartes)
{
	debug_printf("%%p: %p (", cartes);
	debug_printf("%6.3lf, ", cartes->x);
	debug_printf("%6.3lf, ", cartes->y);
}

void	debug_fra_f_vec(t_vec *vec)
{
	debug_printf("vec\t%%p: %p\n", vec);
	debug_printf("pos\t");
	debug_fra_f_cartes(&vec->pos);
	// debug_printf("dir\t");
	// debug_fra_f_cartes(&vec->dir);
}
