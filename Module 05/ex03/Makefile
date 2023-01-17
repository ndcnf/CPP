# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 10:01:54 by nchennaf          #+#    #+#              #
#    Updated: 2023/01/16 11:01:32 by nchennaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		c++
#CC =		g++
#CFLAGS =	g++-11 -Werror -Wextra -Wall -std=c++98 -pedantic
CFLAGS =	-Wall -Wextra -Werror -g -std=c++98 -pedantic #-fsanitize=address
NAME =		hell
AR =		ar rcs
SRC =		main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp
HEADER =	Bureaucrat.hpp \
			AForm.hpp \
			ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp \
			PresidentialPardonForm.hpp

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
