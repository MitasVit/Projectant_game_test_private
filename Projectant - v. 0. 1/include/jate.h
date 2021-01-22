#ifndef JATE_H
#define JATE_H

#define _WIN32_WINNT 0x0500

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sstream>

#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif // _GLIBCXX_IOSTREAM

#ifndef _GLIBCXX_FSTREAM
#include <fstream>
#endif // _GLIBCXX_FSTREAM

#ifndef _WINDOWS_H
#include <windows.h>
#endif // _WINDOWS_H

#ifndef NABARVY_H_
#include <nabarvy>
#endif // NABARVY_H_

#ifndef _CONIO_H_
#include <conio.h>
#endif // _CONIO_H_

#ifndef _DIRENT_H_
#include <dirent.h>
#endif // _DIRECT_H_

#ifndef _TIME_H_
#include <time.h>
#endif // _TIME_H_

#ifndef _GLIBCXX_THREAD
#include <thread>
#endif // _GLIBCXX_THREAD

#ifndef	_TCHAR_H_
#include <tchar.h>
#endif // _TCHAR_H_

#ifndef	_WCHAR_H_
#include <wchar.h>
#endif // _WCHAR_H_

#ifndef _GLIBCXX_LOCALE
#include <locale>
#endif // _GLIBCXX_LOCALE

#ifndef PISKVORKY_H
#include "piskvorky.h"
#endif // PISKVORKY_H

#ifndef MESSAGEBOXRETURN_H
#include "messageBoxReturn.h"
#endif // MESSAGEBOXRETURN_H

#ifndef MY_OSTREAM_H
#include "ostream.h"
#endif // MY_OSTREAM_H

#define CRITICAL "CRITICAL"
#define SPECIAL "SPECIAL"
#define INFO "INFO"
#define WARNING "WARNING"
#define EROR "ERROR"
#define UNKNOWN "UNKNOWN"

#define TL_OK MB_OK
#define TL_ZKUSZNOVUSTORNO MB_CANCELTRYCONTINUE
#define TL_NAPOVEDA MB_HELP
#define TL_ANONE MB_YESNO
#define TLANONEZRUS MB_YESNOCANCEL
#define TL_OKZRUS MB_OKCANCEL

using namespace std;


class Konzole{
public:
    Konzole(){ };
    virtual ~Konzole(){ };

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Kurzor;
    HWND hWnd = GetConsoleWindow();
    RECT ConsoleRect;
    CONSOLE_SCREEN_BUFFER_INFO ConInfo;

    void nastavKurzor(bool visible, DWORD size1){
        if(size1 == 0)
            size1 = 20;

        CONSOLE_CURSOR_INFO lpCursor;
        lpCursor.bVisible = visible;
        lpCursor.dwSize = size1;
        SetConsoleCursorInfo(console, &lpCursor);
    }

     void gotoxy(int x, int y){
        Kurzor.X = x;
        Kurzor.Y = y;
        SetConsoleCursorPosition(console, Kurzor);
    }

     void nastavNormal(bool udelejOkraj){
        setlocale(LC_ALL, "english");
        SetConsoleCP(1250);
        SetConsoleOutputCP(1250);

        GetConsoleScreenBufferInfo(console, &ConInfo);
        DWORD BufferSize = ConInfo.dwSize.X * ConInfo.dwSize.Y;
        GetWindowRect(hWnd, &ConsoleRect);
        //MoveWindow(hWnd, ConsoleRect.left, ConsoleRect.top, OBRAZ_SIRKA, OBRAZ_VYSKA, TRUE);
        if(udelejOkraj == true){
            nakreslyOkraj();
        }
        nastavKurzor(0, 0);
        //gotoxy(0, 0);
    }

     void pausa(){
        system("PAUSE");
    }

     void vymazObraz(){
        system("CLS");
    }

     void obarvyText(const char *text, int barva){
        nabarvy(barva, text);
    }

     void obarvyObraz(const char *barvaTextu, const char *barvaPozadi){
        const char *cele = "color ";
        cele =+ barvaTextu;
        cele =+ barvaPozadi;
        system(cele);
    }
     void vytvorSoubor(const char *soubor){
        ofstream tvor(soubor);
        if(tvor.is_open()){
            tvor.close();
        }else{
            cerr << "eror pri vytvareni souboru";
            tvor.close();
        }
    }
     void prikaz(const char *prikaz){
        system(prikaz);
    }

     void zkompiluj(const char *soubor){
        const char *cele = "gcc -o ";
        cele =+ soubor;
        system(cele);
    }

     void otevriAplikaci(const char *soubor){
        const char *cele = "START ";
        cele =+ soubor;
        system(cele);
    }

     void otevriCokoliv(LPCTSTR soubor){
        ShellExecute(NULL, "open", soubor, NULL, NULL, SW_SHOWNORMAL);

    }

     void zpravaTlacitka(HWND styl, LPCSTR nadpis, LPCSTR popis, UINT tlacitka){
        MessageBox(styl, popis, nadpis, tlacitka);
    }

     void vytvorSlozku(const char *cesta){
        CreateDirectory(cesta, NULL);
    }

     void Log(string druh_zpravy, string zprava,const char *souborUmisteni){
        ofstream log_soubor(souborUmisteni);
        zapisdata:
            if(log_soubor.is_open()){
                log_soubor << endl << "[" << druh_zpravy << ": " << momentalniCas() << "-" << zprava << "-" << __FILE__ << "]" << endl;
            }
            log_soubor.close();
            ifstream kontrola(souborUmisteni);
            if(kontrola.is_open()){
                kontrola.close();
            }else{
                Log(EROR, "Error E4", "C:/projectant/logs/errorE4.log");
                goto zapisdata;
                kontrola.close();
            }
    }

     void nastavTitul(LPCSTR titul){
        SetConsoleTitle(titul);
    }

     void ZahrajPiskvorky(){
        piskvorky();
    }

    void casovac(int sekundy){
        clock_t start = clock();
        clock_t perioda = sekundy * CLOCKS_PER_SEC;
        clock_t uplynulo;

        do {
            uplynulo = clock() - start;
        } while(uplynulo < perioda);
    }

    int nalistujSlozku(const char *cesta){
        struct dirent *entry;
        DIR *dp;

        dp = opendir(cesta);
        if (dp == NULL){
            perror("opendir");
            return -1;
        }

        while((entry = readdir(dp))){
            puts(entry->d_name);
        }
        closedir(dp);
        return 0;
    }

    int nalistujSlozku2(const char *cesta){
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir (cesta)) != NULL) {
            /* print all the files and directories within directory */
            while ((ent = readdir (dir)) != NULL) {
                printf ("%s\n", ent->d_name);
            }
            closedir (dir);
        }else{
            /* could not open directory */
            perror ("CHYBA PRI LISTOVANI");
            return EXIT_FAILURE;
        }
    }

     void konec(int vracejiciHodnota){
        exit(vracejiciHodnota);
    }

     void prepniDoCMD(){
        system("CMD");
    }

     void nastavFullScreen(){
        MoveWindow(hWnd, 0, 0, 200, 200, TRUE);
        system("mode 650");
    }

    inline string momentalniCas(){
        time_t ted = time(0);
        struct tm  tstruct;
        char  buf[80];
        tstruct = *localtime(&ted);
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
        return string(buf);
    }

    void odejdiChyba(){
        exit(EXIT_FAILURE);
    }

    void odejdiVpoho(){
        exit(EXIT_SUCCESS);
    }

     void nakreslyOkraj(){
        int i = 160;
        int d = 43;
        for(int x = 0; x < i; x++){
            cout << '#';
        }
        for(int x = 0; x < d; x++){
            cout << '#' << endl;
        }
        for(int x = 0; x < i; x++){
            cout << '#';
        }
    }
/**handle for buttons
    HWND tlacitko = CreateWindow(
    "BUTTON",  // Predefined class; Unicode assumed
    "OK",      // Button text
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
    10,         // x position
    10,         // y position
    100,        // Button width
    100,        // Button height
    hWnd,     // Parent window
    NULL,       // No menu.
    (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
    NULL);      // Pointer not needed.**/


    void zobrazLiccenci(){
        gotoxy(5, 5);cout << "\t\tMIT License" << endl << endl;

        gotoxy(5, 7);cout << "Copyright (c) 2021 MitasVit" << endl << endl;

        gotoxy(5, 9);cout << "Permission is hereby granted, free of charge, to any person obtaining a copy" << endl;
        gotoxy(5, 10);cout << "of this software and associated documentation files (the \"Software\"), to deal" << endl;
        gotoxy(5, 11);cout << "in the Software without restriction, including without limitation the rights" << endl;
        gotoxy(5, 12);cout << "to use, copy, modify, merge, publish, distribute, sublicense, and/or sell" << endl;
        gotoxy(5, 13);cout << "copies of the Software, and to permit persons to whom the Software is" << endl;
        gotoxy(5, 14);cout << "furnished to do so, subject to the following conditions:" << endl << endl;

        gotoxy(5, 16);cout << "The above copyright notice and this permission notice shall be included in all" << endl;
        gotoxy(5, 17);cout << "copies or substantial portions of the Software." << endl << endl;

        gotoxy(5, 19);cout << "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR" << endl;
        gotoxy(5, 20);cout << "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY," << endl;
        gotoxy(5, 21);cout << "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE" << endl;
        gotoxy(5, 22);cout << "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER" << endl;
        gotoxy(5, 23);cout << "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM," << endl;
        gotoxy(5, 24);cout << "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE" << endl;
        gotoxy(5, 25);cout << "SOFTWARE." << endl << endl;

        gotoxy(5, 27);cout << "Press any key to agreement with this license..." << endl;
        gotoxy(5, 28);getch();
        system("CLS");
    }
    LPCSTR licence(){
    return "\t\tMIT License\n\nCopyright (c) 2021 MitasVit\n\nPermission is hereby granted, free of charge, to any person obtaining a copy\nof this software and associated documentation files (the \"Software\"), to deal\nin the Software without restriction, including without limitation the rights\nto use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n";

       /* gotoxy(5, 7);cout << "" << endl << endl;

        gotoxy(5, 9);cout << "" << endl;
        gotoxy(5, 10);cout << "" << endl;
        gotoxy(5, 11);cout << "" << endl;
        gotoxy(5, 12);cout << "" << endl;
        gotoxy(5, 13);cout << "copies of the Software, and to permit persons to whom the Software is" << endl;
        gotoxy(5, 14);cout << "furnished to do so, subject to the following conditions:" << endl << endl;

        gotoxy(5, 16);cout << "The above copyright notice and this permission notice shall be included in all" << endl;
        gotoxy(5, 17);cout << "copies or substantial portions of the Software." << endl << endl;

        gotoxy(5, 19);cout << "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR" << endl;
        gotoxy(5, 20);cout << "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY," << endl;
        gotoxy(5, 21);cout << "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE" << endl;
        gotoxy(5, 22);cout << "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER" << endl;
        gotoxy(5, 23);cout << "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM," << endl;
        gotoxy(5, 24);cout << "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE" << endl;
        gotoxy(5, 25);cout << "SOFTWARE." << endl << endl;

    */
    }

};

void prepniDoCMD(){
    system("CMD");
}


#endif // JATE_H
