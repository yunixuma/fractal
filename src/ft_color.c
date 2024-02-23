/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/23 15:10:15 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_color_rgb2code(int red, int green, int blue)
{
	red = red << ((N_CHANNEL - IDX_RED - 1) * BITS_CHANNEL);
	green = green << ((N_CHANNEL - IDX_GREEN - 1) * BITS_CHANNEL);
	blue = blue << ((N_CHANNEL - IDX_BLUE - 1) * BITS_CHANNEL);
	return (red | green | blue);
}

int	ft_color_hsv2code(int hue, int chr, int bri)
{
	int	max;
	int	min;

	max = bri;
	min = max - (chr / 0xff * max);
	if (hue < 60)
		return (ft_color_rgb2code(max, hue * chr / 60 + min, min));
	if (hue < 120)
		return (ft_color_rgb2code((120 - hue) * chr / 60 + min, max, min));
	if (hue < 180)
		return (ft_color_rgb2code(min, max, (hue - 120) * chr / 60 + min));
	if (hue < 240)
		return (ft_color_rgb2code(min, (240 - hue) * chr / 60 + min, max));
	if (hue < 300)
		return (ft_color_rgb2code((hue - 240) * chr / 60 + min, min, max));
	return (ft_color_rgb2code(max, min, (360 - hue) * chr / 60 + min));
}
