##
## EPITECH PROJECT, 2022
## B-OOP-400-PAR-4-1-tekspice-geraud.deltour
## File description:
## Makefile
##

NAME	=	nanotekspice

SRC_DIR	=	src/

INPUT	=	Input/

OUTPUT	=	Output/

PIN		=	Pin/

COMPONENT =	Components/

ERROR	=	Error/

PARSING	=	Parsing/

CIRCUIT	=	Circuit/

SRC		=	$(SRC_DIR)main.cpp						\
			$(SRC_DIR)$(CIRCUIT)Gates.cpp			\
			$(SRC_DIR)$(CIRCUIT)Factory.cpp			\
			$(SRC_DIR)$(CIRCUIT)Circuit.cpp			\
			$(SRC_DIR)$(CIRCUIT)Circuitcreate.cpp	\
			$(SRC_DIR)$(PARSING)Parsing.cpp			\
			$(SRC_DIR)$(OUTPUT)Output.cpp			\
			$(SRC_DIR)$(OUTPUT)OutPin.cpp			\
			$(SRC_DIR)$(PIN)Pin.cpp					\
			$(SRC_DIR)$(PIN)CircuitPin.cpp			\
			$(SRC_DIR)$(INPUT)Input.cpp				\
			$(SRC_DIR)$(INPUT)InPin.cpp				\
			$(SRC_DIR)$(INPUT)True.cpp				\
			$(SRC_DIR)$(INPUT)False.cpp				\
			$(SRC_DIR)$(INPUT)Clock.cpp				\
			$(SRC_DIR)$(COMPONENT)4071.cpp			\
			$(SRC_DIR)$(COMPONENT)4081.cpp			\
			$(SRC_DIR)$(COMPONENT)4001.cpp			\
			$(SRC_DIR)$(COMPONENT)4011.cpp			\
			$(SRC_DIR)$(COMPONENT)4030.cpp			\
			$(SRC_DIR)$(COMPONENT)4069.cpp			\
			$(SRC_DIR)$(ERROR)Error.cpp				\

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