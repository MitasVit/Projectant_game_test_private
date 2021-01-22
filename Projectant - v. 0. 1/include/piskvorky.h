#ifndef PISKVORKY_H
#define PISKVORKY_H


#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif // _GLIBCXX_IOSTREAM


#ifndef _WINDOWS_H
#include <windows.h>
#endif // _WINDOWS_H

using namespace std;

extern const int nemene_cislo = 1;//cislo se neda zmenit vubec
extern const int kolecko = 1;
extern const int krizek = 2;
extern const int player1 = 1;
extern const int player2 = 2;
extern int hrajici_hrac = 1;
extern int vyhral = 0;
extern string herni_pole[7][13] = {{"\u2554", "\u2550", "\u2550", "\u2550", "\u2566", "\u2550", "\u2550", "\u2550", "\u2566", "\u2550", "\u2550", "\u2550", "\u2557"},
{"\u2551", " ", " ", " ", "\u2551", " ", " ", " ", "\u2551", " ", " ", " ", "\u2551"},
{"\u2560", "\u2550", "\u2550", "\u2550", "\u256c", "\u2550", "\u2550", "\u2550", "\u256c", "\u2550", "\u2550", "\u2550", "\u2563"},
{"\u2551", " ", " ", " ", "\u2551", " ", " ", " ", "\u2551", " ", " ", " ", "\u2551"},
{"\u2560", "\u2550", "\u2550", "\u2550", "\u256c", "\u2550", "\u2550", "\u2550", "\u256c", "\u2550", "\u2550", "\u2550", "\u2563"},
{"\u2551", " ", " ", " ", "\u2551", " ", " ", " ", "\u2551", " ", " ", " ", "\u2551"},
{"\u255a", "\u2550", "\u2550", "\u2550", "\u2569", "\u2550", "\u2550", "\u2550", "\u2569", "\u2550", "\u2550", "\u2550", "\u255d"}};

extern int zahrana_pole[3][3] = {{0, 0, 0},
                        {0, 0, 0},
                        {0, 0, 0}};

 extern void vykresli_mrizku();

 extern void kolo(int _player, int error);

 extern void kontrola();

extern void piskvorky(){
    SetConsoleOutputCP(65001);
    while(vyhral == 0){
    kolo(hrajici_hrac,0);
    vykresli_mrizku();
    kontrola();
    }

    if(vyhral == 1){
        system("CLS");
        cout << "\nVyhral hrac 2\n";
        cout << "GRATULUJEME!!!";
    }else if(vyhral == 2){
        system("CLS");
        cout << "\nVyhral hrac 1\n";
        cout << "GRATULUJEME!!!";
    }
}

extern void vykresli_mrizku(){
    system("CLS");
    int cursory =2;
    for(int i = 0; i < 7; i++){
        for(int k = 0; k < 13; k++){

            if((i % 2) == 1){
            switch(k){

                case 2:if(zahrana_pole[cursory][2] == krizek){
                    cout << "X";
                    }else if(zahrana_pole[cursory][2] == kolecko){
                    cout << "O";
                    }else {
                    cout << " ";
                    }
                break;
                case 6:if(zahrana_pole[cursory][1] == krizek){
                    cout << "X";
                    }else if(zahrana_pole[cursory][1] == kolecko){
                    cout << "O";
                    }else {
                    cout << " ";
                    }

                break;
                case 10:if(zahrana_pole[cursory][0] == krizek){
                    cout << "X";
                    }else if(zahrana_pole[cursory][0] == kolecko){
                    cout << "O";
                    }else {
                    cout << " ";
                    }
                cursory -= 1;
                break;
                default:cout << herni_pole[i][k];
                break;

            }}else {
            cout << herni_pole[i][k];
            }

        }
        cout << endl;
    }
}
extern void kolo(int _player, int error){
    int policka;

    if(error == 1){
        cout << "\nZahrane policko je jiz obsazene zadejte jine policko: ";
        cin >> policka;
    }else if(error == 2){
    cout << "\nZahrane policko neexistuje, zahrajte policko v rozmezi 1 az 9: ";
    cin >> policka;

    }else{
    cout << "____________________________________";
    if(_player == player1){

        cout << "\n\t\n";
        cout << "Hrac 1";
    }else{
    cout << "\n\t\n";
    cout << "Hrac 2 ";

    }
      cout << "\n____________________________________";
    cout << "\nZadejte pole do ktereho chcete zahnout: ";
    cin >> policka;
    }
    switch(policka){
case 1: if(_player == player1){
if(zahrana_pole[2][2] == 0){
    zahrana_pole[2][2] = krizek;
}else{
kolo(player1, 1);
}
}else{
    if(zahrana_pole[2][2] == 0){
    zahrana_pole[2][2] = kolecko;
}
}
break;
case 2: if(_player == player1){
    if(zahrana_pole[2][1] == 0){
    zahrana_pole[2][1] = krizek;
}else{
kolo(player1, 1);
}
}else{
    if(zahrana_pole[2][1] == 0){
    zahrana_pole[2][1] = kolecko;
}
}
break;
case 3: if(_player == player1){
    if(zahrana_pole[2][0] == 0){
    zahrana_pole[2][0] = krizek;
}else{
kolo(player1, 1);
}
}else{
    if(zahrana_pole[2][0] == 0){
    zahrana_pole[2][0] = kolecko;
}
}
break;
case 4: if(_player == player1){
    if(zahrana_pole[1][2] == 0){
    zahrana_pole[1][2] = krizek;
}else{
kolo(player1, 1);
}
}else{
    if(zahrana_pole[1][2] == 0){
    zahrana_pole[1][2] = kolecko;
}
}
break;
case 5: if(_player == player1){
    if(zahrana_pole[1][1] == 0){
    zahrana_pole[1][1] = krizek;
}else{
kolo(player1, 1);
}
}else{
    if(zahrana_pole[1][1] == 0){
    zahrana_pole[1][1] = kolecko;
}
}
break;
case 6: if(_player == player1){
    if(zahrana_pole[1][0] == 0){
    zahrana_pole[1][0] = krizek;
}else{
kolo(player1, 1);
}
}else{
    if(zahrana_pole[1][0] == 0){
    zahrana_pole[1][0] = kolecko;
}
}
break;
case 7: if(_player == player1){
    if(zahrana_pole[0][2] == 0){
    zahrana_pole[0][2] = krizek;
}else{
kolo(player1, 1);
}
}else{
    if(zahrana_pole[0][2] == 0){
    zahrana_pole[0][2] = kolecko;
}
}
break;
case 8: if(_player == player1){
    if(zahrana_pole[0][1] == 0){
    zahrana_pole[0][1] = krizek;
}else{
kolo(player1, 1);
}
}else{
    if(zahrana_pole[0][1] == 0){
    zahrana_pole[0][1] = kolecko;
}
}
break;
case 9: if(_player == player1){
    if(zahrana_pole[0][0] == 0){
    zahrana_pole[0][0] = krizek;
}else{
kolo(player1, 1);
}
}else{
    if(zahrana_pole[0][0] == 0){
    zahrana_pole[0][0] = kolecko;
}
}
break;
default: if(_player == player1){
kolo(player1, 2);
}else{
kolo(player2, 2);
}
break;

}if(_player == player1){
    hrajici_hrac = player2;

}else{
hrajici_hrac = player1;
}
}

extern void kontrola(){
    for(int i = 0; i < 3; i++ ){
        if(zahrana_pole[i][0]== krizek && zahrana_pole[i][1] == krizek && zahrana_pole[i][2] == krizek){
            vyhral = krizek;
        }else if(zahrana_pole[i][0]== kolecko && zahrana_pole[i][1] == kolecko && zahrana_pole[i][2] == kolecko){
            vyhral = kolecko;
        }
    }for(int i = 0; i < 3; i++ ){
        if(zahrana_pole[0][i]== krizek && zahrana_pole[1][i] == krizek && zahrana_pole[2][i] == krizek){
            vyhral = krizek;
        }else if(zahrana_pole[0][0]== kolecko && zahrana_pole[1][1] == kolecko && zahrana_pole[2][2] == kolecko){
            vyhral = kolecko;
        }
    }if(zahrana_pole[0][0] == krizek && zahrana_pole[1][1] == krizek && zahrana_pole[2][2] == krizek){
vyhral = krizek;
}else if(zahrana_pole[0][0] == kolecko && zahrana_pole[1][1] == kolecko && zahrana_pole[2][2] == kolecko){
vyhral = kolecko;
}

 if(zahrana_pole[0][2] == krizek && zahrana_pole[1][1] == krizek && zahrana_pole[2][0] == krizek){
vyhral = krizek;
}else if(zahrana_pole[0][2] == kolecko && zahrana_pole[1][1] == kolecko && zahrana_pole[2][0] == kolecko){
vyhral = kolecko;
}
}

#endif // PISKVORKY_H
