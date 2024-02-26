/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/26 18:28:31 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "fractal_math.h"
# include "mlx.h"
# include "libftprintf.h"
# include "ft_prompt.h"
# include "fractal_string.h"
# include "fractal_const.h"
/*# ifdef __MACH__
#  include "fractal_event_mac.h"
# else*/
# include "fractal_event.h"
//# endif
# include "fractal_typedef.h"
# ifdef DEBUG_MODE
#  include "debug_fractal.h"
# endif

int		main(int argc, char *argv[]);
int		fra_setparam(t_param *param, int argc, char *argv[]);
int		fra_mlx_init(t_var *var);
int		fra_mlx_loop(t_var *var);
int		fra_mlx_hook(t_var *var);
int		fra_win_init(t_var *var);
int		fra_win_draw_vision(t_var *var);
void	fra_win_draw_pixel(t_var *var, int x, int y, int color);
void	fra_win_destroy(t_var *var);
int		fra_img_init(t_var *var);
void	fra_img_clear(t_img *img, int color_code, int width, int height);
void	fra_img_destroy(t_var *var);
void	fra_render_background(t_var *var);
void	fra_render_fractal(t_var *var);
void	fra_render_blend(t_img *img_dst, t_img *img_src, t_addr *zero);
void	fra_render_pixel(t_img *img, int color_code, t_addr *pixel);
void	fra_render_line(t_img *img, int color_code, \
	t_addr *zero, t_polar *line);
void	fra_render_rectangle(t_img *img, int color_code, \
	t_addr *zero, t_addr *area);
void	fra_render_imgpixel(t_img *img_dst, t_img *img_src, \
	t_addr *dst, t_addr *src);
void	fra_render_imgline(t_img *img_dst, t_img *img_src, \
	t_addr *dst, t_addr *src);
int		fra_calc_mandelbrot(t_cartes c, t_cartes z, int cycle);
int		fra_calc_julia(t_cartes z, t_cartes c, int cycle);
int		fra_calc_burningship(t_cartes c, t_cartes z, int cycle);
int		fra_calc_newton(t_cartes z, t_cartes c, int cycle);
int		fra_calc_sierpinski(t_cartes z, int cycle);
void	fra_ctrl_init(t_param *param);
int		fra_ctrl_keyhook_down(int key, t_var *var);
int		fra_ctrl_keyhook_up(int key, t_var *var);
int		fra_ctrl_keyhook_fire(int key, t_var *var);
int		fra_ctrl_cursorhook(int x, int y, t_var *var);
int		fra_ctrl_clickhook(int button, int x, int y, t_var *var);
int		fra_ctrl_clickhook_up(int button, int x, int y, t_var *var);
bool	fra_ctrl_move(t_param *param, t_cartes *move);
bool	fra_ctrl_constant(t_param *param, t_cartes *move);
bool	fra_ctrl_speed(t_param *param);
bool	fra_ctrl_zoom(t_param *param, double zoom_add);
bool	fra_ctrl_cursormode(t_param *param);
bool	fra_ctrl_param_constant(t_param *param, t_cartes *move);
bool	fra_ctrl_param_cycle(t_param *param, double ratio);
int		fra_exit(int errnum);
int		fra_exit_mlx(t_var *var, int errnum);
int		fra_exit_mlx_break(t_var *var);
int		fra_print_err(int errnum);
void	fra_print_control(void);
void	fra_print_status(t_param *param);
void	fra_print_break(void);
char	fra_idx2flag_direction(size_t idx);
int		ft_seterr(int errnum);
int		ft_seterr_return(int ret, int errnum);
void	*ft_seterr_null(int errnum);
void	*ft_free(void **p);
void	*ft_free_seterr(void **p, int errnum);
void	*ft_lstclear_seterr(t_list **lst, void (*del)(void*), int errnum);
int		ft_hasflag(int val, int flag);
bool	ft_stris(const char *str, int (*f)(int));
void	ft_cartes_init(t_cartes *pt);
void	ft_cartes_set(t_cartes *pt, double x, double y);
void	ft_cartes_copy(t_cartes *dst, t_cartes *src);
void	ft_addr_set(t_addr *addr, ssize_t x, ssize_t y);
bool	ft_inrange_dbl(double nb, double lower, double upper);
float	ft_atof(const char *str);
int		ft_color_rgb2code(int red, int green, int blue);
int		ft_color_hsv2code(int hue, int chr, int bri);

#endif
