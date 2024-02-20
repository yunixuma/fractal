/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_fractal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/20 20:42:03 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_FRACTAL_H
# define DEBUG_FRACTAL_H

# include "libft.h"
# include "debug_common.h"
# include "fractal_const.h"
# include "fractal_typedef.h"

void	debug_fra_lst(t_list *lst);
void	debug_fra_ctrl(t_param *param);
void	debug_fra_param(t_param *param);
void	debug_fra_countchr(int *arr);
void	debug_fra_map_raw(char **map);
void	debug_fra_map_flag(char **map);
void	debug_fra_img(t_img img, int size_tile);
void	debug_fra_f_polar(t_polar *polar);
void	debug_fra_f_cartes(t_cartes *cartes);
void	debug_fra_f_vec(t_vec *vec);

#endif
