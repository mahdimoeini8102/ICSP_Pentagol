#include <stdio.h>
#include "HelpHead.h"
//Function of giving amount '.' to elements of x
void cpoint(char x[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			x[i][j] = '.';
		}
	}
}
//Function of drawing board of the game
void draw(char x[6][6]) {
	//drawing different rows
	for (int i = 0; i < 7; i++) { //i = number of each row
		switch (i)
		{
		case 0:
			printf("       1      2      3   |   4      5      6\n");
			break;
		case 3:
			printf("3      %c      %c      %c   |   %c      %c      %c\n\n\n--     --     --     --      --     --     --\n\n\n", x[2][0], x[2][1], x[2][2], x[2][3], x[2][4], x[2][5]);
			break;
		default:
			printf("%d      %c      %c      %c   |   %c      %c      %c\n\n\n", i, x[i - 1][0], x[i - 1][1], x[i - 1][2], x[i - 1][3], x[i - 1][4], x[i - 1][5]);
			break;
		}
	}
}
//Function of checking winner
char check(char x[6][6]) {
	char result; //result = 'r'(resume) or 'b'(black wins) or 'w'(white wins) or 'e'(end of game)
	int bw[2]; //bw is a one-dimensional array. bw[0]=1 shows black wins. bw[1]=1 shows white wins.
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
//Function of changing string to integer
int change(char input) {
	switch (input)
	{
	case '1':
		return 1; break;
	case '2':
		return 2; break;
	case '3':
		return 3; break;
	case '4':
		return 4; break;
	case '5':
		return 5; break;
	case '6':
		return 6; break;
	case '7':
		return 7; break;
	case '8':
		return 8; break;
	case '9':
		return 9; break;
	case '0':
		return 0; break;
	default:
		break;
	}
}