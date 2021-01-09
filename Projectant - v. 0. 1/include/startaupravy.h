#ifndef STARTAUPRAVY_H
#define STARTAUPRAVY_H


#include <windows.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <wchar.h>
#include "definice.h"
#include "logovani.h"
#include <fstream>
#include "nabarvy.h"
/**
*______FUNKCE_________
*
*CEKEJ()
*VYTVORSOUBOR()
*NASTAV()
*VYTVORSOUBOR_PRACE()
*STRUCT MENU_ARG
*LOGOSS()
*LOADING()
*START()
*MENU()
*NOVAVERZE()
*SCRIPTOTXT()
*SCRIPTOEXE()
*OTEVRISCRIPTOTXT()
*OTEVRISCRIPTOEXE()
*VYTVORWEB()
*OTEVRIWEB()
*NABARVY()
*/
void cekej(int sekundy)
{
    clock_t start = clock();
    clock_t perioda = sekundy * CLOCKS_PER_SEC;
    clock_t uplynulo;

    do {
        uplynulo = clock() - start;
    } while(uplynulo < perioda);
}
void vytvorsoubor(const char *cesta, string zprava1, int zprava2, float zprava3, float zprava4){
    ofstream soubor1(cesta);
    soubor1 << zprava1 << endl << zprava2 << endl << zprava3 << endl << zprava4;
    soubor1.close();
    ifstream kontrola(cesta);
    if(kontrola.is_open()){
        kontrola.close();
    }else{
        log(EROR, "Error E3", "C:\\projectant\\logs\\errorE3.log");
        kontrola.close();
    }

}
void nastav(bool start_jazyk){
   CreateDirectory("C:\\projectant", NULL);
   CreateDirectory("C:\\projectant\\logs", NULL);
   CreateDirectory("C:\\projectant\\data", NULL);
   CreateDirectory("C:\\projectant\\homepage", NULL);
   CreateDirectory("C:\\projectant\\startScript", NULL);
   CreateDirectory("C:\\projectant\\trade_data", NULL);
   if(start_jazyk == true){
        setlocale(LC_ALL, "english");
        SetConsoleCP(1250);
        SetConsoleOutputCP(1250);
   }
   system("TITLE Projectant game v. 1.0.0");
}
void vytvorsoubor_prace(){
    ofstream prace("C:/projectant/trade_data/traders.projectant");
    prace << "engineer" << endl;
    prace << SALARY_ENGINEER << endl;

    prace << "servicer" << endl;
    prace << SALARY_SERVICER << endl;

    prace << "dustman" << endl;
    prace << SALARY_DUSTMAN << endl;

    prace << "cleaner" <<endl;
    prace << SALARY_CLEANER << endl;

    prace.close();
}
struct menu_arg{
    string jmenoa;
    int zemea;
    string pracea;
    float plata;
};

void logoSS(){
    nabarvy(CERVENA, "\t __          __    __   __       __  _____          _        ___");
    cout << endl;
    nabarvy(CERVENA, "\t|    |   |  |  |  |    |  |     |      |    |   |  | \\   |  |   |");
    cout << endl;
    nabarvy(CERVENA, "\t|__  |   |  |__|  |__  |__|     |__    |    |   |  |  |  |  |   |");
    cout << endl;
    nabarvy(CERVENA, "\t   | |   |  |     |    |\\          |   |    |   |  |  |  |  |   |");
    cout << endl;
    nabarvy(CERVENA, "\t___| |___|  |     |__  | \\      ___|   |    |___|  |_/   |  |___|");
    cout << endl;
}
void loading(){
    int procent = 0;
    logoSS();
    while(procent < 100){
        srand(time(NULL));
        int cislo = rand() % 15;
        if(procent < 90){
            procent = procent + cislo;
        }else{
            procent= procent + 1;
        }
        cout << endl;
        cout << "Loading ";
        cout << procent << "%";
        cekej(1);
    }
    if(procent > 100){
        log(EROR, "Error E9", "C:/projectant/Logs/ErrorE9.log");
    }
    cout << endl ;
    nabarvy(MODRA, "Loading success!");
    cout << endl;
    nabarvy(CERVENA, "Press any key to continue...");
    getch();
}

void start(menu_arg menu2){
    ifstream kontrola_en("C:/projectant/data/en_seting.txt");
    if(kontrola_en.is_open()){
        string te_jmeno;
        int te_zeme;
        int test;
        getline(kontrola_en, te_jmeno);
        kontrola_en >> te_zeme;
        if(te_zeme != 0){
            cout << "Do you want to read: "<< endl;
            cout << "name: "<< te_jmeno << endl;
            cout << "country: " << te_zeme << endl;
            cout << "1 -> yes"<< endl;
            cout << "2 -> no" << endl;
            cin >> test;
            if(test == 1){
                cout << endl << "reading the data...";
                cout << endl << "readed -> press enter to continue";
                getch();
                system("CLS");
            }else{
                cout << endl << "ok, reading excepted";
                cout << endl << "press enter to continue";
                getch();
                system("CLS");
                cout << "Enter a name: ";
                cin >> menu2.jmenoa;
                cout << "Enter a country: " << endl;
                cout << "1 -> Czech Republic" << endl;
                cout << "2 -> England" << endl;
                cin >> menu2.zemea;
                ifstream worker("C:/projectant/trade_data/traders.projectant");
                string work1;
                string salary1;
                string work2;
                string salary2;
                string work3;
                string salary3;
                string work4;
                string salary4;
                string work5;
                string salary5;
                string work6;
                string salary6;
                getline(worker, work1);
                getline(worker, salary1);
                getline(worker, work2);
                getline(worker, salary2);
                getline(worker, work3);
                getline(worker, salary3);
                getline(worker, work4);
                getline(worker, salary4);
                getline(worker, work5);
                getline(worker, salary5);
                getline(worker, work6);
                getline(worker, salary6);
                cout << "Choose a work" << endl;
                cout << "1 -> " << work1 << endl;
                cout << "\tsalary: " << salary1 << endl;
                cout << "2 -> " << work2 << endl;
                cout << "\tsalary: " << salary2 << endl;
                cout << "3 -> " << work3 << endl;
                cout << "\tsalary: " << salary3 << endl;
                cout << "4 -> " << work4 << endl;
                cout << "\tsalary: " << salary4 << endl;
                cout << "5 -> " << work5 << endl;
                cout << "\tsalary: " << salary5 << endl;
                cout << "6 -> " << work6 << endl;
                cout << "\tsalary: " << salary6 << endl;
                int cislo;
                cin >>cislo;
                if(cislo == 1){
                    menu2.pracea = "engineer";
                    menu2.plata = SALARY_ENGINEER;
                }
                    vytvorsoubor("C:/projectant/data/en_seting.txt", menu2.jmenoa, menu2.zemea, menu2.plata, NULL);
            }
    }else{
        cout << "Enter a name: ";
        cin >> menu2.jmenoa;
        cout << "Enter a country: " << endl;
        cout << "1 -> Czech Republic" << endl;
        cout << "2 -> England" << endl;
        cin >> menu2.zemea;
        cout << "Choose a work" << endl;
        cout << "1 -> engineer" << endl;
        int cislo;
        cin >>cislo;
        if(cislo == 1){
            menu2.pracea = "engineer";
            menu2.plata = 50;
        }
        vytvorsoubor("C:/projectant/data/en_seting.txt", menu2.jmenoa, menu2.zemea, menu2.plata, NULL);
    }
    }else{
        cout << "Enter a name: ";
        cin >> menu2.jmenoa;
        cout << "Enter a country: " << endl;
        cout << "1 -> Czech Republic" << endl;
        cout << "2 -> England" << endl;
        cin >> menu2.zemea;
        cout << "Choose a work" << endl;
        cout << "1 -> engineer" << endl;
        int cislo;
        cin >>cislo;
        if(cislo == 1){
            menu2.pracea = "engineer";
            menu2.plata = 50;
        }
        vytvorsoubor("C:/projectant/data/en_seting.txt", menu2.jmenoa, menu2.zemea, menu2.plata, NULL);
    }
}

void menu(menu_arg menu1){
    loading();
    system("CLS");
    menicko:
    nabarvy(ZELENA, "\t __    __    ___          __   ___  _____   ___            _____");
    cout << endl;
    nabarvy(ZELENA, "\t|  |  |  |  |   |     |  |    |       |    |   |  |\\   |    |  ");
    cout << endl;
    nabarvy(ZELENA, "\t|__|  |__|  |   |     |  |__  |       |    |___|  | \\  |    |  ");
    cout << endl;
    nabarvy(ZELENA, "\t|     |\\    |   |     |  |    |       |    |   |  |  \\ |    |  ");
    cout << endl;
    nabarvy(ZELENA, "\t|     | \\   |___|   \\_/  |__  |___    |    |   |  |   \\|    |  ");
    cout << endl;
    cout << endl;
    int menu_cislo;
    cout << "1 -> Start" << endl;
    cout << "2 -> Enter a code" << endl;
    cout << "3 -> Add plugin" << endl;
    cout << "4 -> Help" << endl;
    cout << "5 -> Git" << endl;
    cout << "6 -> Quit" << endl;
    cin >> menu_cislo;
    switch(menu_cislo){
        case 1:
            {
                system("CLS");
                cout << endl;
                start(menu1);
                cout << endl;
                getch();
                system("CLS");
                goto menicko;
            }
        case 2:
            {
                system("CLS");
                cout << endl ;
                nabarvy(CERVENA, "Entering a code -> in process... Press any key to continue...");
                getch();
                system("CLS");
                goto menicko;
            }
        case 3:
            {
                system("CLS");
                cout << endl ;
                nabarvy(CERVENA, "Add a plugin ->in process... Press any key to continue...");
                getch();
                system("CLS");
                goto menicko;
            }
        case 4:
            {
                system("CLS");
                cout << endl ;
                nabarvy(CERVENA, "Help -> in process... Press any key to continue...");
                getch();
                system("CLS");
                goto menicko;
            }
        case 5:
            {
                system("CLS");
                cout << endl ;
                nabarvy(CERVENA, "GIT -> in process... Press any key to continue...");
                getch();
                system("CLS");
                goto menicko;
            }
        case 6:
            {
                system("CLS");
                cout << endl ;
                nabarvy(CERVENA, "Quiting,  Press any key to continue...");
                getch();
                exit(0);
            }
    }
}
void novaverze(string verze, string upravy, const char *soubor){
    ofstream soubor1(soubor);
    soubor1 << "[" << CurrentDateTime("now") << " - " << verze << " - " << upravy << "]";
    soubor1.close();
}
void ScriptOtxt(string soubor){
    ofstream script("C:/projectant/startScript/opentTxt.bat");
    script << "COLOR 02" << endl;
    script << "TITLE openTXTinNOTEPAD" << endl;
    script << "CLS" << endl;
    script << "@ECHO OFF" << endl;
    script << "ECHO Open .txt file in NOTEPAD" << endl;
    script << "ECHO Created for Projectant game application" << endl;
    script << "ECHO Written by: MitasVit" << endl;
    script << "ECHO (c)2020 MitasVit. All rights reserved." << endl;
    script << "ECHO." << endl;
    script << "ECHO Info this app was started because the Projectant Game called this app" << endl;
    script << "ECHO If you are owner of Projectant Game is all right" << endl;
    script << "ECHO." << endl;
    script << "ECHO." << endl;
    script << "ECHO You can close this application" << endl;
    script << "Notepad " << soubor << endl;
    script.close();
}
void ScriptOexe(string aplikace){
    ofstream script("C:/projectant/startScript/opentExe.bat");
    script << "COLOR 02" << endl;
    script << "TITLE openTXTinNOTEPAD" << endl;
    script << "CLS" << endl;
    script << "@ECHO OFF" << endl;
    script << "ECHO Open .exe file " << endl;
    script << "ECHO Created for Projectant game application" << endl;
    script << "ECHO Written by: MitasVit" << endl;
    script << "ECHO (c)2020 MitasVit. All rights reserved." << endl;
    script << "ECHO." << endl;
    script << "ECHO Info this app was started because the Projectant Game called this app" << endl;
    script << "ECHO If you are owner of Projectant Game is all right" << endl;
    script << "ECHO." << endl;
    script << "ECHO." << endl;
    script << "ECHO You can close this application" << endl;
    script << "START " << aplikace << endl;
    script.close();
}
void OtevriScriptOtxt(){
    ifstream script("C:/projectant/startScript/opentTxt.bat");
    if(script.is_open()){
        LPCTSTR helpFile = "C:/projectant/startScript/opentTxt.bat";
        ShellExecute(NULL, "open", helpFile, NULL, NULL, SW_SHOWNORMAL);
    }else{
        log(EROR, "Error E6", "C:/projectant/Logs/ErrorE6.log");
    }
}
void OtevriScriptOexe(){
    ifstream script("C:/projectant/startScript/opentExe.bat");
    if(script.is_open()){
        LPCTSTR helpFile = "C:/projectant/startScript/opentExe.bat";
        ShellExecute(NULL, "open", helpFile, NULL, NULL, SW_SHOWNORMAL);
    }else{
        log(EROR, "Error E7", "C:/projectant/Logs/ErrorE7.log");
    }
}
void vytvorWeb(){
    ofstream hlavni("C:/projectant/homepage/stranky.html");
    ofstream styl1("C:/projectant/homepage/styl1.css");
    ofstream ohre("C:/projectant/homepage/ohre.html");
    ofstream onas("C:/projectant/homepage/onas.html");
    ofstream navod("C:/projectant/homepage/navod.html");
    /*DOPLNIM SEM AZ BUDU MIT NAVRZENE STRANKY*/
    hlavni.close();
    styl1.close();
    ohre.close();
    onas.close();
    navod.close();
}
void otevryWeb(){
    ifstream web("C:/projectant/homepage/stranky.html");
    if(web.is_open()){
        LPCTSTR helpFile = "C:/projectant/homepage/stranky.html";
        ShellExecute(NULL, "open", helpFile, NULL, NULL, SW_SHOWNORMAL);
    }else{
        log(EROR, "Error E6", "C:/projectant/Logs/ErrorE6.log");
    }

}

string logoSuperStudio[6][1]{{"\t __          __    __   __       __  _____          _        ___"},
                             {"\t|    |   |  |  |  |    |  |     |      |    |   |  | \\   |  |   |"},
                             {"\t|__  |   |  |__|  |__  |__|     |__    |    |   |  |  |  |  |   |"},
                             {"\t   | |   |  |     |    |\\          |   |    |   |  |  |  |  |   |"},
                             {"\t___| |___|  |     |__  | \\      ___|   |    |___|  |_/   |  |___|"}};
#endif
