# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smadie <smadie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 21:22:38 by smadie            #+#    #+#              #
#    Updated: 2021/12/26 21:22:41 by smadie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= clang
SRCS		=	GNL/ft_gnl.c \
				GNL/ft_strcpy_gnl.c \
				LIBFT/ft_itoa.c \
				LIBFT/ft_strlen.c \
				LIBFT/ft_strstr.c \
				LIBFT/ft_count_digit.c\
				srcs/animation.c \
				srcs/enemy_move.c \
				srcs/enemy.c \
				srcs/error.c \
				srcs/free_map.c\
				srcs/game.c \
				srcs/key_manager.c \
				srcs/maps.c \
				srcs/movements.c\
				srcs/so_long.c \
				srcs/validate_map.c\

CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -L ./minilibx/ -lmlx -framework OpenGl -framework AppKit -lz
RM			= rm -rf
OBJS		= $(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(SRCS) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

run:		all
			./$(NAME) maps/map_bonus.ber

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out


re:			fclean all

.PHONY:		all clean fclean re
