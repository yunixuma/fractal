/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/21 07:52:31 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	fra_print_err_sub(int errnum)
{
	if (errnum == ERR_NOTNUM)
		ft_putendl_fd(MSG_NOTNUM, STDERR_FILENO);
	else if (errnum == ERR_RANGE)
		ft_putendl_fd(MSG_RANGE, STDERR_FILENO);
	else if (errnum == ERR_MANYVALS)
		ft_putendl_fd(MSG_NODEF, STDERR_FILENO);
	else if (errnum == ERR_NODEF)
		ft_putendl_fd(MSG_MANYVALS, STDERR_FILENO);
	else if (errnum == ERR_EMPTY)
		ft_putendl_fd(MSG_EMPTY, STDERR_FILENO);
	else if (errnum == ERR_CHR)
		ft_putendl_fd(MSG_CHR, STDERR_FILENO);
	else if (errnum == ERR_COUNT)
		ft_putendl_fd(MSG_COUNT, STDERR_FILENO);
	else if (errnum == ERR_OUTER)
		ft_putendl_fd(MSG_OUTER, STDERR_FILENO);
	else if (errnum == ERR_MLX)
		ft_putendl_fd(MSG_MLX, STDERR_FILENO);
	return (errnum);
}

//	else if (errnum == ERR_SHAPE)
//		ft_putendl_fd(MSG_SHAPE, STDERR_FILENO);
//	else if (errnum == ERR_PATH)
//		ft_putendl_fd(MSG_PATH, STDERR_FILENO);
//	else if (errnum == ERR_HUGE)
//		ft_putendl_fd(MSG_HUGE, STDERR_FILENO);

int	fra_print_err(int errnum)
{
	if (errnum)
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
	ft_putstr_fd(PROMPT_WARN, STDERR_FILENO);
	if (errnum == ERR_NOARG)
		ft_putendl_fd(MSG_NOARG, STDERR_FILENO);
	else if (errnum == ERR_MANYARGS)
		ft_putendl_fd(MSG_MANYARGS, STDERR_FILENO);
	else if (errnum == ERR_FEXT)
		ft_putendl_fd(MSG_FEXT, STDERR_FILENO);
	else if (errnum == ERR_FPATH)
		ft_putendl_fd(MSG_FPATH, STDERR_FILENO);
	else if (errnum == ERR_OPEN)
		ft_putendl_fd(MSG_OPEN, STDERR_FILENO);
	else if (errnum == ERR_ALLOC)
		ft_putendl_fd(MSG_ALLOC, STDERR_FILENO);
	else if (errnum == ERR_ID)
		ft_putendl_fd(MSG_ID, STDERR_FILENO);
	else if (errnum == ERR_DUP)
		ft_putendl_fd(MSG_DUP, STDERR_FILENO);
	else
		fra_print_err_sub(errnum);
	return (errnum);
}

void	fra_print_control(void)
{
	ft_putstr_fd(MSG_HOWTO_MOVE, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_TURN, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_FOCUS, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_SCROLL, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_ZOOMIN, STDOUT_FILENO);
	ft_putstr_fd(MSG_HOWTO_ZOOMOUT, STDOUT_FILENO);
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
	printf(MSG_STATUS_SPEED, param->speed);
	printf(MSG_STATUS_ZOOM, param->zoom);
	printf(MSG_STATUS_MODE, cursor_mode[ft_hasflag(param->event, FLAG_CURSOR)]);
}

void	fra_print_break(void)
{
	ft_putendl_fd(MSG_BREAK, STDOUT_FILENO);
}

/*
void	fra_print_score(int score)
{
	printf(MSG_SCORE, score);
}
*/
/*
void	fra_print_goal(int score)
{
	printf(MSG_GOAL, score);
}
*/