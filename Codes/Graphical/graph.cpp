#include "graph.h"
#include "graphics.h"
#include "dibapi.h"
#include "dibutil.h"
void draw(char x[6][6]) {
	char input;
	//Drawing 4 main squares 
	draw_rec(0);
	//Drawing 2 main lines
	line(325, 0, 325, 650);
	line(0, 325, 650, 325);
	int i, j;
	//Drawing 36 simple main circles
	for (i = 0; i < 600; i += 100) {
		for (j = 0; j < 600; j += 100) {
			setfillstyle(SOLID_FILL, RED);
			circle(i + 75, j + 75, 25);
			floodfill(i + 75, j + 75, WHITE);
		}
	}
	//Drawing special circles based on place of beads
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (x[i][j] == 'b') {
				setfillstyle(SOLID_FILL, BLACK);
				circle(100 * j + 75, 100 * i + 75, 25);
				floodfill(100 * j + 75, 100 * i + 75, WHITE);
			}
			else if (x[i][j] == 'w') {
				setfillstyle(SOLID_FILL, WHITE);
				circle(100 * j + 75, 100 * i + 75, 25);
				floodfill(100 * j + 75, 100 * i + 75, WHITE);
			}
		}
	}
}
//draw_rec is a function that draw 4 main rectangle
//number = 0(for all rectangles) or n(for rectangle number n that 0 < n < 5)
void draw_rec(int number) {
	switch (number)
	{
	case 0:
		setfillstyle(SOLID_FILL, RED); rectangle(25, 25, 320, 320); floodfill(300, 300, WHITE);
		setfillstyle(SOLID_FILL, RED); rectangle(330, 25, 620, 320); floodfill(600, 300, WHITE);
		setfillstyle(SOLID_FILL, RED); rectangle(330, 330, 620, 620); floodfill(600, 600, WHITE);
		setfillstyle(SOLID_FILL, RED); rectangle(25, 330, 320, 620); floodfill(300, 600, WHITE);
		break;
	case 2:
		setfillstyle(5, 12); rectangle(25, 25, 320, 320); floodfill(300, 300, WHITE);
		setfillstyle(SOLID_FILL, RED); rectangle(330, 25, 620, 320); floodfill(600, 300, WHITE);
		setfillstyle(SOLID_FILL, RED); rectangle(330, 330, 620, 620); floodfill(600, 600, WHITE);
		setfillstyle(SOLID_FILL, RED); rectangle(25, 330, 320, 620); floodfill(300, 600, WHITE);
		break;
	case 1:
		setfillstyle(SOLID_FILL, RED); rectangle(25, 25, 320, 320); floodfill(300, 300, WHITE);
		setfillstyle(4, 12); rectangle(330, 25, 620, 320); floodfill(600, 300, WHITE);
		setfillstyle(SOLID_FILL, RED); rectangle(330, 330, 620, 620); floodfill(600, 600, WHITE);
		setfillstyle(SOLID_FILL, RED); rectangle(25, 330, 320, 620); floodfill(300, 600, WHITE);
		break;
	case 4:
		setfillstyle(SOLID_FILL, RED); rectangle(25, 25, 320, 320); floodfill(300, 300, WHITE);
		setfillstyle(SOLID_FILL, RED); rectangle(330, 25, 620, 320); floodfill(600, 300, WHITE);
		setfillstyle(5, 12); rectangle(330, 330, 620, 620); floodfill(600, 600, WHITE);
		setfillstyle(SOLID_FILL, RED); rectangle(25, 330, 320, 620); floodfill(300, 600, WHITE);
		break;
	case 3:
		setfillstyle(SOLID_FILL, RED); rectangle(25, 25, 320, 320); floodfill(300, 300, WHITE);
		setfillstyle(SOLID_FILL, RED); rectangle(330, 25, 620, 320); floodfill(600, 300, WHITE);
		setfillstyle(SOLID_FILL, RED); rectangle(330, 330, 620, 620); floodfill(600, 600, WHITE);
		setfillstyle(4, 12); rectangle(25, 330, 320, 620); floodfill(300, 600, WHITE);
		break;
	default:
		break;
	}
}