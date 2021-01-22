#ifndef OBCHODNIK_H
#define OBCHODNIK_H

#include "definice.h"
#include "logovani.h"
#include "startaupravy.h"

#include "iostream"
#include "conio.h"
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "fstream"

using namespace std;
class obchodnik{
    public:
        string jmeno;
        float pocetpenez;
        int chytrost;
        float damaxpenez;
        void nastav_veci(float aktu_burza, float mena, int danyo){
        srand(time(NULL));
        pocetpenez = rand() % 300;
        if(pocetpenez > 300 || pocetpenez < 1){
            logv(EROR, "Error E8", "C:/projectant/logs/ErrorE8");
        }
        pocetpenez = pocetpenez * mena * aktu_burza;
        nastav_chytrost:
            chytrost = rand() % 3;
            if(chytrost != 1 && chytrost != 2 && chytrost != 3){
                logv(EROR, "Error E1", "C:/projectant/logs/errorE1.log");
                goto nastav_chytrost;
            }
            if(chytrost == 1){
                damaxpenez = pocetpenez;
            }else if(chytrost == 2){
                damaxpenez = pocetpenez/2;
            }else{
                damaxpenez = pocetpenez/5;
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
                logv(EROR, "Error E2", "C:/projectant/logs/errorE2.log");
                goto nastav_jmeno;
            }
        if(danyo == 1){
            vytvorsouborv("C:\\projectant\\data\\zapis1.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 2){
            vytvorsouborv("C:\\projectant\\data\\zapis2.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 3){
            vytvorsouborv("C:\\projectant\\data\\zapis3.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 4){
            vytvorsouborv("C:\\projectant\\data\\zapis4.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 5){
            vytvorsouborv("C:\\projectant\\data\\zapis5.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 6){
            vytvorsouborv("C:\\projectant\\data\\zapis6.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 7){
            vytvorsouborv("C:\\projectant\\data\\zapis7.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 8){
            vytvorsouborv("C:\\projectant\\data\\zapis8.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 9){
            vytvorsouborv("C:\\projectant\\data\\zapis9.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 10){
            vytvorsouborv("C:\\projectant\\data\\zapis10.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 11){
            vytvorsouborv("C:\\projectant\\data\\zapis11.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 12){
            vytvorsouborv("C:\\projectant\\data\\zapis12.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 13){
            vytvorsouborv("C:\\projectant\\data\\zapis13.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 14){
            vytvorsouborv("C:\\projectant\\data\\zapis14.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 15){
            vytvorsouborv("C:\\projectant\\data\\zapis15.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 16){
            vytvorsouborv("C:\\projectant\\data\\zapis16.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 17){
            vytvorsouborv("C:\\projectant\\data\\zapis17.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 18){
            vytvorsouborv("C:\\projectant\\data\\zapis18.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 19){
            vytvorsouborv("C:\\projectant\\data\\zapis19.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }else if(danyo == 20){
            vytvorsouborv("C:\\projectant\\data\\zapis20.txt", jmeno, chytrost, pocetpenez, damaxpenez);
        }
    }
};
#endif // OBCHODNIK_H
