#include "HelpHead.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
	//Defining variable
	char x[6][6];
	cpoint(x);							//cpoint is a function for giving amount '.' to elements of x
	int s;								//s (stands for section) refers one of four squares (is between 1 to 4)
	int turn = 1;						//If turn is 1 it's the black player's turn but if turn is -1 it's the white player's turn
	char rt, result='r';				//rt stands for rotation (is + or -)
	int counter = 0;					//If counter equal 36 game will be announced equal
	while (result == 'r') {	//Until final result is unknown, result = r and the game will go on
		//Clearing cmd, drawing board and checking winner
		system("cls");
		draw(x);
		result = check(x);
		counter++;
		if (counter > 36)
			result = 'e';
		//Deduction for announcing winner or resumption the game
		if (result == 'b') {
			printf("The BLACK player has won!");
			break;
		}
		if (result == 'w') {
			printf("The WHITE player has won!");
			break;
		}
		if (result == 'e') {
			printf("Both players have been equal!");
			break;
		}
		//This variable help to recognize illegal length of inputs and we expect to fill only two first elements
		char binput[4];
		char winput[4];
		char rinput[4];
		if (turn == 1) { //It's the black player's turn
			printf("BLACK player's turn : "); //Inputing the black player position
			gets(binput);
			while (binput[2] != '\0') {
				printf("The length of input is illegal! retry again. BLACK player's turn : ");
				gets(binput);
			}
			int i = change(binput[0]);
			int j = change(binput[1]);
			while (i < 1 || 6 < i || j < 1 || 6 < j) {
				printf("Illegal input! retry again. BLACK player's turn : ");
				gets(binput);
				while (binput[2] != '\0') {
					printf("The length of input is illegal! retry again. BLACK player's turn : ");
					gets(binput);
				}
				i = change(binput[0]);
				j = change(binput[1]);
			}
			while (x[i - 1][j - 1] != '.') {
				printf("This item was filled before! retry another item. BLACK player's turn : ");
				gets(binput);
				while (binput[2] != '\0') {
					printf("The length of input is illegal! retry again. BLACK player's turn : ");
					gets(binput);
				}
				i = change(binput[0]);
				j = change(binput[1]);
				while (i < 1 || 6 < i || j < 1 || 6 < j) {
					printf("Illegal input! retry again. BLACK player's turn : ");
					gets(binput);
					while (binput[2] != '\0') {
						printf("The length of input is illegal! retry again. BLACK player's turn : ");
						gets(binput);
					}
					i = change(binput[0]);
					j = change(binput[1]);
				}
			}
			x[i - 1][j - 1] = 'b';
			turn *= -1; //Giving turn to opponent
		}
		else if (turn == -1) { //It's the white player's turn
			printf("White player's turn : "); //Inputing the white player position
			gets(winput);
			while (winput[2] != '\0') {
				printf("The length of input is illegal! retry again. WHITE player's turn : ");
				gets(winput);
			}
			int i = change(winput[0]);
			int j = change(winput[1]);
			while (i < 1 || 6 < i || j < 1 || 6 < j) {
				printf("Illegal input! retry again. WHITE player's turn : ");
				gets(winput);
				while (winput[2] != '\0') {
					printf("The length of input is illegal! retry again. WHITE player's turn : ");
					gets(winput);
				}
				i = change(winput[0]);
				j = change(winput[1]);
			}
			while (x[i - 1][j - 1] != '.') {
				printf("This item was filled before! retry another item. WHITE player's turn : ");
				gets(winput);
				while (winput[2] != '\0') {
					printf("The length of input is illegal! retry again. WHITE player's turn : ");
					gets(winput);
				}
				i = change(winput[0]);
				j = change(winput[1]);
				while (i < 1 || 6 < i || j < 1 || 6 < j) {
					printf("Illegal input! retry again. WHITE player's turn : ");
					gets(winput);
					while (winput[2] != '\0') {
						printf("The length of input is illegal! retry again. WHITE player's turn : ");
						gets(winput);
					}
					i = change(winput[0]);
					j = change(winput[1]);
				}
			}
			x[i - 1][j - 1] = 'w';
			turn *= -1; //Giving turn to opponent
		}
		//Clearing cmd and drawing board
		system("cls");
		draw(x);
		printf("Choose square and rotating direction : "); //Inputing second part (choosing square and rotating it)
		gets(rinput);
		while (rinput[2] != '\0') {
			printf("The length of input is illegal! retry again. Choose square and rotating direction : ");
			gets(rinput);
		}
		s = change(rinput[0]);
		rt = rinput[1];
		while ((rt != '+' && rt != '-') || s > 4 || s < 0) {
			printf("Illegal input! retry again. Choose square and rotating direction : ");
			gets(rinput);
			while (rinput[2] != '\0') {
				printf("The length of input is illegal! retry again. Choose square and rotating direction : ");
				gets(rinput);
			}
			s = change(rinput[0]);
			rt = change(rinput[1]);
		}
		rotate(x, s, rt);
	}
}