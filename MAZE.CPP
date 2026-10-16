#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 15
#define CELL_SIZE 30
#define OFFSET_X 80
#define OFFSET_Y 50

// 1 = Wall, 0 = Path, 2 = Player, 3 = Goal
int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 3, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Player initial coordinates
int playerX = 1, playerY = 1;

void drawCell(int r, int c, int color) {
    int x1 = OFFSET_X + (c * CELL_SIZE);
    int y1 = OFFSET_Y + (r * CELL_SIZE);
    int x2 = x1 + CELL_SIZE;
    int y2 = y1 + CELL_SIZE;

    setfillstyle(SOLID_FILL, color);
    bar(x1, y1, x2, y2);
    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);
}

void drawMaze() {
    int r, c;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            if (maze[r][c] == 1) {
                drawCell(r, c, BLUE);        // Wall
            } else if (maze[r][c] == 0) {
                drawCell(r, c, BLACK);       // Path
            } else if (maze[r][c] == 3) {
                drawCell(r, c, GREEN);       // Goal
            }
        }
    }
    // Draw Player
    drawCell(playerY, playerX, RED);         // Player
}

void main() {
    int gd = DETECT, gm;
    char ch;
    int newX, newY;

    // Initialize Turbo C graphics driver
    // Note: Adjust "C:\\TURBOC3\\BGI" if Turbo C is installed in a different folder
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Display Title
    setcolor(YELLOW);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(OFFSET_X, OFFSET_Y - 30, "TURBO C MAZE GAME");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(OFFSET_X, OFFSET_Y + (ROWS * CELL_SIZE) + 15, "Controls: W/A/S/D or Arrow Keys | ESC to Exit");

    drawMaze();

    while (1) {
        ch = getch();

        // Handle ESC key
        if (ch == 27) {
            break;
        }

        newX = playerX;
        newY = playerY;

        // Handle Arrow keys (extended keys send 0 or 224 first)
        if (ch == 0 || ch == -32) {
            ch = getch();
            if (ch == 72) newY--;      // Up Arrow
            else if (ch == 80) newY++; // Down Arrow
            else if (ch == 75) newX--; // Left Arrow
            else if (ch == 77) newX++; // Right Arrow
        }
        // Handle WASD keys
        else {
            if (ch == 'w' || ch == 'W') newY--;
            else if (ch == 's' || ch == 'S') newY++;
            else if (ch == 'a' || ch == 'A') newX--;
            else if (ch == 'd' || ch == 'D') newX++;
        }

        // Check Wall Collision
        if (maze[newY][newX] != 1) {
            // Clear old player position
            drawCell(playerY, playerX, BLACK);

            // Update player position
            playerX = newX;
            playerY = newY;

            // Check Win Condition
            if (maze[playerY][playerX] == 3) {
                drawCell(playerY, playerX, RED);
                setcolor(GREEN);
                settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
                outtextxy(OFFSET_X + 50, OFFSET_Y + (ROWS * CELL_SIZE) / 2, "YOU WIN!");
                getch();
                break;
            }

            // Draw player at new position
            drawCell(playerY, playerX, RED);
        }
    }

    closegraph();
}