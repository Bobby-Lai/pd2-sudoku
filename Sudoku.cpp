#include "Sudoku.h"

void Sudoku::giveQuestion(){
	int que[9][9] = {0, 2, 1, 6, 0, 0, 0, 0, 3,
					 0, 0, 7, 0, 0, 1, 0, 0, 0,
					 0, 0, 0, 7, 0, 0, 9, 5, 0,
				 	 0, 0, 0, 0, 1, 0, 8, 0, 4,
					 0, 3, 0, 0, 8, 0, 0, 2, 0,
					 8, 0, 5, 0, 9, 0, 0, 0, 0,
					 0, 5, 3, 0, 0, 2, 0, 0, 0,
					 0, 0, 0, 3, 0, 0, 4, 0, 0,
					 2, 0, 0, 0, 0, 4, 1, 3, 0};
	int i, j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cout<<que[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Sudoku::readIn(){
	int i;
	for(i=0;i<81;i++){
		cin>>map[i];
	}
}

void Sudoku::check(){
	int i, j, k, t;
	for(i=0;i<81;i++){
		if(map[i]!=0){
	        j = map[i];                              //j為題目之值
	        k = i-((i%9)%3)-9*((i/9)%3);
	        a[k][j] = 0;                             //題目所屬之方格的其他空格除去題目之值的可能
	        a[k+1][j] = 0;
	        a[k+2][j] = 0;
	        a[k+9][j] = 0;
	        a[k+10][j] = 0;
	        a[k+11][j] = 0;
	        a[k+18][j] = 0;
		    a[k+19][j] = 0;
		    a[k+20][j] = 0;
		    k = i%9;
	        for(t=0;t<9;t++)
		        a[k+(9*t)][j] = 0;                   //題目所屬之縱行的其他空格除去題目之值的可能
		    k = i/9;
		    for(t=0;t<9;t++)
		        a[(k*9)+t][j] = 0;                   //題目所屬之橫行的其他空格除去題目之值的可能
		    a[i][j] = j;
		}
    }
}

void Sudoku::checkall(){
	int i, t=0;
	for(i=0;i<81;i++){
		if (map[i]==0)
			t++;
	}
	if (t!=0)
		solve();
	else if (t==0){
		cout<<endl<<1<<endl;
		test();
	}
	else
		cout<<"F**king error!!!";
}

void Sudoku::solve(){
	int i, j, k, t;
	for(i=0;i<81;i++){
		if(map[i]!=0){
	        for(j=1;j<10;j++){
		        a[i][j] = 0;
	    	    a[i][map[i]] = map[i];
       		}
   		}
        else{
	        for(j=1;j<10;j++)
	            a[i][j] = j;
	        }
	}
	check();
	solveMethod();
}

void Sudoku::solveMethod(){
	int i, j, k, t;

	for(j=0;j<9;j++){								 //個方格檢查
		for(i=1;i<10;i++){                           //數字1~9
			int t = 0;
			if (a[(j%3)*3+((j/3)*27)][i]==i){
				k = (j%3)*3+((j/3)*27);
				t++;}
			else if (a[(j%3)*3+((j/3)*27)+1][i]==i){
				k = (j%3)*3+((j/3)*27)+1;
				t++;}
			else if (a[(j%3)*3+((j/3)*27)+2][i]==i){
				k = (j%3)*3+((j/3)*27)+2;
				t++;}
			else if (a[(j%3)*3+((j/3)*27)+9][i]==i){
				k = (j%3)*3+((j/3)*27)+9;
				t++;}
			else if (a[(j%3)*3+((j/3)*27)+10][i]==i){
				k = (j%3)*3+((j/3)*27)+10;
				t++;}
			else if (a[(j%3)*3+((j/3)*27)+11][i]==i){
				k = (j%3)*3+((j/3)*27)+11;
				t++;}
			else if (a[(j%3)*3+((j/3)*27)+18][i]==i){
				k = (j%3)*3+((j/3)*27)+18;
				t++;}
			else if (a[(j%3)*3+((j/3)*27)+19][i]==i){
				k = (j%3)*3+((j/3)*27)+19;
				t++;}
			else if (a[(j%3)*3+((j/3)*27)+20][i]==i){
				k = (j%3)*3+((j/3)*27)+20;
				t++;}
			if (t==1)
				map[k] = i;
			t = 0;
			check();
		}
	}
	int s;
	for(j=0;j<9;j++){												//各縱行
		for(i=1;i<10;i++){											//各數字
			t = 0;
			for(k=0;k<9;k++){										//縱行之空格
				if (a[(9*k)+j][i]==i){
					s = (9*k)+j;
					t++;
				}
			if (t==1)
				map[s] = i;
			}
		}
		check();
	}

	for(j=0;j<9;j++){
		for(i=1;i<10;i++){
			t = 0;
			for(k=0;k<9;k++){
				if (a[(9*j)+k][i]==i){
					s = (9*j)+k;
					t++;
				}
			if (t==1)
				map[s] = i;
			}
		}
		check();
	}

	checkall();
	
}

void Sudoku::changeNum(int a, int b){
	int i;
	for(i=0;i<81;i++){
		if (map[i]==a){
			map[i] = b;
		}
		else if (map[i]==b){
			map[i] = a;
		}
	}
}

void Sudoku::changeRow(int a, int b){
	int x, y, i, t;
	x = 27*a;
	y = 27*b;
	for(i=0;i<27;i++){
		t = map[x];
		map[x] = map[y];
		map[y] = t;
		x++;
		y++;
	}
}

void Sudoku::changeCol(int a, int b){
	int x, y, i, t;
	x = 3*a;
	y = 3*b;
	for(i=0;i<27;i++){
		t = map[x];
		map[x] = map[y];
		map[y] = t;
		if (x%9==2||x%9==5||x%9==8){
			x = x+7;
			y = y+7;
		}
		else{
			x++;
			y++;
		}
	}	
}

void Sudoku::rotate(int n){
	int x, y, i, j, k, t, s;
	for(i=0;i<n;i++){
		for(j=1;j<5;j++){
			for(s=0;s<(2*j);s++){
				t = map[40-(10*j)];
				for(k=0;k<(2*j);k++){
					map[40-(10*j)+(9*k)] = map[40-(10*j)+(9*(k+1))];
				}
				for(k=0;k<(2*j);k++){
					map[40+(8*j)+k] = map[40+(8*j)+k+1];
				}
				for(k=0;k<(2*j);k++){
					map[40+(10*j)-(9*k)] = map[40+(10*j)-(9*(k+1))];
				}
				for(k=0;k<(2*j)-1;k++){
					map[40-(8*j)-k] = map[40-(8*j)-k-1];
				}
				map[40-(10*j)+1] = t;
			}
		}
	}
}

void Sudoku::flip(int n){
	int i, t;
	if (n==0){
		for(i=0;i<36;i++){
			t = map[i];
			map[i] = map[36+(i%9)+9*(4-(i/9))];
			map[36+(i%9)+9*(4-(i/9))] = t;
		}
	}
	else if (n==1){
		for(i=0;i<36;i++){
			t = map[(i%9)*9+(i/9)];
			map[(i%9)*9+(i/9)] = map[(i%9)*9+(i/9)+2*(4-(i/9))];
			map[(i%9)*9+(i/9)+2*(4-(i/9))] = t;
		}
	}
}

void Sudoku::transform(){
	readIn();
	srand(time(NULL));
	changeNum(rand()%9+1, rand()%9+1);
	changeRow(rand()%3, rand()%3);
	changeCol(rand()%3, rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	test();
}

/*void Sudoku::mmap(){
	int i;
	for(i=0;i<81;i++){
		map[i] = (i/9)+1;
	}
}*/
void Sudoku::test(){
	int i;
	for(i=0;i<81;i++){
		printf("%d%c", map[i], (i+1)%9==0?'\n':' ');
	}
	cout<<endl;
}
