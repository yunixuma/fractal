# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2024/02/21 01:22:50 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= fractol

# Component names
LIBNAME_FT		= libft
LIBNAME_MLX		= libmlx

# Check the platform
OS				= $(shell uname)

# Enumeration of files
SRC				= fra_main.c fra_param.c \
				  fra_mlx.c fra_win.c fra_img.c fra_print.c fra_exit.c \
				  fra_render_background.c fra_render_fractal.c \
				  fra_render_rectangle.c fra_render_line.c \
				  fra_render_imgline.c fra_render_imgpixel.c \
				  fra_render_blend.c \
				  fra_ctrl.c \
				  fra_ctrl_keyhook.c fra_ctrl_keyhook_fire.c \
				  fra_ctrl_cursorhook.c fra_ctrl_clickhook.c \
				  ft_mapseek.c ft_mapsize.c ft_addr.c ft_cartes.c \
				  ft_free.c ft_seterr.c \
				  ft_prompt_clr.c ft_prompt_arg.c \
				  ft_hasflag.c ft_inrange.c ft_stris.c \
				  ft_math.c ft_math_distance.c 

SRC_DEBUG		= debug_common.c \
				  debug_fra.c debug_fra_f.c debug_fra_map.c debug_fra_img.c

# Enumeration of directories
SRCDIR			= ./src
INCDIR			= ./include
LIBDIR			= ./lib
LIBDIR_FT		= $(LIBDIR)/libft
INCDIR_FT		= $(LIBDIR_FT)/include
LIBDIR_MLX		= $(LIBDIR)/minilibx-linux
OBJDIR			= ./obj

# Macros to replace and/or integrate
SRCS			= $(addprefix $(SRCDIR)/, $(SRC))
OBJS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))
LIB_FT			= $(LIBDIR_FT)/$(LIBNAME_FT).a
LIBS			= $(LIB_FT) -lm
ifeq ($(OS), Darwin)
#	LIB_MLX		= $(LIBNAME_MLX).dylib
#	LIBS		+= $(LIBDIR_MLX)/$(LIB_MLX)
	LIB_MLX		= $(LIBDIR_MLX)/$(LIBNAME_MLX)_Darwin.a
	LIBS		+= $(LIB_MLX)
else
	LIB_MLX		= $(LIBDIR_MLX)/$(LIBNAME_MLX).a
	LIBS		+= $(LIB_MLX)
endif

# Aliases of commands
CC				= cc
RM				= rm

# Command options (flags)
CFLAGS			= -MMD -Wall -Wextra -Werror
DEBUGCFLAGS		= -g -ggdb -fstack-usage -fno-omit-frame-pointer
DEBUGLDFLAGS	= -fsanitize=address
INCLUDES		= -I$(INCDIR) -I$(LIBDIR_MLX) -I$(INCDIR_FT)
ifeq ($(OS), Darwin)
#	LDFLAGS		= -L/usr/lib -L$(LIBDIR_MLX)
	LDFLAGS		= -L/usr/lib -L$(LIBDIR_MLX)/obj
	LIBS		+= -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
else
	LDFLAGS		= -L/usr/lib -L$(LIBDIR_MLX)/obj
	LIBS		+= -lXext -lX11
endif
RMFLAGS			= -r

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), debug)
	ifneq ($(OS), Darwin)
		CFLAGS	+= $(DEBUGCFLAGS)
		LDFLAGS	+= $(DEBUGLDFLAGS)
	endif
	SRC		+= $(SRC_DEBUG)
	DEF		+= -D DEBUG_MODE=1
endif

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re clean_partly debug_lib debug

# Mandatory targets
default:
	-$(MAKE) all
all: $(LIBS) $(NAME)
clean:
	-$(MAKE) clean -C $(LIBDIR_FT)
	-$(MAKE) clean -C $(LIBDIR_MLX)
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	-$(MAKE) fclean -C $(LIBDIR_FT)
	-$(MAKE) clean -C $(LIBDIR_MLX)
	-$(RM) $(RMFLAGS) $(NAME)
ifeq ($(OS), Darwin)
	-$(RM) $(LIB_MLX)
endif
re: fclean all

# Additional targets
clean_partly:
	$(MAKE) clean -C $(LIBDIR_FT)
	-$(RM) $(RMFLAGS) $(OBJDIR)
debug_lib: 
	$(MAKE) debug -C $(LIBDIR_FT)
debug: clean_partly debug_lib all

# Recipes
$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)
$(LIBS):
	$(MAKE) -C $(LIBDIR_FT)
	$(MAKE) -C $(LIBDIR_MLX)
#ifeq ($(OS), Darwin)
#	cp -p $(LIBDIR_MLX)/$(LIB_MLX) ./
#endif
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
