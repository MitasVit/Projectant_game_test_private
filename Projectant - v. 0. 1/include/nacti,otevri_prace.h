#ifndef NACTIOTEVRI_PRACE_H
#define NACTIOTEVRI_PRACE_H

#include <iostream>
#include <fstream>

using namespace std;

void nacti_prace(int pocet_praci){
    ifstream prace("C:/projectant/trade_data/works.projectant");
    if(prace.is_open()){
        cout  << endl << endl;
        switch(pocet_praci){
            case 1:
                {
                    string str1;
                    int plat1;
                    getline(prace, str1);
                    prace >> plat1;
                    cout << "1->" << endl;
                    cout << "\twork: " << str1 << endl;
                    cout << "\tsalary: "<< plat1 << endl << endl;
                    break;
                }
            case 2:
                {
                    string str1;
                    string str2;
                    int plat1;
                    int plat2;
                    getline(prace, str1);
                    prace >> plat1;
                    getline(prace, str2);
                    prace >> plat2;
                    cout << "1->" << endl;
                    cout << "\twork: " << str1 << endl;
                    cout << "\tsalary: "<< plat1 << endl << endl;
                    cout << "2->" << endl;
                    cout << "\twork: " << str2 << endl;
                    cout << "\tsalary: "<< plat2 << endl << endl;
                    break;
                }
            case 3:
                {
                    string str1;
                    string str2;
                    string str3;
                    int plat1;
                    int plat2;
                    int plat3;
                    getline(prace, str1);
                    prace >> plat1;
                    getline(prace, str2);
                    prace >> plat2;
                    getline(prace, str3);
                    prace >> plat3;
                    cout << "1->" << endl;
                    cout << "\twork: " << str1 << endl;
                    cout << "\tsalary: "<< plat1 << endl << endl;
                    cout << "2->" << endl;
                    cout << "\twork: " << str2 << endl;
                    cout << "\tsalary: "<< plat2 << endl << endl;
                    cout << "3->" << endl;
                    cout << "\twork: " << str3 << endl;
                    cout << "\tsalary: "<< plat3 << endl << endl;
                    break;
                }
            case 4:
                {
                    string str1;
                    string str2;
                    string str3;
                    string str4;
                    string plat1;
                    string plat2;
                    string plat3;
                    string plat4;
                    getline(prace, str1);
                    getline(prace, plat1);
                    getline(prace, str2);
                    getline(prace, plat2);
                    getline(prace, str3);
                    getline(prace, plat3);
                    getline(prace, str4);
                    getline(prace, plat4);
                    cout << "1->" << endl;
                    cout << "\twork: " << str1 << endl;
                    cout << "\tsalary: "<< plat1 << endl << endl;
                    cout << "2->" << endl;
                    cout << "\twork: " << str2 << endl;
                    cout << "\tsalary: "<< plat2 << endl << endl;
                    cout << "3->" << endl;
                    cout << "\twork: " << str3 << endl;
                    cout << "\tsalary: "<< plat3 << endl << endl;
                    cout << "4->" << endl;
                    cout << "\twork: " << str4 << endl;
                    cout << "\tsalary: "<< plat4 << endl << endl;
                    break;
                }
            case 5:
                {
                    string str1;
                    string str2;
                    string str3;
                    string str4;
                    string str5;
                    int plat1;
                    int plat2;
                    int plat3;
                    int plat4;
                    int plat5;
                    getline(prace, str1);
                    prace >> plat1;
                    getline(prace, str2);
                    prace >> plat2;
                    getline(prace, str3);
                    prace >> plat3;
                    getline(prace, str4);
                    prace >> plat4;
                    getline(prace, str5);
                    prace >> plat5;
                    cout << "1->" << endl;
                    cout << "\twork: " << str1 << endl;
                    cout << "\tsalary: "<< plat1 << endl << endl;
                    cout << "2->" << endl;
                    cout << "\twork: " << str2 << endl;
                    cout << "\tsalary: "<< plat2 << endl << endl;
                    cout << "3->" << endl;
                    cout << "\twork: " << str3 << endl;
                    cout << "\tsalary: "<< plat3 << endl << endl;
                    cout << "4->" << endl;
                    cout << "\twork: " << str4 << endl;
                    cout << "\tsalary: "<< plat4 << endl << endl;
                    cout << "5->" << endl;
                    cout << "\twork: " << str5 << endl;
                    cout << "\tsalary: "<< plat5 << endl << endl;
                    break;
                }
            case 6:
                {
                    string str1;
                    string str2;
                    string str3;
                    string str4;
                    string str5;
                    string str6;
                    int plat1;
                    int plat2;
                    int plat3;
                    int plat4;
                    int plat5;
                    int plat6;
                    getline(prace, str1);
                    prace >> plat1;
                    getline(prace, str2);
                    prace >> plat2;
                    getline(prace, str3);
                    prace >> plat3;
                    getline(prace, str4);
                    prace >> plat4;
                    getline(prace, str5);
                    prace >> plat5;
                    getline(prace, str6);
                    prace >> plat6;
                    cout << "1->" << endl;
                    cout << "\twork: " << str1 << endl;
                    cout << "\tsalary: "<< plat1 << endl << endl;
                    cout << "2->" << endl;
                    cout << "\twork: " << str2 << endl;
                    cout << "\tsalary: "<< plat2 << endl << endl;
                    cout << "3->" << endl;
                    cout << "\twork: " << str3 << endl;
                    cout << "\tsalary: "<< plat3 << endl << endl;
                    cout << "4->" << endl;
                    cout << "\twork: " << str4 << endl;
                    cout << "\tsalary: "<< plat4 << endl << endl;
                    cout << "5->" << endl;
                    cout << "\twork: " << str5 << endl;
                    cout << "\tsalary: "<< plat5 << endl << endl;
                    cout << "6->" << endl;
                    cout << "\twork: " << str6 << endl;
                    cout << "\tsalary: "<< plat6 << endl << endl;
                    break;
                }
            default:
                {
                    cout << "too much arguments, complete in next update...";
                    break;
                }
        }
    }
}

void uloz_data(string u_jmeno, int u_zeme, string u_prace, float u_plat){
    ofstream u_soubor("C:/projectant/data/en_seting.txt");
    u_soubor << u_jmeno << endl;
    u_soubor << u_zeme << endl;
    u_soubor << u_prace <<endl;
    u_soubor << u_plat << endl;
    u_soubor.close();
}
#endif
