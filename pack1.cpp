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
