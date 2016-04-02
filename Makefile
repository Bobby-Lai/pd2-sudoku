main : main.cpp Sudoku.o
	g++ -o main Sudoku.o main.cpp
Sudoku.o : Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp
