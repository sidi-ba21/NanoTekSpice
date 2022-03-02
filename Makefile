##
## EPITECH PROJECT, 2022
## B-OOP-400-PAR-4-1-tekspice-geraud.deltour
## File description:
## Makefile
##

NAME	=	nanotekspice

SRC_DIR	=	src/

SRC		=	$(SRC_DIR)main.cpp		\
			$(SRC_DIR)Gates.cpp		\
			$(SRC_DIR)parsing.cpp	\
			$(SRC_DIR)Circuit.cpp	\

OBJ		=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I include

CC		=		g++

CFLAGS	=	-std=c++20 -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all