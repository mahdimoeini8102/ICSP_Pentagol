#include <stdio.h>
#include "HelpHead.h"
#include "HelpHelpHead.h"
//Function of giving amount '.' to elements of x
void cpoint(char x[6][6]) {
	int i, j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			x[i][j] = '.';
		}
	}
}
//Function of checking winner
char check(char x[6][6]) {
	char result;
	int i, j, empty = 0;
	//bw is a one-dimensional array. bw[0]=1 shows black wins. bw[1]=1 shows white wins.
	int bw[2];
	//Checking horizontal
	checkhelp(x, 0, 0, 0, 1, 0, 2, 0, 3, 1, 3, bw);
	checkhelp(x, 0, 0, 0, 1, 0, 2, 0, 3, -1, 3, bw);
	checkhelp(x, 0, 0, 0, 1, 0, 2, 0, 3, 1, 0, bw);
	checkhelp(x, 0, 0, 0, 1, 0, 2, 0, 3, -1, 0, bw);
	//Checking vertical
	checkhelp(x, 0, 0, 1, 0, 2, 0, 3, 0, 3, 1, bw);
	checkhelp(x, 0, 0, 1, 0, 2, 0, 3, 0, 3, -1, bw);
	checkhelp(x, 0, 0, 1, 0, 2, 0, 3, 0, 0, 1, bw);
	checkhelp(x, 0, 0, 1, 0, 2, 0, 3, 0, 0, -1, bw);
	//Checking diagonal (in the direction of sub-diameter)
	checkhelp(x, 0, 3, 1, 2, 2, 1, 3, 0, 4, 1, bw);
	checkhelp(x, 0, 3, 1, 2, 2, 1, 3, 0, 2, -1, bw);
	checkhelp(x, 0, 3, 1, 2, 2, 1, 3, 0, 1, 4, bw);
	checkhelp(x, 0, 3, 1, 2, 2, 1, 3, 0, -1, 2, bw);
	//Checking diagonal (in the direction of main diameter)
	checkhelp(x, 0, 0, 1, 1, 2, 2, 3, 3, 2, 4, bw);
	checkhelp(x, 0, 0, 1, 1, 2, 2, 3, 3, 4, 2, bw);
	checkhelp(x, 0, 0, 1, 1, 2, 2, 3, 3, 1, -1, bw);
	checkhelp(x, 0, 0, 1, 1, 2, 2, 3, 3, -1, 1, bw);
	//result = 'r'(resume) or 'b'(black wins) or 'w'(white wins) or 'e'(end of game)
	if (bw[0] == 1 && bw[1] != 1)
		result = 'b';
	else if (bw[0] != 1 && bw[1] == 1)
		result = 'w';
	else if (bw[0] == 1 && bw[1] == 1)
		result = 'e';
	else
		result = 'r';
	return result;
}
//Function of rotating
void rotate(char x[6][6], int s, char rt) {
	char y[6][6];
	//Backing up x (in y)
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			y[i][j] = x[i][j];
		}
	}
	if (rt == '+') {
		//vmat (value matrix) is a function that giving amount from y to x
		//vmat(receiver, giver, + or -, criterion1, criterion2, the number of square (1 to 4))
		switch (s)
		{
		case 2:
			vmat(x, y, rt, 2, 0, s);
			break;
		case 1:
			vmat(x, y, rt, 5, 3, s);
			break;
		case 3:
			vmat(x, y, rt, 5, -3, s);
			break;
		case 4:
			vmat(x, y, rt, 8, 0, s);
			break;
		default:
			break;
		}
	}
	else if (rt == '-') {
		switch (s)
		{
		case 2:
			vmat(x, y, rt, 0, 2, s);
			break;
		case 1:
			vmat(x, y, rt, -3, 5, s);
			break;
		case 3:
			vmat(x, y, rt, 3, 5, s);
			break;
		case 4:
			vmat(x, y, rt, 0, 8, s);
			break;
		default:
			break;
		}
	}
}