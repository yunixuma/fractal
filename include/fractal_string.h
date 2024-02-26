/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_string.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/26 18:22:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_STRING_H
# define FRACTAL_STRING_H

# define STR_EMPTY			""
# define STR_MANDELBROT		"MANDELBROT"
# define STR_JULIA			"JULIA"
# define STR_BURNINGSHIP	"BURNINGSHIP"
# define STR_NEWTON			"NEWTON"
# define STR_SIERPINSKI		"SIERPINSKI"
# define STR_TITLE			"fract-ol"
# define STR_ON				"\033[43m ON  \033[49m"
# define STR_OFF			"\033[44m OFF \033[49m"

# define MSG_ERR			"\033[1;31mError\033[0m"
# define MSG_NOARG			"Missing the argument to specify a type of fractal"
# define MSG_MANYARGS		"Please specify only one or three argument"
# define MSG_ALLOC			"An error occured during allocating memory"
# define MSG_NOTNUM			"Value must be a numeric"
# define MSG_RANGE			"Value is out of range"
# define MSG_INVAL			"./fractal [mandelbrot/julia] [cx] [cy]"
# define MSG_MLX			"An error occured during initiate a X-Window I/F"
# define MSG_WAIT_WIN		"Wait a moment for creating the window..."
# define MSG_WAIT_CALC		"\033[33mCalculating...\033[39m"
# define MSG_HOWTO_MOVE		"Move: \033[1m[Up][Left][Down][Right]\033[0m\t"
# define MSG_HOWTO_TURN		"Turn: \033[1m[Z][X]\033[0m\n"
# define MSG_HOWTO_PARAM	"Move: \033[1m[D][A][W][S]\033[0m\t"
# define MSG_HOWTO_FOCUS	"Focus: \033[1m[LeftClick]\033[0m\t"
# define MSG_HOWTO_SCROLL	"Cursor: \033[1m[C][MidClick]\033[0m\n"
# define MSG_HOWTO_ZOOMIN	"Zoom-in: \033[1m[PgUp][ScrUp]\033[0m\t"
# define MSG_HOWTO_ZOOMOUT	"Zoom-out: \033[1m[PgDn][ScrDn]\033[0m\n"
# define MSG_HOWTO_SPEED	"Change Speed: \033[1m[F][RightClick]\033[0m\t"
# define MSG_HOWTO_CYCLE	"Calc. Cycle: \033[1m[E][R]\033[0m\n"
# define MSG_HOWTO_EXIT		"Exit: \033[1m[Q]\033[0m or \033[1m[Esc]\033[0m\n"
# define MSG_HLINE			"\033[2m--------------------------------------\033[0m"
# define MSG_STATUS_POS_1	"Coord: (\033[4;32m%lf\033[0m, "
# define MSG_STATUS_POS_2	"\033[4;32m%lf\033[0m)\t"
# define MSG_STATUS_PARAM_1	"Constant: (\033[4;32m%lf\033[0m"
# define MSG_STATUS_PARAM_2	" + \033[4;32m%lf\033[0m i)\n"
# define MSG_STATUS_MODE	"Cursor: \033[1m%s\033[0m\t"
# define MSG_STATUS_SPEED	"Speed: \033[1;32;46m %d \033[0m\t"
# define MSG_STATUS_CYCLE	"Cycle: \033[4;32m%5d\033[0m\t"
# define MSG_STATUS_ZOOM	"Zoom: \033[4;32m%6.3lf%%\033[0m\n"
# define MSG_BREAK			"\033[33mTerminated by player's operation\033[39m"

#endif
