/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_const.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/21 00:31:59 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_CONST_H
# define FRACTAL_CONST_H

# include <stdint.h>
# include <errno.h>

# define OFFSET_ARG			1
# define IDX_ARG			1
# define LEN_MAXPATH		255
# define BITS_CHANNEL		8
# define MASK_CHANNEL		0xff
# define ERR_NOERR			0
# define ERR_NOARG			EISDIR
# define ERR_MANYARGS		E2BIG
# define ERR_FEXT			ENOEXEC
# define ERR_FPATH			ENAMETOOLONG
# define ERR_OPEN			ENOENT
# define ERR_ALLOC			ENOMEM
# define ERR_ID				EFAULT
# define ERR_DUP			EEXIST
# define ERR_NOTNUM			EDOM
# define ERR_RANGE			ERANGE
# define ERR_MANYVALS		EOVERFLOW
# define ERR_NODEF			ENXIO
# define ERR_EMPTY			ENODATA
# define ERR_CHR			EINVAL
# define ERR_COUNT			EMLINK
# define ERR_OUTER			EILSEQ
//# define ERR_SHAPE			EMSGSIZE
//# define ERR_PATH			EHOSTUNREACH
# define ERR_MLX			EBUSY
//# define ERR_HUGE			EFBIG
# define TYPE_MANDELBROT	1
# define TYPE_JULIA			2

# define UNIT_MOVE			0.03125
# define UNIT_ZOOM			1.4142135623730950488016887242097
# define ANGLE_RIGHT		90.
# define ANGLE_FOV			90.
# define ANGLE_FOV_MAX		108.
# define ANGLE_FOV_MIN		72.
# define WIDTH_VISION		640
# define HEIGHT_VISION		480
# define ZERO_VISION		0
# define HEIGHT_SIGHT		0.5
# define WIDTH_BLOCK		120
# define HEIGHT_BLOCK		120
# define SIZE_CELL			12
# define LEN_POS			2
# define RATIO_HUD			3
# define WEIGHT_FRAME		2
# define UNIT_SPEED			1
# define MAX_SPEED			16
# define FLAG_NOEVENT		0x00
# define FLAG_INIT			0x01
# define FLAG_PROMPT		0x02
# define FLAG_DRAW			0x04
# define FLAG_KEY			0x20
# define FLAG_CURSOR		0x40
# define FLAG_CLICK			0x80

typedef enum e_channel
{
	IDX_ALPHA = 0,
	IDX_RED = 1,
	IDX_GREEN = 2,
	IDX_BLUE = 3,
	N_CHANNEL = 4
}	t_channel;

# define IDX_BG				0
# define N_COLOR			4
# define COLOR_BG			0x000000
# define COLOR_1			0x00ff00
# define COLOR_2			0xff0000
# define COLOR_3			0x0000ff
# define COLOR_4			0xffff00
# define COLOR_5			0xff00ff
# define COLOR_6			0x00ffff
# define COLOR_7			0x7f7f7f

# define N_DIRECTION		IDX_FREE
# define N_TEXTURE			N_DIRECTION

typedef enum e_imgidx
{
	IDX_VISION = 0,
	N_IMAGE = 1
}	t_imgidx;

# define INVAL_FILENO		-1
# define VAL_INVAL			-1
# define CHR_DIR			'/'
# define CHR_SEP			','
# define CHR_SPACE			' '
# define COLOR_SPACE		0x7f000000
# define COLOR_WALL			0x3f00007f
# define COLOR_FREE			0x3fffffff
# define COLOR_POS			0x3fff0000
# define COLOR_FRAME		0x3f00ff00

# define FLAG_CHECKED		0x80
# define SIZE_NULL			0
# define POS_NOEXIST		-1
# define SIZE_TILE			64
# define SIZE_TILE_SMALL	32
# define SIZE_FRAME_SIDE	4
# define SIZE_FRAME_END		28
# define COLOR_OBJ			0x00FF0000

#endif