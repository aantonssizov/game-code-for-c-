#include <iostream>

using namespace std;

char pole[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

void viewPole(string name1, string name2);

int main()
{
    string name1, name2;
    int answer;

    cout << "\t\tTicTacToe\n\n";

    cout << "Please enter name for first player: ";
    cin >> name1;

    cout << "Please enter name for second player: ";
    cin >> name2;

    viewPole(name1, name2);

    return 0;
}

void viewPole(string name1, string name2) {
    cout << name1 << "(X)\t" << name2 << endl;
    for(int i = 0; i < 9; i++) {
        if(i == 0) {
            cout << " ~~~ ~~~ ~~~\n~ ";
        }

        if(i == 2 || i == 5) {
            cout << pole[i] << " ~\n ~~~ ~~~ ~~~ \n~ ";
        } else {
            cout << pole[i] << " ~ ";
        }
    }
}
