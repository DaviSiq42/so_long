# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 16:08:26 by davioliv          #+#    #+#              #
#    Updated: 2024/04/15 18:03:27 by davioliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
SRC = mlx.c so_long.c create_map.c quit_all.c moves.c check_game.c flood_n_stuff.c
OBJ = ${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
MAKE = make -C
RM = rm -f
LIBDIR = libs/libft
LIB = -L ${LIBDIR} -lft
MLXDIR = libs/mlx
MLX = -L ${MLXDIR} -lmlx -Ilmlx -lXext -lX11 -lm

all:	${NAME}

$(NAME):	${OBJ}
	${MAKE} ${LIBDIR}
	${MAKE} ${MLXDIR}
	${CC} ${CFLAGS} ${OBJ} ${LIB} ${MLX} -o ${NAME}

clean:
	${MAKE} ${LIBDIR} clean
	${MAKE} ${MLXDIR} clean
	${RM} ${OBJ}

fclean:	clean
	${MAKE} ${LIBDIR} fclean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re

.SILENT:
