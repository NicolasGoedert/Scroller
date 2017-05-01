##
## Makefile for Makefile in /home/Romingo/CGraph/scroller
## 
## Made by romain rousseau
## Login   <Romingo@epitech.net>
## 
## Started on  Sat Apr  1 15:51:25 2017 romain rousseau
## Last update Sat Apr  1 15:51:25 2017 romain rousseau
##

NAME	=	scroller

SRC	=	main.c		\
		muse.c		\
		wolf.c		\
		back.c		\
		text.c		\
		fire.c		\
		plant.c		\
		bird.c		\
		nyancat.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-I./include/

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lc_graph_prog_full

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(CLEAN)

re	:	fclean all

.PHONY	:	all clean fclean re
