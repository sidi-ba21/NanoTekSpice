##
## EPITECH PROJECT, 2022
## B-OOP-400-PAR-4-1-tekspice-geraud.deltour
## File description:
## Makefile
##

NAME	=	nanotekspice

SRC_DIR	=	src/

IN_OUT_DIR = InputOutput/

SRC		=	$(SRC_DIR)main.cpp		\
			$(SRC_DIR)Gates.cpp		\
			$(SRC_DIR)parsing.cpp	\
			$(SRC_DIR)Circuit.cpp	\
			$(SRC_DIR)$(IN_OUT_DIR)Input.cpp	\
			$(SRC_DIR)$(IN_OUT_DIR)Output.cpp	\
			$(SRC_DIR)$(IN_OUT_DIR)InPin.cpp	\
			$(SRC_DIR)$(IN_OUT_DIR)OutPin.cpp	\
			$(SRC_DIR)$(IN_OUT_DIR)Pin.cpp		\
			$(SRC_DIR)$(IN_OUT_DIR)CircuitPin.cpp	\


OBJ		=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I include

CC		=		g++

CFLAGS	=	-std=c++20 -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -g3

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all