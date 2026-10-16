#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

void main() {
    int gd = DETECT, gm;
    int ballX = 320, ballY = 240;
    int dx = 5, dy = 5;
    int p1Y = 200, p2Y = 200;
    char key;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    while (1) {
	// Clear screen
	cleardevice();

	// Draw middle line
	line(320, 0, 320, 480);

	// Draw Paddles
	rectangle(10, p1Y, 20, p1Y + 60);         // Player 1 (Left)
	rectangle(620, p2Y, 630, p2Y + 60);       // Player 2 (Right)

	// Draw Ball
	circle(ballX, ballY, 8);
	floodfill(ballX, ballY, WHITE);

	// Movement Logic
	ballX += dx;
	ballY += dy;

	// Bounce top/bottom
	if (ballY <= 10 || ballY >= 470) dy = -dy;

	// Bounce Paddles
	if (ballX <= 28 && ballY >= p1Y && ballY <= p1Y + 60) dx = -dx;
	if (ballX >= 612 && ballY >= p2Y && ballY <= p2Y + 60) dx = -dx;

	// Check Wall Collision (Game Over / Reset)
	if (ballX <= 0 || ballX >= 640) {
	    outtextxy(270, 240, "GAME OVER!");
	    getch();
	    break;
	}

	// Key Controls
	if (kbhit()) {
	    key = getch();
	    if (key == 'w' && p1Y > 10) p1Y -= 20;       // P1 Up
	    if (key == 's' && p1Y < 410) p1Y += 20;      // P1 Down
	    if (key == 'i' && p2Y > 10) p2Y -= 20;       // P2 Up
	    if (key == 'k' && p2Y < 410) p2Y += 20;      // P2 Down
	    if (key == 27) break;                        // ESC to exit
	}

	delay(50);
    }

    closegraph();
}