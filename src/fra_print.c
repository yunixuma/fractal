/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/26 18:54:52 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fra_print_err(int errnum)
{
	if (errnum)
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
	ft_putstr_fd(PROMPT_WARN, STDERR_FILENO);
	if (errnum == ERR_NOARG)
		ft_putendl_fd(MSG_NOARG, STDERR_FILENO);
	else if (errnum == ERR_MANYARGS)
		ft_putendl_fd(MSG_MANYARGS, STDERR_FILENO);
	else if (errnum == ERR_INVAL)
		ft_putendl_fd(MSG_INVAL, STDERR_FILENO);
	else if (errnum == ERR_ALLOC)
		ft_putendl_fd(MSG_ALLOC, STDERR_FILENO);
	else if (errnum == ERR_NOTNUM)
		ft_putendl_fd(MSG_NOTNUM, STDERR_FILENO);
	else if (errnum == ERR_RANGE)
		ft_putendl_fd(MSG_RANGE, STDERR_FILENO);
	else if (errnum == ERR_MLX)
		ft_putendl_fd(MSG_MLX, STDERR_FILENO);
	return (errnum);
}

void	fra_print_control(void)
{
	ft_putstr_fd(MSG_HOWTO_MOVE, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_TURN, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_PARAM, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_FOCUS, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_SCROLL, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_ZOOMIN, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_ZOOMOUT, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_DEPTH, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_SPEED, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_EXIT, STDOUT_FILENO);
	ft_putendl_fd(MSG_HLINE, STDOUT_FILENO);
}

void	fra_print_status(t_param *param)
{
	const char	*cursor_mode[2] = {STR_OFF, STR_ON};

	if (ft_hasflag(param->event, FLAG_INIT))
		param->event &= ~FLAG_INIT;
	else
	{
		ft_prompt_arg(PROMPT_MOVE_UP, 1);
		ft_prompt_clr_line();
		ft_prompt_arg(PROMPT_MOVE_UP, 1);
		ft_prompt_clr_line();
	}
	printf(MSG_STATUS_POS_1, param->coord.x);
	printf(MSG_STATUS_POS_2, param->coord.y);
	printf(MSG_STATUS_PARAM_1, param->constant.x);
	printf(MSG_STATUS_PARAM_2, param->constant.y);
	printf(MSG_STATUS_MODE, cursor_mode[ft_hasflag(param->event, FLAG_CURSOR)]);
	printf(MSG_STATUS_SPEED, param->speed);
	printf(MSG_STATUS_DEPTH, param->depth);
	printf(MSG_STATUS_ZOOM, 1 / param->zoom);
}

void	fra_print_break(void)
{
	ft_putendl_fd(MSG_BREAK, STDOUT_FILENO);
}
