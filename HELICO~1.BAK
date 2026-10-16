#include <graphics.h>
#include<math.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
void main() {
    int gd = DETECT, gm;
    int copterY = 200, copterX = 100;
    int velocity = 0, gravity = 1;
    int wallX = 600, wallTop = 150, wallBottom = 280;
    char key;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    while (1) {
	cleardevice();

	// Draw Ceiling & Floor Lines
	setcolor(WHITE);
	line(0, 50, 640, 50);
	line(0, 430, 640, 430);

	// Draw Helicopter (Box + Rotor)
	setcolor(YELLOW);
	rectangle(copterX, copterY, copterX + 30, copterY + 15);
	line(copterX - 5, copterY - 5, copterX + 35, copterY - 5); // Rotor line
	line(copterX + 15, copterY - 5, copterX + 15, copterY);

	// Draw Obstacle Wall
	setcolor(RED);
	rectangle(wallX, 50, wallX + 30, wallTop);
	rectangle(wallX, wallBottom, wallX + 30, 430);

	// Physics
	velocity += gravity;
	copterY += velocity;

	// Move Wall
	wallX -= 7;
	if (wallX < -30) {
	    wallX = 640;
	    wallTop = 80 + rand() % 150;
	    wallBottom = wallTop + 130;
	}

	// Check Collision with Ceiling/Floor
	if (copterY <= 50 || copterY + 15 >= 430) {
	    outtextxy(270, 240, "CRASHED INTO WALL!");
	    getch();
	    break;
	}

	// Check Collision with Obstacles
	if (wallX <= copterX + 30 && wallX + 30 >= copterX) {
	    if (copterY <= wallTop || copterY + 15 >= wallBottom) {
		outtextxy(270, 240, "CRASHED INTO OBSTACLE!");
		getch();
		break;
	    }
	}

	// Key Press
	if (kbhit()) {
	    key = getch();
	    if (key == ' ') velocity = -5; // Press Space to fly up
	    if (key == 27) break;         // ESC
	}

	delay(50);
    }

    closegraph();
}