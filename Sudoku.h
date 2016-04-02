#include <iostream>

#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Sudoku{
	public:
		void giveQuestion();
		void readIn();
		void check();
		void checkall();
		void solve();
		void solveMethod();
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a, int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		void test();
	
	private:
		int map[81];
		int a[81][9];
};
