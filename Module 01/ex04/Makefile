# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 17:13:06 by nchennaf          #+#    #+#              #
#    Updated: 2022/12/27 14:14:45 by nchennaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		c++
#CC =		g++
#CFLAGS =	g++-11 -Werror -Wextra -Wall -std=c++98 -pedantic
CFLAGS =	-Wall -Wextra -Werror -g -std=c++98 -pedantic #-fsanitize=address
NAME =		the_substitute
AR =		ar rcs
SRC =		main.cpp \

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
