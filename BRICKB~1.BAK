#include <graphics.h>
#include <conio.h>
#include <dos.h>

void main() {
    int gd = DETECT, gm;
    int ballX = 320, ballY = 350, dx = 4, dy = -4;
    int paddleX = 280, paddleW = 80;
    int bricks[3][6];
    int i, j, score = 0;
    char key;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Initialize bricks array (1 = visible)
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 6; j++) {
            bricks[i][j] = 1;
        }
    }

    while (1) {
        cleardevice();

        // Draw Bricks
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 6; j++) {
                if (bricks[i][j] == 1) {
                    int bx = 50 + j * 95;
                    int by = 40 + i * 30;
                    rectangle(bx, by, bx + 85, by + 20);

                    // Check Ball collision with Brick
                    if (ballX >= bx && ballX <= bx + 85 && ballY >= by && ballY <= by + 20) {
                        bricks[i][j] = 0;
                        dy = -dy;
                        score += 10;
                    }
                }
            }
        }

        // Draw Paddle and Ball
        rectangle(paddleX, 440, paddleX + paddleW, 450);
        circle(ballX, ballY, 6);

        // Move Ball
        ballX += dx;
        ballY += dy;

        // Bounce Walls
        if (ballX <= 10 || ballX >= 630) dx = -dx;
        if (ballY <= 10) dy = -dy;

        // Bounce Paddle
        if (ballY >= 434 && ballX >= paddleX && ballX <= paddleX + paddleW) {
            dy = -dy;
        }

        // Bottom Wall Collision (Game Over)
        if (ballY >= 470) {
            outtextxy(280, 240, "GAME OVER");
            getch();
            break;
        }

        // Key Controls
        if (kbhit()) {
            key = getch();
            if (key == 75 && paddleX > 10) paddleX -= 25;       // Left Arrow
            if (key == 77 && paddleX < 550) paddleX += 25;      // Right Arrow
            if (key == 27) break;                              // ESC Key
        }

	delay(40);
    }

    closegraph();
}