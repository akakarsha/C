#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

#define MAX 100

int snakeX[MAX], snakeY[MAX];
int length;
int foodX, foodY;
int direction;
int score;

void drawFood()
{
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    circle(foodX, foodY, 5);
    floodfill(foodX, foodY, RED);
}

void generateFood()
{
    foodX = 60 + (rand() % 520);
    foodY = 80 + (rand() % 320);

    /* Keep food aligned to grid */
    foodX = (foodX / 10) * 10;
    foodY = (foodY / 10) * 10;
}

void drawSnake()
{
    int i;

    for(i = 0; i < length; i++)
    {
        if(i == 0)
        {
            setcolor(YELLOW);
            setfillstyle(SOLID_FILL, YELLOW);
        }
        else
        {
            setcolor(GREEN);
            setfillstyle(SOLID_FILL, GREEN);
        }

        rectangle(snakeX[i], snakeY[i],
                  snakeX[i] + 10, snakeY[i] + 10);

        floodfill(snakeX[i] + 2,
                  snakeY[i] + 2,
                  i == 0 ? YELLOW : GREEN);
    }
}

void moveSnake()
{
    int i;

    /* Move body */
    for(i = length - 1; i > 0; i--)
    {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    /* Move head */
    if(direction == 1)
        snakeX[0] += 10;       /* Right */

    if(direction == 2)
        snakeX[0] -= 10;       /* Left */

    if(direction == 3)
        snakeY[0] -= 10;       /* Up */

    if(direction == 4)
        snakeY[0] += 10;       /* Down */
}

int checkCollision()
{
    int i;

    /* Wall collision */
    if(snakeX[0] <= 20 ||
       snakeX[0] >= 610 ||
       snakeY[0] <= 60 ||
       snakeY[0] >= 410)
    {
        return 1;
    }

    /* Self collision */
    for(i = 1; i < length; i++)
    {
        if(snakeX[0] == snakeX[i] &&
           snakeY[0] == snakeY[i])
        {
            return 1;
        }
    }

    return 0;
}

void main()
{
    int gd = DETECT, gm;
    char key;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    randomize();

    /* Initial snake */
    length = 5;
    score = 0;
    direction = 1;

    snakeX[0] = 300;
    snakeY[0] = 200;

    snakeX[1] = 290;
    snakeY[1] = 200;

    snakeX[2] = 280;
    snakeY[2] = 200;

    snakeX[3] = 270;
    snakeY[3] = 200;

    snakeX[4] = 260;
    snakeY[4] = 200;

    generateFood();

    while(1)
    {
        cleardevice();

        /* Game border */
        setcolor(WHITE);
        rectangle(20, 60, 620, 420);

        /* Title */
        setcolor(CYAN);
        outtextxy(250, 20, "SNAKE GAME");

        /* Score */
        setcolor(WHITE);
        outtextxy(30, 35, "Score:");

        /* Convert score to text */
        {
            char scoreText[10];
            sprintf(scoreText, "%d", score);
            outtextxy(80, 35, scoreText);
        }

        drawFood();
        drawSnake();

        /* Keyboard input */
        if(kbhit())
        {
            key = getch();

            if(key == 27)
                break;

            /* Prevent reverse direction */
            if(key == 'd' && direction != 2)
                direction = 1;

            if(key == 'a' && direction != 1)
                direction = 2;

            if(key == 'w' && direction != 4)
                direction = 3;

            if(key == 's' && direction != 3)
                direction = 4;
        }

        moveSnake();

        /* Check food */
        if(snakeX[0] == foodX &&
           snakeY[0] == foodY)
        {
            if(length < MAX)
                length++;

            score += 10;

            /* Put new tail at previous tail position */
            snakeX[length - 1] = snakeX[length - 2];
            snakeY[length - 1] = snakeY[length - 2];

            generateFood();
        }

        /* Collision */
        if(checkCollision())
        {
            cleardevice();

            setcolor(RED);
            outtextxy(250, 180, "GAME OVER!");

            setcolor(YELLOW);
            outtextxy(250, 210, "Your Score:");

            {
                char finalScore[10];
                sprintf(finalScore, "%d", score);
                outtextxy(330, 210, finalScore);
            }

            setcolor(WHITE);
            outtextxy(210, 250, "Press any key to exit");

            getch();
            break;
        }

        delay(100);
    }

    closegraph();
}