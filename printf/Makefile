# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 18:04:47 by eaubry            #+#    #+#              #
#    Updated: 2023/03/20 15:51:05 by eaubry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_display.c ft_print_hexa.c ft_print_ptr.c ft_printf.c ft_putchar.c ft_print_unsigned.c ft_putnbr.c ft_putstr.c 

INC	=	ft_printf.h

NAME	=	libprintf.a

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror

all:	${NAME}

.c.o:
	cc ${CFLAGS} -fPIC -c $< -o ${<:.c=.o}
	
${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS} ${INC}
	
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

so:
	$(CC) -fPIC $(CFLAGS) $(SRC)
	gcc -shared -o printf.so $(OBJ)