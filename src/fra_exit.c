/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/20 23:19:22 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fra_exit(int errnum)
{
	if (errnum != ERR_NOERR)
		fra_print_err(errnum);
	exit(errnum);
}

int	fra_exit_mlx(t_var *var, int errnum)
{
	if (var != NULL)
	{
		fra_img_destroy(var);
		fra_win_destroy(var);
	}
	return (fra_exit(errnum));
}

int	fra_exit_mlx_break(t_var *var)
{
	fra_print_break();
	return (fra_exit_mlx(var, ERR_NOERR));
}
