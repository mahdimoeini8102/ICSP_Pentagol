#include <stdio.h>
#include "HelpHelpHead.h"
void vmat(char x[6][6], char y[6][6], char rd, int subj, int subi, int s) {
	int m, n;
	//Determination of one section of matrix that should be rotated.
	if (s == 2)
	{
		m = 0; n = 0;
	}
	else if (s == 1)
	{
		m = 0; n = 3;
	}
	else if (s == 3)
	{
		m = 3; n = 0;
	}
	else if (s == 4)
	{
		m = 3; n = 3;
	}
	//According to criterion, it is changed.
	for (int i = m; i < m + 3; i++) {
		for (int j = n; j < n + 3; j++) {
			if (rd == '+')
				x[i][j] = y[subj - j][i + subi];
			else if (rd == '-')
				x[i][j] = y[j + subj][subi - i];
		}
	}
}
void checkhelp(char x[6][6], int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int bw[2]) {
	char y[10][10];
	//y is a bigger array in which surrounding elements of x is '.'
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i < 6 && j < 6)
				y[i][j] = x[i][j];
			else
				y[i][j] = '.';
		}
	}
	//Checking winning black
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (y[i + n1][j + n2] == 'b' && y[i + n3][j + n4] == 'b' && y[i + n5][j + n6] == 'b' && y[i + n7][j + n8] == 'b' && y[i + n9][j + n10] == 'b') {
				bw[0] = 1;
				break;
			}
		}
	}
	//Checking winning white
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (y[i + n1][j + n2] == 'w' && y[i + n3][j + n4] == 'w' && y[i + n5][j + n6] == 'w' && y[i + n7][j + n8] == 'w' && y[i + n9][j + n10] == 'w') {
				bw[1] = 1;
				break;
			}
		}
	}
}