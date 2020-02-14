# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 18:11:29 by lgaultie          #+#    #+#              #
#    Updated: 2020/02/14 18:43:45 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = @clang
CFLAGS = -Wall -Werror -Wextra
MLXFINC = -I /usr/local/include
MLXFLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIBDIR = libft
LIB = $(LIBDIR)/libft.a
OBJDIR = obj
SRCDIR = src
INC = ./includes/

SRCS = main.c

OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
#voir GNU 8.3 Functions for File Names

_GREEN=\e[32m
_PURPLE=\e[35m
_BLUE=\e[34m
_BLUE1=\e[1;34m
_YELLOW=\e[33m
_CYAN=\e[36m
_RED=\e[31m
_END=\e[0m

all: $(NAME)
	@printf "$(_BLUE1) _                   _      _      _        _______ _____   _______ \n"
	@printf "$(_BLUE1)| |                 | |_   (_)    ( )      (_______|____ \ (_______)\n"
	@printf "$(_BLUE1)| | ____  ____ _   _| | |_  _  ___|/ ___    _____   _   \ \ _____   \n"
	@printf "$(_BLUE1)| |/ _  |/ _  | | | | |  _)| |/ _  )/___)  |  ___) | |   | |  ___)  \n"
	@printf "$(_BLUE1)| ( ( | ( ( | | |_| | | |__| ( (/ /|___ |  | |     | |__/ /| |      \n"
	@printf "$(_BLUE1)|_|\_|| |\_||_|\____|_|\___)_|\____|___/   |_|     |_____/ |_|      \n"
	@printf "$(_BLUE1) (_____|                                                           \n"

$(NAME): $(OBJ)
	@printf "$(_YELLOW)Compiling libft... $(_END)"
	@make -C $(LIBDIR)
	@printf "$(_YELLOW)Compilation... $(_END)"
	@$(CC) $(CFLAGS) $(MLXINC) $(OBJ) $(LIB) $(MLXFLAGS) -I$(INC) -o $(NAME)
	@printf "$(_GREEN)fdf done [✓]$(_END)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c includes/fdf.h
	@$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

$(OBJDIR) :
	@printf "$(_YELLOW)Creating $(_PURPLE)fdf$(_YELLOW) obj folder $(_END)"
	@mkdir $@
	@printf "$(_CYAN)done$(_END)\n"

$(OBJ) : | $(OBJDIR)
#voir GNU make 4.3 Types of Prerequisites

clean:
	@printf "$(_YELLOW)clean... $(_END)"
	@cd $(LIBDIR) && make clean
	@rm -rf $(OBJDIR)
	@printf "$(_CYAN)done$(_END)\n"

fclean: clean
	@printf "$(_YELLOW)fclean... $(_END)"
	@cd $(LIBDIR) && make fclean
	@rm -rf $(NAME)
	@printf "$(_CYAN)done $(_END)\n"

re: fclean all clean

.PHONY: clean fclean all re
