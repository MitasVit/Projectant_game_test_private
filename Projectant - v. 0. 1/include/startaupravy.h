#ifndef STARTAUPRAVY_H
#define STARTAUPRAVY_H


#include <windows.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <wchar.h>
#include <fstream>
#include <nabarvy>
#include <thread>

#define _WIN32_WINNT 0x0500

#include "definice.h"
#include "logovani.h"
#include "nacti,otevri_prace.h"
#include "plugins.h"
#include "vipcode.h"
#include "herni_menu.h"
#include "jate.h"
#include "messageBoxReturn.h"

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
        logv(EROR, "Error E3", "C:\\projectant\\logs\\errorE3.log");
        kontrola.close();
    }

}
void vytvorsouborv(const char *cesta, string zprava1, int zprava2, float zprava3, float zprava4){
    thread soubory(vytvorsoubor, cesta, zprava1, zprava2, zprava3, zprava4);
    soubory.join();
}
void nastav(){
   Konzole testik;
   testik.vytvorSlozku("C:\\projectant");
   testik.vytvorSlozku("C:\\projectant\\logs");
   testik.vytvorSlozku("C:\\projectant\\data");
   testik.vytvorSlozku("C:\\projectant\\homepage");
   testik.vytvorSlozku("C:\\projectant\\startScript");
   testik.vytvorSlozku("C:\\projectant\\Plugins");
   testik.vytvorSlozku("C:\\projectant\\trade_data");
   testik.nastavNormal(false);
   ///testik.nastavFullScreen();
}
void vytvorsoubor_prace(){
    ofstream prace("C:/projectant/trade_data/works.projectant");
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
        logv(EROR, "Error E9", "C:/projectant/logs/ErrorE9.log");
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
        string te_prace;
        int te_zeme;
        int te_plat;
        int test;
        getline(kontrola_en, te_jmeno);
        kontrola_en >> te_zeme;
        getline(kontrola_en, te_prace);
        kontrola_en >> te_plat;
        if(te_zeme != 0){
            cout << "Do you want to read: "<< endl;
            cout << "name: "<< te_jmeno << endl;
            cout << "country: ";
            if(te_zeme == 1){
                cout << "Czech republic" << endl;
            }else if(te_zeme == 2){
                cout << "England" << endl;
            }else{
                logv(EROR, "Error E10", "C:/projectant/logs/ErrorE10.log");
            }
            cout << "work: " << te_prace << endl;
            cout << "salary: " << te_plat << endl;
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
                kontrola_en.clear();
                cout << endl << "press enter to continue";
                getch();
                system("CLS");
                cout << "Enter a name: ";
                cin >> menu2.jmenoa;
                cout << "Enter a country: " << endl;
                cout << "1 -> Czech Republic" << endl;
                cout << "2 -> England" << endl;
                cin >> menu2.zemea;
                zadejpraci:
                    cout << "select a work: " << endl;
                    nacti_prace(4);
                    int cislo;
                    cin >>cislo;
                    if(cislo == 1){
                        menu2.pracea = "engineer";
                        menu2.plata = SALARY_ENGINEER;
                    }else if(cislo == 2){
                        menu2.pracea = "servicer";
                        menu2.plata = SALARY_SERVICER;
                    }else if(cislo == 3){
                        menu2.pracea = "dustman";
                        menu2.plata = SALARY_DUSTMAN;
                    }else if(cislo == 4){
                        menu2.pracea = "cleaner";
                        menu2.plata = SALARY_CLEANER;
                    }else{
                        nabarvy(CERVENA, "unknown, press any key to continue");
                        getch();
                        system("CLS");
                        goto zadejpraci;
                    }
                    uloz_data(menu2.jmenoa, menu2.zemea, menu2.pracea, menu2.plata);
            }
    }else{
        cout << "Enter a name: ";
        cin >> menu2.jmenoa;
        cout << "Enter a country: " << endl;
        cout << "1 -> Czech Republic" << endl;
        cout << "2 -> England" << endl;
        cin >> menu2.zemea;
        zadejpraci2:
            cout << "select a work: " << endl;
            nacti_prace(4);
            int cislo;
            cin >>cislo;
            if(cislo == 1){
                menu2.pracea = "engineer";
                menu2.plata = SALARY_ENGINEER;
            }else if(cislo == 2){
                menu2.pracea = "servicer";
                menu2.plata = SALARY_SERVICER;
            }else if(cislo == 3){
                menu2.pracea = "dustman";
                menu2.plata = SALARY_DUSTMAN;
            }else if(cislo == 4){
                menu2.pracea = "cleaner";
                menu2.plata = SALARY_CLEANER;
            }else{
                nabarvy(CERVENA, "unknown, press any key to continue");
                getch();
                system("CLS");
                goto zadejpraci2;
            }
        uloz_data(menu2.jmenoa, menu2.zemea, menu2.pracea, menu2.plata);
    }
    }else{
        cout << "Enter a name: ";
        cin >> menu2.jmenoa;
        cout << "Enter a country: " << endl;
        cout << "1 -> Czech Republic" << endl;
        cout << "2 -> England" << endl;
        cin >> menu2.zemea;
        zadejpraci3:
            cout << "select a work: " << endl;
            nacti_prace(4);
            int cislo;
            cin >>cislo;
            if(cislo == 1){
                menu2.pracea = "engineer";
                menu2.plata = SALARY_ENGINEER;
            }else if(cislo == 2){
                menu2.pracea = "servicer";
                menu2.plata = SALARY_SERVICER;
            }else if(cislo == 3){
                menu2.pracea = "dustman";
                menu2.plata = SALARY_DUSTMAN;
            }else if(cislo == 4){
                menu2.pracea = "cleaner";
                menu2.plata = SALARY_CLEANER;
            }else{
                nabarvy(CERVENA, "unknown, press any key to continue");
                getch();
                system("CLS");
                goto zadejpraci3;
            }
        uloz_data(menu2.jmenoa, menu2.zemea, menu2.pracea, menu2.plata);
    }
}

void menu(menu_arg menu1){
    /*loading();*/
    Boxe();
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
                system("CLS");
                bool test2 = true;
                setcursor(0,0);
                mainmenu:
                cout << "     MAIN MENU" << endl;
                /*herniMenu(0);*/
                cout << "-------------------" << endl;
                cout << "|     1. Shop     |" << endl;
                cout << "|-----------------|" << endl;
                cout << "|   2. Inventory  |" << endl;
                cout << "|-----------------|" << endl;
                cout << "|   3. Business   |" << endl;
                cout << "|-----------------|" << endl;
                cout << "|    4. Games     |" << endl;
                cout << "|-----------------|" << endl;
                cout << "|    5. Bonus     |" << endl;
                cout << "|-----------------|" << endl;
                cout << "|     6. Help     |" << endl;
                cout << "|-----------------|" << endl;
                cout << "|   7. Settings   |" << endl;
                cout << "|-----------------|" << endl;
                cout << "|     8. Quit     |" << endl;
                cout << "-------------------" << endl << endl;
                int nums;
                cout << "Enter a number: ";
                cin >> nums;
                switch(nums){
                    case 1:
                        {
                            cout << "shop - in work, press any key to continue...";
                            getch();
                            system("CLS");
                            goto mainmenu;
                            break;
                        }
                    case 2:
                        {
                            cout << "inventory - in work, press any key to continue...";
                            getch();
                            system("CLS");
                            goto mainmenu;
                            break;
                        }
                    case 3:
                        {
                            cout << "business - in work, press any key to continue...";
                            getch();
                            system("CLS");
                            goto mainmenu;
                            break;
                        }
                    case 4:
                        {
                            cout << "games - in work, press any key to continue...";
                            getch();
                            system("CLS");
                            goto mainmenu;
                            break;
                        }
                    case 5:
                        {
                            cout << "bonus - in work, press any key to continue...";
                            getch();
                            system("CLS");
                            goto mainmenu;
                            break;
                        }
                    case 6:
                        {
                            system("CLS");
                            cout << endl ;
                            ShellExecute(NULL, "open", "projectant - help.exe", NULL, NULL, SW_SHOWNORMAL);
                            cout << "Press enter to return to menu.";
                            getch();
                            system("CLS");
                            break;
                        }
                    case 7:
                        {
                            cout << "setting - in work, press any key to continue...";
                            getch();
                            system("CLS");
                            goto mainmenu;
                            break;
                        }
                    case 8:
                        {
                            system("CLS");
                            cout << endl ;
                            nabarvy(CERVENA, "Quiting,  Press any key to continue...");
                            getch();
                            exit(0);
                            break;
                        }
                    default:
                        {
                            system("CLS");
                            goto mainmenu;
                            break;
                        }
                }
                getch();
                system("CLS");
                goto menicko;
            }
        case 2:
            {
                system("CLS");
                cout << endl ;
                zadejKod();
                goto menicko;
            }
        case 3:
            {
                system("CLS");
                cout << endl ;
                vytvorPlugin();
                getch();
                system("CLS");
                goto menicko;
            }
        case 4:
            {
                system("CLS");
                cout << endl ;
                ShellExecute(NULL, "open", "projectant - help.exe", NULL, NULL, SW_SHOWNORMAL);
                cout << "Press enter to return to menu.";
                getch();
                system("CLS");
                goto menicko;
            }
        case 5:
            {
                system("CLS");
                cout << endl ;
                cout << "Opening web..." << endl;
                ShellExecute(NULL, "open", "https://github.com/MitasVit/Projectant_game_test_private", NULL, NULL, SW_SHOWNORMAL);
                nabarvy(CERVENA, "Press any key to continue in game...");
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
        logv(EROR, "Error E6", "C:/projectant/logs/ErrorE6.log");
    }
}
void OtevriScriptOexe(){
    ifstream script("C:/projectant/startScript/opentExe.bat");
    if(script.is_open()){
        LPCTSTR helpFile = "C:/projectant/startScript/opentExe.bat";
        ShellExecute(NULL, "open", helpFile, NULL, NULL, SW_SHOWNORMAL);
    }else{
        logv(EROR, "Error E7", "C:/projectant/logs/ErrorE7.log");
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
        logv(EROR, "Error E6", "C:/projectant/logs/ErrorE6.log");
    }

}

string logoSuperStudio[6][1]{{"\t __          __    __   __       __  _____          _        ___"},
                             {"\t|    |   |  |  |  |    |  |     |      |    |   |  | \\   |  |   |"},
                             {"\t|__  |   |  |__|  |__  |__|     |__    |    |   |  |  |  |  |   |"},
                             {"\t   | |   |  |     |    |\\          |   |    |   |  |  |  |  |   |"},
                             {"\t___| |___|  |     |__  | \\      ___|   |    |___|  |_/   |  |___|"}};
#endif
