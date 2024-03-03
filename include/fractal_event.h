/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_event.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/03 13:38:00 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_EVENT_H
# define FRACTAL_EVENT_H

# define EVENT_KEYDOWN		2
# define EVENT_KEYUP		3
# define EVENT_MOUSEPRESS	4
# define EVENT_MOUSERELEASE	5
# define EVENT_MOUSEMOVE	6
# define EVENT_EXPOSE		12
# define EVENT_DESTROY		17
# define MASK_STRUCT		1
# define SHIFT_KEYDOWN		0
# define SHIFT_KEYUP		1
# define SHIFT_MOUSEPRESS	2
# define SHIFT_MOUSERELEASE	3
# define SHIFT_MOUSEMOVE	EVENT_MOUSEMOVE
# define SHIFT_DESTROY  	EVENT_DESTROY

# define VK_Q				'q'
# define VK_W				'w'
# define VK_E				'e'
# define VK_R				'r'
# define VK_A				'a'
# define VK_S				's'
# define VK_D				'd'
# define VK_F				'f'
# define VK_Z				'z'
# define VK_X				'x'
# define VK_C				'c'
# define VK_UP				0xff52
# define VK_LEFT			0xff51
# define VK_DOWN			0xff54
# define VK_RIGHT			0xff53
# define VK_ESC				0xff1b
# define VK_PGUP			0xff55
# define VK_PGDN			0xff56
# define VK_LBUTTON			0x01
# define VK_MBUTTON			0x02
# define VK_RBUTTON			0x03
# define VK_SCROLLUP		0x04
# define VK_SCROLLDOWN		0x05
# define KEY_EXIT_1			VK_ESC
# define KEY_EXIT_2			VK_Q
# define KEY_MOVEUP			VK_UP
# define KEY_MOVEDOWN		VK_DOWN
# define KEY_MOVELEFT		VK_LEFT
# define KEY_MOVERIGHT		VK_RIGHT
# define KEY_TURNLEFT		VK_Z
# define KEY_TURNRIGHT		VK_X
# define KEY_REALPLUS		VK_D
# define KEY_REALMINUS		VK_A
# define KEY_IMAGPLUS		VK_W
# define KEY_IMAGMINUS		VK_S
# define KEY_DEPTH_INCR		VK_R
# define KEY_DEPTH_DECR		VK_E
# define KEY_CURSOR			VK_C
# define KEY_SPEED			VK_F
# define KEY_TELE			VK_PGUP
# define KEY_WIDE			VK_PGDN
# define BUTTON_FOCUS		VK_LBUTTON
# define BUTTON_CURSOR		VK_MBUTTON
# define BUTTON_SPEED		VK_RBUTTON
# define BUTTON_TELE		VK_SCROLLUP
# define BUTTON_WIDE		VK_SCROLLDOWN
# define KEY_NONE			0x7fffffffL

#endif
