#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
using namespace std;

const int width = 40, heigth = 20;
int snake[heigth*width][2];
char field[heigth][width];

void gotoxy(int x, int y);
void drawField();

int main()
{
    int lenght = 4, direction = 1, foodX, foodY;

    snake [0][0] = heigth / 2; snake [0][1] = width / 2;

    for(int i = 1; i < lenght; i++) {
        snake[i][0] = snake[i-1][0] + 1;
        snake[i][1] = snake[0][1];
    }

    while(1) {
        for(int y = 0; y < heigth; y++) {
            for(int x = 0; y < width; x++) {
                if(y == 0 || y == heigth - 1 || x == 0 || x == width - 1)
                    field[y][x] = '#'; else field[y][x] = ' ';
            }
        }
        for(int l = 0; l < lenght; l++) {
                field [snake[l][0]][snake[l][1]] = '@';
        }
        for(int i = lenght - 1; i > 0; i--) {
            snake[i][0] = snake[i - 1][0];
            snake[i][1] = snake[i - 1][1];
        }
        switch(direction) {
            case 1: snake[0][0]--; break;
            case 2: snake[0][1]++; break;
            case 3: snake[0][0]++; break;
            case 4: snake[0][1]--; break;
        }

        if(GetKeyState('A') & 0x8000)

        drawField();
    }

    return 0;
}


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawField() {
    gotoxy(0, 0);
    for(int y = 0; y < heigth; y++) {
        for(int x = 0; y < width; x++) {
            cout << field[heigth][width];
        }
        cout << endl;
    }
}
