/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/02/20 18:28:03 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	*ft_free(void **p)
{
	if (p == NULL)
		return (NULL);
	if (*p != NULL)
		free(*p);
	*p = NULL;
	return (NULL);
}

void	*ft_free_seterr(void **p, int errnum)
{
	if (p)
		ft_free(p);
	return (ft_seterr_null(errnum));
}
