#include "HelpHead.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
/*
You can move with w, a, s, d and select a circle with f.
And you can select big square and rotate it with 1, 2, 3, 4 and then + or -.
All instructions are shown in cmd.
*/
int main() {
	initwindow(650, 650, "Pentagol!"); //Creating graphical window
	//Defining variants
	char x[6][6];
	cpoint(x);//cpoint is a function for giving amount '.' to elements of x
	int i, j, turn = 1; //If turn is 1 it's the black player's turn but if turn is -1 it's the white player's turn
	char result = 'r';
	int counter = 0; //If counter equal 36 game will be announced equal
	char input;
	while (result == 'r') { //Until final result is unknown, result = r and the game will go on
		//Clearing cmd, drawing board again and checking winner
		system("cls");
		cleardevice();
		draw(x);
		result = check(x);
		counter++;
		if (counter > 36)
			result = 'e';
		//Deduction for announcing winner or resumption the game
		if (result == 'b') {
			printf("The BLACK player has won!");
			settextstyle(8, HORIZ_DIR, 2);
			outtextxy(175, 300, "The BLACK player has won!");
			break;
		}
		else if (result == 'w') {
			printf("The WHITE player has won!");
			settextstyle(8, HORIZ_DIR, 2);
			outtextxy(175, 300, "The WHITE player has won!");
			break;
		}
		else if (result == 'e') {
			printf("Both players have been equal!");
			settextstyle(8, HORIZ_DIR, 2);
			outtextxy(175, 300, "Both players have been equal!");
			break;
		}
		if (turn == 1)
			printf("BLACK player's turn : "); //Inputing the black player position
		else if (turn == -1)
			printf("WHITE player's turn : "); //Inputing the black player position
		int rec[4] = { 73,73,77,77 }; //rec is array contains small rectangle coordinates
		do {
			setcolor(12); rectangle(rec[0], rec[1], rec[2], rec[3]); setcolor(WHITE);
			input = getch();
			switch (input) //Changing small rectangle coordinates based on inputed character
			{
			case 'a':
				if (rec[0] > 73) {
					rec[0] -= 100; rec[2] -= 100;
				}
				break;
			case 's':
				if (rec[3] < 577) {
					rec[1] += 100; rec[3] += 100;
				}
				break;
			case 'd':
				if (rec[2] < 577) {
					rec[0] += 100; rec[2] += 100;
				}
				break;
			case 'w':
				if (rec[1] > 73) {
					rec[1] -= 100; rec[3] -= 100;
				}
				break;
			default:
				break;
			}
			//Drawing board again
			cleardevice();
			draw(x);
			setcolor(12); rectangle(rec[0], rec[1], rec[2], rec[3]); setcolor(WHITE);
			i = (rec[1] - 73) / 100;
			j = (rec[0] - 73) / 100;

		} while (input != 'f' || x[i][j] != '.');//Checking illegal input
		if (turn == 1) { //It's the black player's turn
			x[i][j] = 'b';
			turn *= -1; //Giving turn to opponent
		}
		else if (turn == -1) { //It's the white player's turn
			x[i][j] = 'w';
			turn *= -1;//Giving turn to opponent
		}
		//Clearing cmd, drawing board again and checking winner
		system("cls");
		cleardevice();
		draw(x);
		printf("Choose square and rotating direction: "); //Inputing second part (choosing square and rotating it)
		int s = 0; //s (stands for section) refers one of four squares (is between 1 to 4)
		char rt = '\0'; //rt stands for rotation (is + or -)
		do {
			input = getch();
			switch (input) //Changing small rectangle coordinates based on inputed charachter
			{
			case '2':
				draw_rec(2); s = 2; break;
			case '1':
				draw_rec(1); s = 1; break;
			case '4':
				draw_rec(4); s = 4; break;
			case '3':
				draw_rec(3); s = 3; break;
			case '+':
				if (s != 0) {
					rt = '+'; break;
				}
			case '-':
				if (s != 0) {
					rt = '-'; break;
				}
			default:
				break;
			}
		} while (rt != '+' && rt != '-' || s == 0);
		rotate(x, s, rt);
	}
	//Anouncing game over
	settextstyle(8, HORIZ_DIR, 2);
	outtextxy(75, 330, "Thanks for playing. Press any key to EXIT!");
	printf("\nPress any key to exit:)");
	getch();
}