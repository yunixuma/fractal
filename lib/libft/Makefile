# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile copy                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2024/02/20 21:16:53 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME		= libft.a

# Component names
NAME_LIBFT	= libft
NAME_PRINTF	= printf
NAME_GNL	= gnl

# Enumeration of files
SRC_LIBFT	= ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			  ft_isascii.c ft_isprint.c \
			  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
			  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
			  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			  ft_strmapi.c ft_striteri.c \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			  ft_lstiter.c ft_lstmap.c
SRC_PRINTF	= ft_printf.c ft_dprintf.c ft_dprintf_sub.c prf_conv.c prf_getconv.c \
			  prf_setconv.c prf_setconv_flag.c prf_setconv_type.c \
			  prf_setconv_length.c prf_setconv_order.c prf_setconv_wandp.c \
			  prf_convarg.c prf_convarg_s.c prf_convarg_ws.c \
			  prf_convarg_i.c prf_convarg_ui.c prf_convarg_p.c \
			  prf_convarg_dbl.c prf_convarg_nan.c prf_convarg_ftoe.c \
			  prf_convarg_a.c prf_convarg_la.c \
			  prf_chrtostr.c prf_wchrtostr.c \
			  prf_putlen.c  prf_shiftarg.c prf_getpresentret.c \
			  prf_adjustdigit.c \
			  prf_rounddigit.c prf_rounddigit_fill.c prf_rounddigit_getlen.c \
			  prf_rounddigit_a.c prf_rounddigit_a_getlen.c \
			  prf_rounddigit_a_fill.c prf_rounddigit_a_fill_len.c \
			  prf_putplane.c prf_putpadding.c \
			  prf_putchar.c prf_putstr.c prf_putstrn.c \
			  prf_ulltostr_o.c prf_ulltostr_x.c prf_ftoa.c \
			  prf_strjoin.c prf_strtoupper.c prf_hexdigitadd.c \
			  prf_strnchr.c prf_strrnchr.c prf_isdigit19.c prf_isxdigit1f.c \
			  ft_hasflag.c ft_wcslen.c ft_isxdigit.c ft_lltostr.c ft_ulltostr.c
SRC_GNL		= get_next_line.c get_next_line_utils.c

# Enumeration of directories
SRCDIR		= ./src
INCDIR		= ./include
OBJDIR		= ./obj

# Macros to replace and/or integrate
SRCS_LIBFT	= $(addprefix $(SRCDIR)/$(NAME_LIBFT)/, $(SRC_LIBFT))
SRCS_PRINTF	= $(addprefix $(SRCDIR)/$(NAME_PRINTF)/, $(SRC_PRINTF))
SRCS_GNL	= $(addprefix $(SRCDIR)/$(NAME_GNL)/, $(SRC_GNL))
SRCS		= $(SRCS_LIBFT) $(SRCS_PRINTF) $(SRCS_GNL)
OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))

# Aliases of commands
CC			= cc
AR			= ar
RM			= rm

# Command options (flags)
CFLAGS		= -MMD -Wall -Wextra -Werror
DEBUGFLAGS	= -g -ggdb -fstack-usage -fno-omit-frame-pointer
INCLUDES	= -I$(INCDIR)
ARFLAGS		= rcs
RMFLAGS		= -rf

# Check the platform
OS				= $(shell uname)

# Sources for debugging
SRCS_DEBUG		= $(SRCDIR)/debug_common.c
SRCS_DEBUG_MAC	= $(SRCDIR)/debug_macos.c

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), debug)
	SRCS		+= $(SRCS_DEBUG)
	ifeq ($(OS), Darwin)
		SRCS	+= $(SRCS_DEBUG_MAC)
	endif
endif

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re debug

# Mandatory targets
all: $(NAME)
clean:
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean $(OBJDIR) all
debug: clean all

# Recipes
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/$(NAME_LIBFT)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<
$(OBJDIR)/%.o: $(SRCDIR)/$(NAME_PRINTF)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<
$(OBJDIR)/%.o: $(SRCDIR)/$(NAME_GNL)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
