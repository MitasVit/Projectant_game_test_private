
#include "../include/definice.h"
#include "../include/logovani.h"

#include "iostream"
#include "conio.h"
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "fstream"

using namespace std;

void nastav_veci(float aktu_burza, float mena, int danyo){
    string jmeno;
    float pocetpenez;
    int chytrost;
    float damaxpenez;
    srand(time(NULL));
    pocetpenez = rand() % 300;
    pocetpenez = pocetpenez * mena * aktu_burza;
    nastav_chytrost:
        chytrost = rand() % 3;
        if(chytrost != 1 && chytrost != 2 && chytrost != 3){
            log(ERROR, "Error E1", "C:/projectant/logs/errorE1.log");
            goto nastav_chytrost;
        }
        if(chytrost == 1){

        }else if(chytrost == 2){

        }else if(chytrost == 3){

        }else{
            log(ERROR, "Error E1s", "C:/projectant/logs/errorE1s.log");
            goto nastav_chytrost;
        }
    nastav_jmeno:
        int cislo = rand() % 10;
        if(cislo == 1){
            jmeno = "Nick";
        }else if(cislo == 2){
            jmeno = "Gustav";
        }else if(cislo == 3){
            jmeno = "Rick";
        }else if(cislo == 4){
            jmeno = "Jakub";
        }else if(cislo == 5){
            jmeno = "Wolfgang";
        }else if(cislo == 6){
            jmeno = "Lismond";
        }else if(cislo == 7){
            jmeno = "Barber";
        }else if(cislo == 8){
            jmeno = "Donald";
        }else if(cislo == 9){
            jmeno = "Joe";
        }else if(cislo == 10){
            jmeno = "Jorge";
        }else{
            log(ERROR, "Error E2", "C:/projectant/logs/errorE2.log");
            goto nastav_jmeno;
        }
    ofstream soubor3("zapis.txt");
    soubor3 << "[ " << jmeno << endl << pocetpenez << endl;
    soubor3 << chytrost << endl << damaxpenez << " ]";
    soubor3.close();

 }
