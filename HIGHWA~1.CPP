#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

void drawCar(int x, int y, int color) {
    setcolor(color);
    rectangle(x, y, x + 30, y + 50);          // Body
    rectangle(x + 5, y + 10, x + 25, y + 35); // Cabin
}

void main() {
    int gd = DETECT, gm;
    int myX = 300, myY = 380;
    int enemyX = 200 + (rand() % 3) * 80, enemyY = 0;
    int score = 0;
    char key;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    while (1) {
        cleardevice();

        // Draw Road Borders
        setcolor(WHITE);
        line(180, 0, 180, 480);
        line(460, 0, 460, 480);

        // Draw Player and Enemy Cars
        drawCar(myX, myY, CYAN);
        drawCar(enemyX, enemyY, RED);

        // Move Enemy Car
        enemyY += 8;

        // Reset Enemy Car
        if (enemyY > 480) {
            enemyY = 0;
            enemyX = 200 + (rand() % 3) * 80;
            score += 10;
        }

        // Collision Check
        if (abs(myX - enemyX) < 30 && abs(myY - enemyY) < 50) {
            outtextxy(270, 240, "CRASHED! GAME OVER!");
            getch();
            break;
        }

        // Controls
        if (kbhit()) {
            key = getch();
            if (key == 75 && myX > 200) myX -= 40;  // Left Arrow
            if (key == 77 && myX < 420) myX += 40;  // Right Arrow
            if (key == 27) break;                   // ESC Key
        }

	delay(40);
    }

    closegraph();
}