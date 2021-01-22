#ifndef HERNI_MENU_H
#define HERNI_MENU_H

#include <iostream>
#include <nabarvy>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>

/**
#include "herni_menu.h

bool test2 = true;
setcursor(0,0);
cout << "     MAIN MENU" << endl;
herniMenu(0);
gotoxy(20, 1); while(test2 == true){cout << "enter a number: ";char testik = getche();setcursor(0,0);system("CLS");cout << "     MAIN MENU" << endl;herniMenu(testik);gotoxy(20, 1);}

*/

using namespace std;
COORD cursorPos;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int x, int y){
    cursorPos.X = x;
    cursorPos.Y = y;
    SetConsoleCursorPosition(console, cursorPos);
}
void setcursor(bool visible, DWORD size1){
    if(size1 == 0)
        size1 = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size1;
    SetConsoleCursorInfo(console, &lpCursor);
}
void herniMenu(char current){
    cout << "-------------------" << endl;
    if(current == '1'){cout << "|";nabarvy(ZELENA, "     1. Shop     ");cout << "|" << endl;}else{cout << "|     1. Shop     |" << endl;}
    cout << "|-----------------|" << endl;
    if(current == '2'){cout << "|";nabarvy(ZELENA, "   2. Inventory  ");cout << "|" << endl;}else{cout << "|   2. Inventory  |" << endl;}
    cout << "|-----------------|" << endl;
    if(current == '3'){cout << "|";nabarvy(ZELENA, "   3. Business   ");cout << "|" << endl;}else{cout << "|   3. Business   |" << endl;}
    cout << "|-----------------|" << endl;
    if(current == '4'){cout << "|";nabarvy(ZELENA, "    4. Games     ");cout << "|" << endl;}else{cout << "|    4. Games     |" << endl;}
    cout << "|-----------------|" << endl;
    if(current == '5'){cout << "|";nabarvy(ZELENA, "    5. Bonus     ");cout << "|" << endl;}else{cout << "|    5. Bonus     |" << endl;}
    cout << "|-----------------|" << endl;
    if(current == '6'){cout << "|";nabarvy(ZELENA, "     6. Help     ");cout << "|" << endl;}else{cout << "|     6. Help     |" << endl;}
    cout << "|-----------------|" << endl;
    if(current == '7'){cout << "|";nabarvy(ZELENA, "   7. Settings   ");cout << "|" << endl;}else{cout << "|   7. Settings   |" << endl;}
    cout << "|-----------------|" << endl;
    if(current == '8'){cout << "|";nabarvy(ZELENA, "     8. Quit     ");cout << "|" << endl;}else{cout << "|     8. Quit     |" << endl;}
    cout << "-------------------" << endl;
}
#endif // HERNI_MENU_H
