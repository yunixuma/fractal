/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/20 18:28:04 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_addr	ft_mapsize(char **map)
{
	t_addr	size;

	if (map == NULL)
	{
		size.x = SIZE_NULL;
		size.y = SIZE_NULL;
	}
	size.y = 0;
	size.x = ft_strlen(map[size.y]);
	while (map[size.y] != NULL)
		(size.y)++;
	return (size);
}
