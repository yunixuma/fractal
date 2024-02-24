/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/24 14:26:31 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	fra_main_mlx(t_param *param)
{
	t_var	var;

	var.param = param;
	if (fra_mlx_init(&var))
		return (errno);
	ft_putendl_fd(MSG_WAIT, STDOUT_FILENO);
	if (fra_win_init(&var))
		return (fra_exit_mlx(&var, errno));
	if (fra_img_init(&var))
		return (fra_exit_mlx(&var, errno));
	fra_win_draw_vision(&var);
	fra_print_control();
	fra_print_status(var.param);
	return (fra_mlx_loop(&var));
}

int	main(int argc, char *argv[])
{
	t_param	param;
	int		errnum;

	errnum = fra_setparam(&param, argc, argv);
	if (errnum)
		return (fra_print_err(errnum));
	fra_main_mlx(&param);
	return (ERR_NOERR);
}
