#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;
char tmp_map[18][32];

char map[18][32] = {
	"+#############################+",
	"|                  |          |",
	"|   ##   |#######  |   ###### |",
	"|## #### |         | ######## |",
	"|        |    #####       ##  |",
	"| | |###    |      ##   |     |",
	"| | |    |  | |###  |   |  |  |",
	"| | #####|##| |      ## |     |",
	"| |           |###  |      |  |",
	"| |##### ###         ##       |",
	"|          ######  ####### ###|",
	"#####        |                |",
	"|# ########  |   ###   #######|",
	"|     #      |                |",
	"|  ########        |  #####   |",
	"|  ######   ###### |  #####   |",
	"|                             |",
	"+#############################+"
	};

void ShowMap()
{
	HANDLE h;
	h=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,139);
	for(int i = 0; i < 18; i++) {
		printf("%s\n",map[i] );
	}
}

void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;
    SetConsoleCursorPosition( hStdout, position ) ;
}

class entity {
public:
	entity( int x, int y ){
		this ->x = x;
		this ->y = y;
	}

	void move_x( int p ){
		if( map[y][x+p] == ' ' ) x += p;
	}

	void move_y( int p ){
		if( map[y+p][x] == ' ' ) y += p;
	}

	void move( int p, int q ){
		x += p;
		y += q;
	}

	int get_x(){ return x; }
	int get_y(){ return y; }

	void draw( char p ){
		map[x][y] = p;
		gotoxy( x, y );
		printf( "%c", p );
	}

private:
	int x;
	int y;
};

struct walk {
	short walk_count;
	short x;
	short y;
	short back;
};

struct target {
	short x;
	short y;
};
