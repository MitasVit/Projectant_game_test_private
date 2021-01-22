#ifndef VIPCODE_H
#define VIPCODE_H

#include <iostream>
#include <fstream>
#include "logovani.h"
#include "definice.h"

using namespace std;
/**KODY VIZ KODY.TXT*/
void vytvorsoubor_jenzprava(const char *cesta, string zprava1){
    ofstream soubor1(cesta);
    soubor1 << zprava1 << endl;
    soubor1.close();
    ifstream kontrola(cesta);
    if(kontrola.is_open()){
        kontrola.close();
    }else{
        logv(EROR, "Error E3", "C:\\projectant\\logs\\errorE3.log");
        kontrola.close();
    }

}
void zadejKod(){
    string code;
    int danyCode;
    cout << "Enter a code, then press enter: ";
    cin >> code;
    if(code == "F35553"){
        danyCode = 1;
        vytvorsoubor_jenzprava("C:/projectant/data/code1_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "5D1411"){
        danyCode = 2;
        vytvorsoubor_jenzprava("C:/projectant/data/code2_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "26B165"){
        danyCode = 3;
        vytvorsoubor_jenzprava("C:/projectant/data/code3_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "1411B4"){
        danyCode = 4;
        vytvorsoubor_jenzprava("C:/projectant/data/code4_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "2411B4"){
        danyCode = 5;
        vytvorsoubor_jenzprava("C:/projectant/data/code5_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "65251C"){
        danyCode = 6;
        vytvorsoubor_jenzprava("C:/projectant/data/code6_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "B13364"){
        danyCode = 7;
        vytvorsoubor_jenzprava("C:/projectant/data/code7_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "5E4256"){
        danyCode = 8;
        vytvorsoubor_jenzprava("C:/projectant/data/code8_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "62D155"){
        danyCode = 9;
        vytvorsoubor_jenzprava("C:/projectant/data/code9_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "443C33"){
        danyCode = 10;
        vytvorsoubor_jenzprava("C:/projectant/data/code10_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "6445F5"){
        danyCode = 11;
        vytvorsoubor_jenzprava("C:/projectant/data/code11_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "35553F"){
        danyCode = 12;
        vytvorsoubor_jenzprava("C:/projectant/data/code12_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "F26441"){
        danyCode = 13;
        vytvorsoubor_jenzprava("C:/projectant/data/code13_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "5C2231"){
        danyCode = 14;
        vytvorsoubor_jenzprava("C:/projectant/data/code14_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "61F412"){
        danyCode = 15;
        vytvorsoubor_jenzprava("C:/projectant/data/code15_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "116F11"){
        danyCode = 16;
        vytvorsoubor_jenzprava("C:/projectant/data/code16_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "2552A2"){
        danyCode = 17;
        vytvorsoubor_jenzprava("C:/projectant/data/code17_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "33341C"){
        danyCode = 18;
        vytvorsoubor_jenzprava("C:/projectant/data/code18_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "E13212"){
        danyCode = 19;
        vytvorsoubor_jenzprava("C:/projectant/data/code19_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "2C5533"){
        danyCode = 20;
        vytvorsoubor_jenzprava("C:/projectant/data/code20_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "35C136"){
        danyCode = 21;
        vytvorsoubor_jenzprava("C:/projectant/data/code21_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "345D54"){
        danyCode = 22;
        vytvorsoubor_jenzprava("C:/projectant/data/code22_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "2642D2"){
        danyCode = 23;
        vytvorsoubor_jenzprava("C:/projectant/data/code23_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "23224C"){
        danyCode = 24;
        vytvorsoubor_jenzprava("C:/projectant/data/code24_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "E45556"){
        danyCode = 25;
        vytvorsoubor_jenzprava("C:/projectant/data/code25_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "2F4656"){
        danyCode = 26;
        vytvorsoubor_jenzprava("C:/projectant/data/code26_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else{
        cout << endl << "Invalid code, press enter to continue...";
        getch();
        system("CLS");
    }
}
int zadejKodvraceni(){
    string code;
    int danyCode;
    cout << "Enter a code, then press enter: ";
    cin >> code;
    if(code == "F35553"){
        danyCode = 1;
        vytvorsoubor_jenzprava("C:/projectant/data/code1_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "5D1411"){
        danyCode = 2;
        vytvorsoubor_jenzprava("C:/projectant/data/code2_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "26B165"){
        danyCode = 3;
        vytvorsoubor_jenzprava("C:/projectant/data/code3_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "1411B4"){
        danyCode = 4;
        vytvorsoubor_jenzprava("C:/projectant/data/code4_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "2411B4"){
        danyCode = 5;
        vytvorsoubor_jenzprava("C:/projectant/data/code5_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "65251C"){
        danyCode = 6;
        vytvorsoubor_jenzprava("C:/projectant/data/code6_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "B13364"){
        danyCode = 7;
        vytvorsoubor_jenzprava("C:/projectant/data/code7_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "5E4256"){
        danyCode = 8;
        vytvorsoubor_jenzprava("C:/projectant/data/code8_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "62D155"){
        danyCode = 9;
        vytvorsoubor_jenzprava("C:/projectant/data/code9_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "443C33"){
        danyCode = 10;
        vytvorsoubor_jenzprava("C:/projectant/data/code10_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "6445F5"){
        danyCode = 11;
        vytvorsoubor_jenzprava("C:/projectant/data/code11_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "35553F"){
        danyCode = 12;
        vytvorsoubor_jenzprava("C:/projectant/data/code12_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "F26441"){
        danyCode = 13;
        vytvorsoubor_jenzprava("C:/projectant/data/code13_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "5C2231"){
        danyCode = 14;
        vytvorsoubor_jenzprava("C:/projectant/data/code14_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "61F412"){
        danyCode = 15;
        vytvorsoubor_jenzprava("C:/projectant/data/code15_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "116F11"){
        danyCode = 16;
        vytvorsoubor_jenzprava("C:/projectant/data/code16_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "2552A2"){
        danyCode = 17;
        vytvorsoubor_jenzprava("C:/projectant/data/code17_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "33341C"){
        danyCode = 18;
        vytvorsoubor_jenzprava("C:/projectant/data/code18_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "E13212"){
        danyCode = 19;
        vytvorsoubor_jenzprava("C:/projectant/data/code19_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "2C5533"){
        danyCode = 20;
        vytvorsoubor_jenzprava("C:/projectant/data/code20_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "35C136"){
        danyCode = 21;
        vytvorsoubor_jenzprava("C:/projectant/data/code21_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "345D54"){
        danyCode = 22;
        vytvorsoubor_jenzprava("C:/projectant/data/code22_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "2642D2"){
        danyCode = 23;
        vytvorsoubor_jenzprava("C:/projectant/data/code23_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "23224C"){
        danyCode = 24;
        vytvorsoubor_jenzprava("C:/projectant/data/code24_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "E45556"){
        danyCode = 25;
        vytvorsoubor_jenzprava("C:/projectant/data/code25_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else if(code ==  "2F4656"){
        danyCode = 26;
        vytvorsoubor_jenzprava("C:/projectant/data/code26_applied.txt", "code_applied");
        /**PRIDANI NECEHO*/
        getch();
        system("CLS");
    }else{
        cout << endl << "Invalid code, press enter to continue...";
        getch();
        system("CLS");
    }
    return danyCode;

}
#endif // VIPCODE_H
