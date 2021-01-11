#ifndef CLOVEKHRAC_H
#define CLOVEKHRAC_H

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
class hrac{
    public:
        string jmeno;
        float pocetpenez;
        int zeme;
        string prace;
        float plat;
        void nastavPlat(float _plat, float mena, float aktu_burza){
            plat = _plat * mena * aktu_burza;
        }
        void nastavJmeno(string _jmeno){
            jmeno = _jmeno;
        }
        void nastavPocetPenez(float _pocetpenez, float aktu_burza, float mena){
            pocetpenez = _pocetpenez * mena * aktu_burza;
        }
        void nastavVse(string _jmeno, string _prace, float _pocetpenez, float _plat, float mena, float aktu_burza){
            pocetpenez = _pocetpenez * mena * aktu_burza;
            jmeno = _jmeno;
            prace = _prace;
            plat = _plat * mena * aktu_burza;
        }
        void ulozVse(const char *souborCesta){
            ofstream uklsou(souborCesta);
            uklsou << pocetpenez << endl;
            uklsou << jmeno << endl;
            uklsou << prace <<endl;
            uklsou << plat << endl;
            uklsou.close();
        }
        void nastavUlozVse(string _jmeno,string _prace, float _pocetpenez, float _plat,float aktu_burza, float mena, const char *souborCesta){
            ofstream uklsou(souborCesta);
            pocetpenez = _pocetpenez * mena * aktu_burza;
            jmeno = _jmeno;
            prace = _prace;
            plat = _plat * aktu_burza * mena;
            uklsou << pocetpenez << endl;
            uklsou << jmeno << endl;
            uklsou << prace << endl;
            uklsou.close();
        }

};
#endif // OBCHODNIK_H
