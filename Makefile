CC = g++
C_FLAGS = -g -std=c++17 -Wall
SRC_FILES = $(filter-out $(wildcard mad.cpp),$(wildcard *.cpp))
SFML = -I/opt/homebrew/include -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system
APP = mad

money:
	$(CC) $(C_FLAGS) $(SRC_FILES) -o $(APP) mad.cpp $(SFML)

valgrind:
	valgrind --leak-check=full ./$(APP) $(TEST)

clean:
	rm -f $(APP)