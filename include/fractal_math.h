/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_math.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/21 01:21:01 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_MATH_H
# define FRACTAL_MATH_H

# define _USE_MATH_DEFINES

# include <math.h>
# include <stdbool.h>
# include "fractal_typedef.h"

# ifndef M_PI
#  define M_PI	3.141592653589793
# endif

double	ft_math_deg2rad(double deg);
double	ft_math_rad2deg(double rad);
double	ft_math_angle_normalize(double polar);
double	ft_math_distance_2d(t_cartes *pt1, t_cartes *pt2);

#endif
