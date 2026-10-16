#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawBoard() {
    // Grid lines
    line(220, 100, 220, 400);
    line(320, 100, 320, 400);
    line(120, 200, 420, 200);
    line(120, 300, 420, 300);
}

void drawMark(int pos, int player) {
    int x = 170 + ((pos - 1) % 3) * 100;
    int y = 150 + ((pos - 1) / 3) * 100;

    if (player == 1) {
        // Draw 'X'
        line(x - 20, y - 20, x + 20, y + 20);
        line(x + 20, y - 20, x - 20, y + 20);
    } else {
        // Draw 'O'
        circle(x, y, 25);
    }
}

void main() {
    int gd = DETECT, gm;
    int board[9] = {0};
    int player = 1, choice, moves = 0;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    while (moves < 9) {
        cleardevice();
        drawBoard();

        // Redraw previous moves
        for (int i = 0; i < 9; i++) {
            if (board[i] != 0) drawMark(i + 1, board[i]);
        }

        gotoxy(1, 1);
        printf("Player %d's Turn. Enter position (1-9): ", player);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 9 && board[choice - 1] == 0) {
            board[choice - 1] = player;
            moves++;
            player = (player == 1) ? 2 : 1;
        }
    }

    cleardevice();
    drawBoard();
    for (int i = 0; i < 9; i++) {
        if (board[i] != 0) drawMark(i + 1, board[i]);
    }

    outtextxy(200, 430, "Game Over! Press any key.");
    getch();
    closegraph();
}