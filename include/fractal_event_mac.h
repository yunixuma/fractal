/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_event_mac.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/25 14:04:36 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_EVENT_MAC_H
# define FRACTAL_EVENT_MAC_H

# define EVENT_KEYDOWN		2
# define EVENT_EXPOSE		12
# define EVENT_DESTROY		17
# define MASK_STRUCT		1

# define KEYCODE_Q			0x0c
# define KEYCODE_W			0x0d
# define KEYCODE_E			0x0d
# define KEYCODE_R			0x0e
# define KEYCODE_A			0x00
# define KEYCODE_S			0x01
# define KEYCODE_D			0x02
# define KEYCODE_F			0x03
# define KEYCODE_Z			0x18
# define KEYCODE_X			0x19
# define KEYCODE_C			0x1a
# define KEYCODE_UP			0x7e
# define KEYCODE_LEFT		0x7b
# define KEYCODE_DOWN		0x7d
# define KEYCODE_RIGHT		0x7c
# define KEYCODE_PAGEUP		0x74
# define KEYCODE_PAGEDOWN	0x79
# define KEYCODE_ESC		0x35
# define KEY_EXIT_1			KEYCODE_ESC
# define KEY_EXIT_2			KEYCODE_Q
# define KEY_MOVEUP			KEYCODE_UP
# define KEY_MOVEDOWN		KEYCODE_DOWN
# define KEY_MOVELEFT		KEYCODE_LEFT
# define KEY_MOVERIGHT		KEYCODE_RIGHT
# define KEY_TURNLEFT		KEYCODE_Z
# define KEY_TURNRIGHT		KEYCODE_X
# define KEY_TELE			KEYCODE_PAGEUP
# define KEY_WIDE			KEYCODE_PAGEDOWN
# define KEY_REALPLUS		KEYCODE_D
# define KEY_REALMINUS		KEYCODE_A
# define KEY_IMAGPLUS		KEYCODE_W
# define KEY_IMAGMINUS		KEYCODE_S
# define KEY_CYCLE_INCR		KEYCODE_R
# define KEY_CYCLE_DECR		KEYCODE_E
# define KEY_CURSOR			KEYCODE_C
# define KEY_SPEED			KEYCODE_F
# define KEY_NONE			0x7fffffffL

#endif
