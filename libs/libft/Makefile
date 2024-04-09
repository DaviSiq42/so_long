# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davioliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 10:03:20 by davioliv          #+#    #+#              #
#    Updated: 2024/03/04 19:54:22 by davioliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_strchr.c ft_strdup.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_atoi.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line_bonus.c get_next_line_utils_bonus.c ft_printchars.c ft_printf.c ft_printhex.c ft_printnbr.c ft_printptr.c
SRCSB	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS	= ${SRCS:.c=.o}
OBJSB	= ${SRCSB:.c=.o}
HEADER	= libft.h
CC	= cc ${CFLAGS}
CFLAGS	= -Wall -Werror -Wextra
INCLUDE	= -I include
RM	= rm -rf
.c.o:
	${CC} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS} ${HEADER}

all:	${NAME}

clean:
	${RM} ${OBJS} ${OBJSB}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

bonus:	${OBJS} ${OBJSB}
	ar rcs ${NAME} ${OBJS} ${OBJSB} ${HEADER}

.PHONY:	all clean fclean re bonus
.SILENT:
