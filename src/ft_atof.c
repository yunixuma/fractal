/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:57:55 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/23 08:57:05 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_atof_calc(const char *str, size_t i)
{
	double	ret;
	double	scale;
	int		is_decimal;

	ret = 0;
	scale = 1;
	is_decimal = 0;
	while ((ft_isdigit(*(str + i)) || *(str + i) == '.') && is_decimal < 2)
	{
		if (*(str + i) == '.')
			is_decimal++;
		else
		{
			if (is_decimal)
				scale *= 10;
			ret = ret * 10 + *(str + i) - '0';
		}
		i++;
	}
	return (ret / scale);
}

float	ft_atof(const char *str)
{
	size_t	i;
	double	ret;
	int		is_minus;

	i = 0;
	while (*(str + i) == ' ' || (*(str + i) >= 9 && *(str + i) <= 13))
		i++;
	is_minus = (*(str + i) == '-');
	if (*(str + i) == '+' || *(str + i) == '-')
		i++;
	ret = ft_atof_calc(str, i);
	if (is_minus)
		return (-ret);
	return (ret);
}
