/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_param_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/20 20:35:56 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	fra_param_setcolor(t_param *param)
{
	size_t	i;

	i = 0;
	while (i < N_COLOR)
	{
		param->color[i] = ft_color_hsv2code(360 * i / N_COLOR, 0xff, 0xff);
		i++;
	}
	// param->color[i++] = COLOR_1;
	// param->color[i++] = COLOR_2;
	// param->color[i++] = COLOR_3;
	// param->color[i++] = COLOR_4;
	// param->color[i++] = COLOR_5;
	// param->color[i++] = COLOR_6;
	// param->color[i++] = COLOR_7;
}

int	fra_param_init(t_param *param, int argc, char *argv[])
{
	char	*arg;

	if (argc < OFFSET_ARG + IDX_ARG_TYPE)
		return (fra_print_err(ERR_NOARG));
	if (argc > OFFSET_ARG + IDX_ARG_CY)
		return (fra_print_err(ERR_MANYARGS));
	arg = ft_strdup(argv[IDX_ARG_TYPE]);
	if (arg == NULL)
		return (fra_print_err(ERR_ALLOC));
	prf_strtoupper(arg);
	if (ft_strncmp(arg, STR_MANDELBROT, ft_strlen(arg) + 1) == 0)
		param->type = TYPE_MANDELBROT;
	else if (ft_strncmp(arg, STR_JULIA, ft_strlen(arg) + 1) == 0)
	{
		param->type = TYPE_JULIA;
		if (argc < OFFSET_ARG + IDX_ARG_CY)
			ft_cartes_set(&param->constant, 0, 0);
		else
			ft_cartes_set(&param->constant, \
				ft_atof(argv[IDX_ARG_CX]), ft_atof(argv[IDX_ARG_CY]));
	}
	fra_param_setcolor(param);
	param->zoom = ZOOM_DEFAULT;
	param->coord.x = 0;
	param->coord.y = 0;
	param->event = FLAG_INIT;
	param->key = KEY_NONE;
	ft_addr_set(&param->cursor, VAL_INVAL, VAL_INVAL);
	param->speed = UNIT_SPEED;
	param->title = argv[IDX_ARG_TYPE];
	return (ERR_NOERR);
}
