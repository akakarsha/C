#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int number, guess;
    int attempts = 0;

    clrscr();

    randomize();
    number = random(100) + 1;

    cout << "============================\n";
    cout << "     NUMBER GUESSING GAME\n";
    cout << "============================\n";
    cout << "Guess a number between 1 and 100\n\n";

    do
    {
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        if (guess > number)
            cout << "Too high!\n";
        else if (guess < number)
            cout << "Too low!\n";
        else
            cout << "\nCongratulations!\n";

    } while (guess != number);

    cout << "You found it in " << attempts << " attempts.";

    getch();
}