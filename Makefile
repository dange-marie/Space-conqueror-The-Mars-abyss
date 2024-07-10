##
## EPITECH PROJECT, 2024
## main.hs
## File description:
## main.hs
##

SRC	=	$(wildcard src/*.cpp)

NAME = mars-abyss

all: $(NAME)

$(NAME):
		g++ $(SRC) -o $(NAME) -lsfml-graphics \
		-lsfml-window -lsfml-system -lsfml-network -lsfml-audio

clean:
	rm -rf *.o
	rm -rf *~

fclean:	clean
		rm -rf $(NAME)

re:	fclean	all