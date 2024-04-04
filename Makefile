# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 09:57:09 by thenry            #+#    #+#              #
#    Updated: 2024/03/28 18:06:09 by eaubry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			src/check_outline.c \
			src/check_outline_utils.c \
			src/check_rgb_utils.c \
			src/check_rgb.c \
			src/check_spawn.c \
			src/check_texture.c \
			src/fill_map.c \
			src/free_pars.c \
			src/map_dup.c \
			src/pars_utils.c \
			src/pars.c \
			src/keyhook.c \
			src/keyhook_bis.c \
			src/free_struct.c \
			src/raycast.c \
			src/init.c \
			src/init_bis.c \
			src/render.c \
			src/minimap.c \
			src/utils.c \
			src/main.c \

NAME	= 	cub3D

OBJ_DIR	=	obj

OBJS	=	${patsubst %.c, ${OBJ_DIR}/%.o,${SRCS}}

INC		=	-I inc 

RM		= rm -rf

CFLAGS	= 	-Wall -Wextra -Werror -g

CC	= 	cc

LIBR	=	libft/libft.a minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a

MLX	=	-Lminilibx-linux -lX11 -lXext

MATH =	-lm

all:		${NAME}

${OBJ_DIR}/%.o: %.c | ${OBJ_DIR}
		${CC} ${INC} ${CFLAGS} -MMD -MP -c $< -o $@


${OBJ_DIR}:
		mkdir -p ${OBJ_DIR}
		mkdir -p ${OBJ_DIR}/get_next_line
		mkdir -p ${OBJ_DIR}/src

${NAME}:	${OBJS}
		make -C libft
		make -C minilibx-linux
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${INC} ${LIBR} ${MLX} ${MATH}

-include ${OBJS:.o=.d}

clean:		
		${RM} ${OBJ_DIR}	
		make -C libft clean
		make -C minilibx-linux clean

fclean:		clean
		${RM} ${NAME}
		make -C libft fclean

re:		fclean all

.PHONY:		all re clean fclean
