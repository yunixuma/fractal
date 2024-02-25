/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_const.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/25 13:56:03 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_CONST_H
# define FRACTAL_CONST_H

# include <stdint.h>
# include <errno.h>

# define OFFSET_ARG			1
# define BITS_CHANNEL		8
# define ERR_NOERR			0
# define ERR_NOARG			EISDIR
# define ERR_MANYARGS		E2BIG
# define ERR_ALLOC			ENOMEM
# define ERR_NOTNUM			EDOM
# define ERR_RANGE			ERANGE
# define ERR_MANYVALS		EOVERFLOW
# define ERR_NODEF			ENXIO
# define ERR_EMPTY			ENODATA
# define ERR_MLX			EBUSY
# define TYPE_MANDELBROT	1
# define TYPE_JULIA			2

# define UNIT_MOVE			16.
# define UNIT_ZOOM			1.0905077326652576592070106557606
# define UNIT_CYCLE			2
# define UNIT_PARAM			0.1
# define ANGLE_RIGHT		90.
# define ZOOM_DEFAULT		0.01
# define ZOOM_MAX			2.56
# define ZOOM_MIN			0.0000000000000090949470177292823755
# define CYCLE_DEFAULT		256
# define CYCLE_MAX			4096
# define CYCLE_MIN			1
# define WIDTH_VISION		800
# define HEIGHT_VISION		600
# define ZERO_VISION		0
# define LIMIT_SIZE			4
# define UNIT_SPEED			1
# define MAX_SPEED			16
# define FLAG_NOEVENT		0x00
# define FLAG_INIT			0x01
# define FLAG_PROMPT		0x02
# define FLAG_DRAW			0x04
# define FLAG_KEY			0x20
# define FLAG_CURSOR		0x40
# define FLAG_CLICK			0x80

typedef enum e_arg
{
	IDX_ARG_TYPE	= 1,
	IDX_ARG_CX		= 2,
	IDX_ARG_CY		= 3
}	t_arg;

typedef enum e_channel
{
	IDX_ALPHA = 0,
	IDX_RED = 1,
	IDX_GREEN = 2,
	IDX_BLUE = 3,
	N_CHANNEL = 4
}	t_channel;

# define IDX_BG				0
# define N_COLOR			15

typedef enum e_pallete
{
	COLOR_BG	= 0x000000,
	COLOR_1		= 0x00ff00,
	COLOR_2		= 0xff0000,
	COLOR_3		= 0x0000ff,
	COLOR_4		= 0xffff00,
	COLOR_5		= 0xff00ff,
	COLOR_6		= 0x00ffff,
	COLOR_7		= 0x7f7f7f
}	t_palette;

typedef enum e_imgidx
{
	IDX_VISION = 0,
	N_IMAGE = 1
}	t_imgidx;

# define INVAL_FILENO		-1
# define VAL_INVAL			-1

# define SIZE_NULL			0
# define POS_NOEXIST		-1

#endif
