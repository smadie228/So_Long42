NAME		= so_long
CC			= clang
SRCS		=	srcs/maps.c\
				srcs/so_long.c\
				srcs/validate_map.c\
				srcs/ft_strlen.c\
				srcs/error.c\
				srcs/ft_strstr.c\
				GNL/ft_gnl.c\
				GNL/ft_strcpy_gnl.c\


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
