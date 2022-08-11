SRC = ../src/*.cpp
NAME = repel
FLAGS = -o $(NAME) -std=c++17

debug:
	g++ $(SRC) $(FLAGS) -Wall -Wextra -pedantic

release:
	g++ $(SRC) $(FLAGS) -O2 -s -lstdc++fs

static:
	g++ $(SRC) $(FLAGS) -O2 -s -static -static-libgcc -static-libstdc++ -lstdc++fs

win32:
	i686-w64-mingw32-g++ $(SRC) $(FLAGS) -O2 -s -static -static-libgcc -static-libstdc++

win64:
	x86_64-w64-mingw32-g++ $(SRC) $(FLAGS) -O2 -s -static -static-libgcc -static-libstdc++

install:
	make release
	mv repel /bin/

install-static:
	make static
	mv repel /bin/

uninstall:
	rm /bin/repel