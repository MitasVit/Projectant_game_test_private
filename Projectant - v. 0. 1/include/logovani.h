#ifndef LOGOVANI_H
#define LOGOVANI_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include "definice.h"
#include <thread>

using namespace std;

inline string CurrentDateTime( string s ){
 time_t now = time(0);
    struct tm  tstruct;
    char  buf[80];
    tstruct = *localtime(&now);
    if(s=="now")
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    else if(s=="date")
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
        return string(buf);
}

void log(string druh_zpravy, string zprava,  const char* soubor){
    ofstream log_soubor(soubor);
    zapisdata:
        if(log_soubor.is_open()){
            log_soubor << endl << "[" << druh_zpravy << ": " << CurrentDateTime("now") << "-" << zprava << "-" << __FILE__ << "]" << endl;
        }
        log_soubor.close();
        ifstream kontrola(soubor);
        if(kontrola.is_open()){
            kontrola.close();
        }else{
            log(EROR, "Error E4", "C:/projectant/logs/errorE4.log");
            goto zapisdata;
            kontrola.close();
        }
}
void logE(string druh_zpravy, int zprava,  const char* soubor){
    ofstream log_soubor(soubor);
    zapisdata:
        if(log_soubor.is_open()){
            log_soubor << endl << "[" << druh_zpravy << ": " << CurrentDateTime("now") << "-" << zprava << "-" << __FILE__ << "]" << endl;
        }
        log_soubor.close();
        ifstream kontrola(soubor);
        if(kontrola.is_open()){
            kontrola.close();
        }else{
            log(EROR, "Error E4", "C:/projectant/logs/errorE4.log");
            goto zapisdata;
            kontrola.close();
        }
}

void logv(string _druh_zpravy, string _zprava,  const char* _soubor){
    thread logs(log, _druh_zpravy, _zprava, _soubor);
    logs.join();
}
void logEv(string druh_zpravy, int zprava,  const char* soubor){
    thread logs(logE, druh_zpravy, zprava, soubor);
    logs.join();
}
#endif // LOGOVANI_H
