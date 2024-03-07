all: compil

compil: main.cpp
	clang++ -Wall -Werror IntVector.cpp main.cpp -o main

