/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_fractal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/22 08:55:18 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_FRACTAL_H
# define DEBUG_FRACTAL_H

# include "libft.h"
# include "debug_common.h"
# include "fractal_const.h"
# include "fractal_typedef.h"

void	debug_fra_ctrl(t_param *param);
void	debug_fra_param(t_param *param);
void	debug_fra_img(t_img img, int size_tile);
void	debug_fra_f_cartes(t_cartes *cartes);
void	debug_fra_f_vec(t_vec *vec);

#endif
