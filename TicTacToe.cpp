#include <iostream>
#include <stdlib.h>

using namespace std;

char pole[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

void viewPole(string name1, string name2);

bool isWinner(char n);

int main()
{
    string name1, name2;
    int answer;

    system("color 02");
    cout << "\t\tTicTacToe\n\n";

    cout << "Please enter name for first player: ";
    cin >> name1;
    system("cls");

    cout << "Please enter name second player: ";
    cin >> name2;
    system("cls");

    while (true) {
        viewPole(name1, name2);
        cout << name1 << " your course(0-8): ";
        cin >> answer;
        pole[answer] = 'X';
        system("cls");

        if (isWinner('X')) {
            viewPole(name1, name2);
            cout << name1 + " is Winner\n";
            break;
        }

        viewPole(name1, name2);
        cout << name2 << " your course(0-8): ";
        cin >> answer;
        pole[answer] = 'O';
        system("cls");

        if (isWinner('O')) {
            viewPole(name1, name2);
            cout << name2 + " is Winner\n";
            break;
        }
    }
    return 0;
}

void viewPole(string name1, string name2) {
    cout << name1 + "(X)\t" << name2 + "(O)\n";

    for (int i = 0; i < 9; i++) {
         if (i == 0) {
            cout << " ~~~ ~~~ ~~~ \n~ "  << pole[i] << " ~ ";
         } else if (i == 2 || i == 5) {
            cout << pole[i] << " ~\n ~~~ ~~~ ~~~ \n~ ";
         } else if (i == 8) {
            cout << pole[i] << " ~\n ~~~ ~~~ ~~~\n";
         } else {
             cout << pole[i] << " ~ ";
         }
    }
}

bool isWinner(char n) {
    if ((pole[0] == n && pole[4] == n && pole[8] == n) ||
        (pole[2] == n && pole[4] == n && pole[6] == n) ||
        (pole[0] == n && pole[1] == n && pole[2] == n) ||
        (pole[3] == n && pole[4] == n && pole[5] == n) ||
        (pole[6] == n && pole[7] == n && pole[8] == n) ||
        (pole[0] == n && pole[3] == n && pole[6] == n) ||
        (pole[1] == n && pole[4] == n && pole[7] == n) ||
        (pole[2] == n && pole[5] == n && pole[8] == n)) {
            return true;
        }

        return false;
}
