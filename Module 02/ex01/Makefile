# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 14:16:12 by nchennaf          #+#    #+#              #
#    Updated: 2022/12/29 14:16:15 by nchennaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		c++
#CC =		g++
#CFLAGS =	g++-11 -Werror -Wextra -Wall -std=c++98 -pedantic
CFLAGS =	-Wall -Wextra -Werror -g -std=c++98 -pedantic -fsanitize=address
NAME =		fixed
AR =		ar rcs
SRC =		main.cpp \
			Fixed.cpp
HEADER =	Fixed.hpp

OBJ =		${SRC:.cpp=.o}

all:		${NAME}

${OBJ}: %.o : %.cpp ${HEADER}
	@${CC} ${CPPFLAGS} -o $@ -c $<

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
