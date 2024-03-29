/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_common.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/03 04:33:46 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_COMMON_H
# define DEBUG_COMMON_H

# include <stdio.h>
# include <stdarg.h>
# include <errno.h>
# include "ft_printf.h"

# define FD_DEBUG		2
# ifndef DEBUG_MODE
#  define DEBUG_MODE	0
# endif
# if DEBUG_MODE == 0
#  define debug_printf(...) debug_dummy(__VA_ARGS__)
# else
#  define debug_printf(...) dprintf(FD_DEBUG, __VA_ARGS__)
# endif
# ifndef ERR_PRF
#  define ERR_PRF	-1
# endif
# ifdef __MACH__
#  include "debug_macos.h"
# endif

int	debug_dummy(const char *format, ...);

# define DEBUGV(v_fmt, v) \
    printf(#v ": " v_fmt "\t(file \"%s\", line %d, in %s)\n", \
        v, __FILE__, __LINE__, __FUNCTION__);

# define DC(v) DEBUGV("%c", v);
# define DS(v) DEBUGV("%s", v);
# define DI(v) DEBUGV("%d", v);
# define DF(v) DEBUGV("%f", v);
# define DD(v) DEBUGV("%lf", v);
# define DX(v) DEBUGV("%x", v);
# define DL(v) DEBUGV("%ld", v);

# define DEBUGF(fmt, ...) \
    printf(fmt "\t(file \"%s\", line %d, in %s)\n", \
        __VA_ARGS__, __FILE__, __LINE__, __FUNCTION__);

#endif
