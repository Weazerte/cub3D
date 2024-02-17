# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 14:42:13 by eaubry            #+#    #+#              #
#    Updated: 2024/02/17 13:44:44 by eaubry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	pars/pars.c pars/pars_utils.c pars/map_dup.c pars/check_outline.c pars/fill_map.c pars/check_spawn.c pars/free_pars.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			pars/check_texture.c

NAME    =	cub3d

OBJS    =	${SRCS:.c=.o}

CFLAGS    =    -Wall -Wextra -Werror -g

CC	=	cc

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#minilibx-linux/libmlx.a -lreadline -Lminilibx-linux -lmlx -lXext -lX11 -lm

${NAME}:	libft/libft.a  ${OBJS} 
	${CC} ${CFLAGS} ${OBJS} -Llibft -lft -o ${NAME} 

clean:
	rm -f ${OBJS}
	make -C libft clean

fclean:	clean
	rm -f ${NAME}
	make -C libft fclean

re:	fclean all

.PHONY:	all clean fclean re bonus

libft/libft.a:
	make -C libft

#minilibx-linux/libmlx.a:
#make -C minilibx-linux
