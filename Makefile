##
## EPITECH PROJECT, 2020
## bootsrap my_printf
## File description:
## Makefile
##

CC	= gcc

CFLAGS	= -I./include -L. -lmy
CFLAGS	+=	-W -Wall -Wextra -lm -g3

SRC	= $(wildcard lib/my/*.c)

OBJ	= $(SRC:.c=.o)

LIB	= libmy.a
SRC2	= $(wildcard src/*.c) \
		  ./main.c \

NAME = 42sh

all:	$(LIB)
	$(CC) -o $(NAME) $(SRC2) $(CFLAGS)

$(LIB):	$(OBJ)
	$(AR) rsc $(LIB) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) #*#
	$(RM) $(LIB)

fclean:	clean
	$(RM) -f $(NAME)

re:	fclean all