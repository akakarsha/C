#include <graphics.h>
#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

int main() {
    int gdriver = DETECT, gmode;
    int headX = 200, headY = 200;
    int foodX, foodY;
    int dirX = 10, dirY = 0; /* Starting direction (Right) */
    char ch;
    int score = 0;
    char scoreStr[20];

    initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");

    /* Generate first food coordinates */
    randomize();
    foodX = (rand() % 40 + 5) * 10;
    foodY = (rand() % 30 + 5) * 10;

    while (1) {
	/* Clear screen buffer and draw borders */
	cleardevice();
	setcolor(WHITE);
	rectangle(10, 40, 630, 450);

	/* Display Score */
	sprintf(scoreStr, "SCORE: %d", score);
	outtextxy(20, 15, scoreStr);
	outtextxy(450, 15, "CONTROLS: W A S D | Q = Quit");

	/* Draw Food */
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	bar(foodX, foodY, foodX + 8, foodY + 8);

	/* Update Snake Head position */
	headX += dirX;
	headY += dirY;

	/* Draw Snake Head */
	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	bar(headX, headY, headX + 8, headY + 8);

	/* Collision with Wall boundaries */
	if (headX < 10 || headX > 620 || headY < 40 || headY > 440) {
	    outtextxy(280, 220, "GAME OVER!");
	    getch();
	    break;
	}

	/* Collision with Food */
	if (abs(headX - foodX) < 10 && abs(headY - foodY) < 10) {
	    score += 10;
	    foodX = (rand() % 58 + 2) * 10;
	    foodY = (rand() % 38 + 5) * 10;
	}

	/* Check for keyboard input */
	if (kbhit()) {
	    ch = getch();
	    if (ch == 'q' || ch == 'Q') break;

	    if ((ch == 'w' || ch == 'W') && dirY == 0) { dirX = 0; dirY = -10; }
	    else if ((ch == 's' || ch == 'S') && dirY == 0) { dirX = 0; dirY = 10; }
	    else if ((ch == 'a' || ch == 'A') && dirX == 0) { dirX = -10; dirY = 0; }
	    else if ((ch == 'd' || ch == 'D') && dirX == 0) { dirX = 10; dirY = 0; }
	}

	delay(400); /* Controls the game speed */
    }

    closegraph();
    return 0;
}