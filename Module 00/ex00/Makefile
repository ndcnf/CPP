# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 09:33:59 by nchennaf          #+#    #+#              #
#    Updated: 2022/12/16 09:36:06 by nchennaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		c++
CFLAGS =	-Wall -Wextra -Werror -g -fsanitize=address -std=c++98 -pedantic
NAME =		megaphone
AR =		ar rcs
SRC =		megaphone.cpp

OBJ =		${SRC:.cpp=.o}

all:		${NAME}

${NAME}:	${OBJ}
			@${CC} ${CFLAGS} ${OBJ} -o ${NAME}
			@echo "compiling	OK"

clean:
			@rm -rf ${OBJ}
			@echo "cleaning	OK"

fclean:		clean
			@rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re norm
