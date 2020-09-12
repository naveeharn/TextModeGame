// textModeGame_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y)
{
    gotoxy(x,y);
    std::cout<<("<=o=>");
}

void erase_ship(int x, int y) 
{
    gotoxy(x,y);
    std::cout << ("     ");
}

int main()
{
    char ch = ' ';
    int x = 38, y = 20;
    draw_ship(x, y);
    do {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 'a') {
                if (x > 0) {
                    erase_ship(x, y);
                    draw_ship(--x, y);
                }
            }
            if (ch == 'd') {
                if (x < 75) {
                    erase_ship(x, y);
                    draw_ship(++x, y);
                }
            }
            if (ch == 'w') {
                if (y > 0) {
                    erase_ship(x, y);
                    draw_ship(x, --y);
                }
            }
            if (ch == 's') {
                if (y < 25) {
                    erase_ship(x, y);
                    draw_ship(x, ++y);
                }
            }
            fflush(stdin);
        }
        Sleep(100);
    } while (ch != 'x');
    return 0;
}