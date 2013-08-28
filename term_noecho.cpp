#include<iostream>
#include<termios.h>
#include<fstream>

using namespace std;

static struct termios old,cur;

void set_echo_opt(int echo)
{
		tcgetattr(0, &cur);
		old = cur; //copy current setting to other termios type variable old for futher recovery of terminal to its normal state
		cur.c_lflag= ~ICANON; // set non-buffered io [non canonical input(no lne editing... see "man termios" for help)]
		cur.c_lflag=echo ? ECHO : ~ECHO; //set terminal to no echo if echo=0
		tcsetattr(0,TCSANOW, &cur); //apply cur termios setting to terminal immediately(TCSANOW) 
}

void restoreterm()
{
		tcsetattr(0, TCSANOW, &old);
}

void _getch(int echo)
{
set_echo_opt(echo);
}

char ch;
char getch()
{
char gc;
_getch(0);
cin.get(gc);
restoreterm();
return gc;
}

char getche()
{
char gc;
_getch(1);
cin.get(gc);
restoreterm();
return gc;
}
