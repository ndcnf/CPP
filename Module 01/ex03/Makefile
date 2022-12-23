# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 12:56:27 by nchennaf          #+#    #+#              #
#    Updated: 2022/12/23 17:06:55 by nchennaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		c++
CFLAGS =	-Wall -Wextra -Werror -g -std=c++98 -pedantic -fsanitize=address
NAME =		duel
AR =		ar rcs
SRC =		Weapon.cpp \
			main.cpp \
			HumanA.cpp \
			HumanB.cpp \

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
