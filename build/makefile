SRC = ../src/*.cpp
NAME = repel
FLAGS = -o $(NAME) -std=c++17

debug:
	g++ $(SRC) $(FLAGS) -Wall -Wextra -pedantic

release:
	g++ $(SRC) $(FLAGS) -O2 -s

static:
	g++ $(SRC) $(FLAGS) -O2 -s -static

install:
	make release
	mv repel /bin/

install-static:
	make static
	mv repel /bin/

uninstall:
	rm /bin/repel