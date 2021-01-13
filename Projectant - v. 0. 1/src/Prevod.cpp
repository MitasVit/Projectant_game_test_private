#include "../include/Prevod.h"
#include <iostream>

using namespace std;

namespace prevod{
    Prevodik(float mena, float burza, float penize){
        float vysledek;
        vysledek =  burza* penize * mena;
        return vysledek;
    }
}
