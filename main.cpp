#include "Sudoku.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int a, b, n;
	Sudoku ss;
	/*ss.giveQuestion();
	cout<<"reset"<<endl;
	ss.mmap();
	cout<<"map"<<endl;
	ss.test();
	cout<<"rotate"<<endl;
	ss.rotate(n);
	cout<<"test"<<endl;
	ss.test();
	cout<<"reset"<<endl;
	ss.mmap();
	cout<<"changeNum"<<endl;
	ss.changeNum(a, b);
	cout<<"test"<<endl;
	ss.test();
	cout<<"reset"<<endl;
	ss.mmap();
	cout<<"changeRow"<<endl;
	ss.changeRow(a, b);
	cout<<"test"<<endl;
	ss.test();
	cout<<"reset"<<endl;
	ss.mmap();
	cout<<"changeCol"<<endl;
	ss.changeCol(a, b);
	cout<<"test"<<endl;
	ss.test();
	cout<<"reset"<<endl;
	ss.mmap();
	cout<<"flip"<<endl;
	ss.flip(n);
	cout<<"test"<<endl;
	ss.test();*/
	//ss.transform();
	ss.readIn();
	ss.solve();
	
	return 0;
}
