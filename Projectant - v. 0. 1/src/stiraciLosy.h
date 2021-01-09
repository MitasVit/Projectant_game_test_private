#ifndef STIRACILOSY_H
#define STIRACILOSY_H

#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "../include/stiraciLosy.h"


using namespace std;

void stastnych10(int penize){
    penize = penize - 35;
    int vyhra;
    int cis1;
    int cis2;
    int cis3;
    int cis4;
    int cis5;
    int cis6;
    int cis7;
    int cis8;
    int cis9;
    int cis10;
    srand(time(NULL));
    cis1 = rand() % 40;
    cis2 = rand() % 40;
    cis3 = rand() % 40;
    cis4 = rand() % 40;
    cis5 = rand() % 40;
    cis6 = rand() % 40;
    cis7 = rand() % 40;
    cis8 = rand() % 40;
    cis9 = rand() % 40;
    cis10 = rand() % 40;
    cout << endl << endl << "Stastnych 10 - enter pro dalsi cislo" <<endl << endl;
    switch(cis1){
    case 5:
        {
            cout << "+20" << endl;
            vyhra = 20;
            getch();
            break;
        }
    case 10:
        {
            cout << "+40" << endl;
            vyhra = 40;
            getch();
            break;
        }
    default:
        {
            cout << "+0" << endl;
            vyhra = 0;
            getch();
            break;
        }
    }
    switch(cis2){
    case 5:
        {
            cout << "+20" << endl;
            vyhra = vyhra + 20;
            getch();
            break;
        }
    case 10:
        {
            cout << "+40" << endl;
            vyhra = vyhra + 40;
            getch();
            break;
        }
    default:
        {
            cout << "+0" << endl;
            getch();
            break;
        }
    }
    switch(cis3){
    case 5:
        {
            cout << "+20" << endl;
            vyhra = vyhra + 20;
            getch();
            break;
        }
    case 10:
        {
            cout << "+40" << endl;
            vyhra = vyhra + 40;
            getch();
            break;
        }
    default:
        {
            cout << "+0" << endl;
            getch();
            break;
        }
    }switch(cis4){
    case 5:
        {
            cout << "+20" << endl;
            vyhra = vyhra + 20;
            getch();
            break;
        }
    case 10:
        {
            cout << "+40" << endl;
            vyhra = vyhra + 40;
            getch();
            break;
        }
    default:
        {
            cout << "+0" << endl;
            getch();
            break;
        }
    }switch(cis5){
    case 5:
        {
            cout << "+20" << endl;
            vyhra = vyhra + 20;
            getch();
            break;
        }
    case 10:
        {
            cout << "+40" << endl;
            vyhra = vyhra + 40;
            getch();
            break;
        }
    default:
        {
            cout << "+0" << endl;
            getch();
            break;
        }
    }switch(cis6){
    case 5:
        {
            cout << "+20" << endl;
            vyhra = vyhra + 20;
            getch();
            break;
        }
    case 10:
        {
            cout << "+40" << endl;
            vyhra = vyhra + 40;
            getch();
            break;
        }
    default:
        {
            cout << "+0" << endl;
            getch();
            break;
        }
    }switch(cis7){
    case 5:
        {
            cout << "+20" << endl;
            vyhra = vyhra + 20;
            getch();
            break;
        }
    case 10:
        {
            cout << "+40" << endl;
            vyhra = vyhra + 40;
            getch();
            break;
        }
    default:
        {
            cout << "+0" << endl;
            getch();
            break;
        }
    }switch(cis8){
    case 5:
        {
            cout << "+20" << endl;
            vyhra = vyhra + 20;
            getch();
            break;
        }
    case 10:
        {
            cout << "+40" << endl;
            vyhra = vyhra + 40;
            getch();
            break;
        }
    default:
        {
            cout << "+0" << endl;
            getch();
            break;
        }
    }switch(cis9){
    case 5:
        {
            cout << "+20" << endl;
            vyhra = vyhra + 20;
            getch();
            break;
        }
    case 10:
        {
            cout << "+40" << endl;
            vyhra = vyhra + 40;
            getch();
            break;
        }
    default:
        {
            cout << "+0" << endl;
            getch();
            break;
        }
    }switch(cis10){
    case 5:
        {
            cout << "+20" << endl;
            vyhra = vyhra + 20;
            getch();
            break;
        }
    case 10:
        {
            cout << "+40" << endl;
            vyhra = vyhra + 40;
            getch();
            break;
        }
    default:
        {
            cout << "+0" << endl;
            getch();
            break;
        }
    }
    penize = penize + vyhra;
    cout << endl << "celkova vyhra: " << vyhra <<endl;
    cout << "Momentalni pocet $ : " << penize;
    if(penize < 40){
        MessageBox(NULL, "Upozorneni mate mene nez 40 penez", "upozorneni", MB_OK);
    }
}

#endif
