#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int player, computer;

    clrscr();

    randomize();

    cout << "============================\n";
    cout << "    ROCK PAPER SCISSORS\n";
    cout << "============================\n\n";

    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n\n";

    cout << "Enter your choice: ";
    cin >> player;

    computer = random(3) + 1;

    cout << "\nComputer chose: ";

    switch(computer)
    {
        case 1:
            cout << "Rock";
            break;

        case 2:
            cout << "Paper";
            break;

        case 3:
            cout << "Scissors";
            break;
    }

    cout << "\n";

    if(player == computer)
    {
        cout << "\nDRAW!";
    }
    else if((player == 1 && computer == 3) ||
            (player == 2 && computer == 1) ||
            (player == 3 && computer == 2))
    {
        cout << "\nYOU WIN!";
    }
    else
    {
        cout << "\nCOMPUTER WINS!";
    }

    getch();
}