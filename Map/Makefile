NAME = map

SRC = main.cpp

FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(SRC)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all