/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_typedef.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/23 15:25:01 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_TYPEDEF_H
# define FRACTAL_TYPEDEF_H

# include <unistd.h>
# include "fractal_const.h"

typedef struct s_addr
{
	ssize_t	x;
	ssize_t	y;
}	t_addr;

typedef struct s_cartes
{
	double	x;
	double	y;
}	t_cartes;

typedef struct s_polar
{
	double	radius;
	double	angle;
}	t_polar;

typedef struct s_vec
{
	t_cartes	pos;
	t_polar		dir;
}	t_vec;

typedef union u_color
{
	unsigned int	code;
	unsigned char	ch[N_CHANNEL];
}	t_color;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		len;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_param
{
	int			type;
	int			color[N_PALETTE];
	double		zoom;
	t_cartes	coord;
	t_cartes	constant;
	int			event;
	int			key;
	t_addr		cursor;
	int			speed;
	char		*title;
}	t_param;

typedef struct s_var
{
	void	*conn;
	void	*win;
	t_img	img[N_IMAGE];
	t_param	*param;
}	t_var;

#endif
