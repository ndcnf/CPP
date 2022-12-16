# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 09:33:59 by nchennaf          #+#    #+#              #
#    Updated: 2022/12/16 14:01:14 by nchennaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		c++
CPPFLAGS =	-Wall -Wextra -Werror -g -fsanitize=address -std=c++98 -pedantic
NAME =		phonebook
AR =		ar rcs
SRC =		main.cpp \
			Phonebook.cpp \
			Contact.cpp
HEADER =	./Class.Contact.hpp \
			./Class.Phonebook.hpp

OBJ =		${SRC:.cpp=.o}

all:		${NAME}

${OBJ}: %.o : %.cpp ${HEADER} ./Makefile
	@${CC} ${CPPFLAGS} -o $@ -c $<

${NAME}:	${OBJ}
			@${CC} ${CPPFLAGS} ${OBJ} -o ${NAME}
			@echo "compiling	OK"

clean:
			@rm -rf ${OBJ}
			@echo "cleaning	OK"

fclean:		clean
			@rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re norm
