#include "../include/Prevod.h"
#include <iostream>

using namespace std;


Prevod::Prevodik(int mena, int burza, int pocet)
{
    int vysledek;

    if(burza == NORMAL){

        if(mena == ME_CZK){

            vysledek = burza * pocet * ME_CZK;
            return vysledek;

        }else if(mena == ME_EURO){

            vysledek = burza * pocet * ME_EUROc;
            return vysledek;

        }else if(mena == ME_JEN){

            vysledek = burza * pocet * ME_JENc;
            return vysledek;

        }else if(mena == ME_USDOLAR){

            vysledek = burza * pocet * ME_USDOLARc;
            return vysledek;

        }else{

            vysledek = 0;
            return vysledek;

        }

    }else{

        vysledek = 0;
        return vysledek;

    }
}
