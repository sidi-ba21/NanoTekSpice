##
## EPITECH PROJECT, 2022
## B-OOP-400-PAR-4-1-tekspice-geraud.deltour
## File description:
## Makefile
##

NAME	=	nanotekspice

SRC_DIR	=	src/

IN_OUT_DIR = InputOutput/

COMPONENT =	components/

SRC		=	$(SRC_DIR)main.cpp						\
			$(SRC_DIR)Gates.cpp						\
			$(SRC_DIR)Parsing.cpp					\
			$(SRC_DIR)Circuit.cpp					\
			$(SRC_DIR)$(IN_OUT_DIR)Input.cpp		\
			$(SRC_DIR)$(IN_OUT_DIR)Output.cpp		\
			$(SRC_DIR)$(IN_OUT_DIR)InPin.cpp		\
			$(SRC_DIR)$(IN_OUT_DIR)OutPin.cpp		\
			$(SRC_DIR)$(IN_OUT_DIR)Pin.cpp			\
			$(SRC_DIR)$(IN_OUT_DIR)CircuitPin.cpp	\
			$(SRC_DIR)$(IN_OUT_DIR)True.cpp			\
			$(SRC_DIR)$(IN_OUT_DIR)False.cpp		\
			$(SRC_DIR)$(IN_OUT_DIR)Clock.cpp		\
			$(SRC_DIR)$(COMPONENT)4071.cpp			\
			$(SRC_DIR)$(COMPONENT)4081.cpp			\
			$(SRC_DIR)$(COMPONENT)4001.cpp			\
			$(SRC_DIR)$(COMPONENT)4011.cpp			\
			$(SRC_DIR)$(COMPONENT)4030.cpp			\
			$(SRC_DIR)$(COMPONENT)4069.cpp			\
			$(SRC_DIR)Error.cpp						\
			$(SRC_DIR)Factory.cpp					\

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

.PHONY: all clean fclean re