#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

void main() {
    int gd = DETECT, gm;
    int arrowX = 50, arrowY = 240, arrowFlying = 0;
    int targetY = 50, targetDir = 4;
    int score = 0;
    char scoreMsg[30];

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    while (1) {
        cleardevice();

        // Draw Target (Moving up and down on the right)
        setcolor(RED);
        circle(580, targetY, 20);
        setcolor(YELLOW);
        circle(580, targetY, 10);

        // Draw Bow & Arrow
        setcolor(WHITE);
        if (!arrowFlying) {
            arrowY = 240; // Aim position
            line(30, arrowY - 30, 30, arrowY + 30); // Bow
            line(30, arrowY - 30, 50, arrowY);
            line(30, arrowY + 30, 50, arrowY);
        }

        // Draw Arrow
        line(arrowX, arrowY, arrowX + 25, arrowY);
        line(arrowX + 20, arrowY - 3, arrowX + 25, arrowY);
        line(arrowX + 20, arrowY + 3, arrowX + 25, arrowY);

        // Move Target
        targetY += targetDir;
        if (targetY <= 30 || targetY >= 450) targetDir = -targetDir;

        // Move Arrow if Fired
        if (arrowFlying) {
            arrowX += 12;

            // Check Hit Target
            if (arrowX + 25 >= 560 && abs(arrowY - targetY) <= 20) {
                score += 10;
                arrowFlying = 0;
                arrowX = 50;
            }

            // Missed Target
            if (arrowX > 640) {
                arrowFlying = 0;
                arrowX = 50;
            }
        }

        // Controls
        if (kbhit()) {
            char key = getch();
            if (key == ' ' && !arrowFlying) arrowFlying = 1; // Release Arrow
            if (key == 27) break;                            // ESC
        }

	delay(30);
    }

    closegraph();
}