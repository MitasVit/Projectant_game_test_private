#ifndef PLUGINS_H
#define PLUGINS_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <exception>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

void vytvorScript_plugin(string nazevSouboru_proPlugin){
    ofstream plugin("C:/projectant/startScript/pluginscript.bat");
    plugin << "TITLE Plugin_Open_Edit_Save" << endl;
    plugin << "COLOR 04" << endl;
    plugin << "@ECHO OFF" << endl;
    plugin << "mkdir C:/projectant" << endl;
    plugin << "cd C:/projectant" << endl;
    plugin << "cd Plugins" << endl;
    plugin << "CLS" << endl;
    plugin << "ECHO Write the script to opened file" << endl;
    plugin << "ECHO." << endl;
    plugin << "ECHO Then save the file and close this app" << endl;
    plugin << "Notepad "<< nazevSouboru_proPlugin << endl;
    plugin << "EXIT" << endl;
    plugin.close();
}

void otevri_Script_plugin(){
    LPCSTR helpfile = "C:/projectant/startScript/pluginscript.bat";
    ShellExecute(NULL, "open", helpfile, NULL, NULL, SW_SHOWNORMAL);
}

 void vytvorPlugin(){
    cout << "Plugins test" << endl;
    ofstream ofs("C:/projectant/Plugins/plugin1.projectant");
    ofs.close();
    LPCSTR helpfile = "C:/projectant/startScript/pluginscript.bat";
    ShellExecute(NULL, "open", helpfile, NULL, NULL, SW_SHOWNORMAL);
    cout << "Press any key to continue" <<endl;
    getch();
    system("CLS");
    ifstream kontrola("C:/projectant/Plugins/plugin1.projectant");
    if(kontrola.is_open()){
        cout << "Loaded - > translating...";
        string linka1;
        int linka2;
        getline(kontrola, linka1);
        kontrola >> linka2;
        cout << endl << linka1 << endl;
        cout << linka2 << endl;
        int n = linka1.length();
        char linka1_char[n + 1];
        strcpy(linka1_char, linka1.c_str());
        if(linka1_char[0] == 'A'){
            if(linka1_char[1] == 'D'){
                if(linka1_char[2] == 'D'){
                    if(linka1_char[3] == ' '){
                        char zbytek[15];
                        for(int j = 0; j < 15; j++){
                            zbytek[j] = linka1_char[j+4];
                        }
                        stringstream pomoc;
                        string text;
                        pomoc << zbytek;
                        pomoc >> text;
                        cout << endl << "Adding "<< text;
                    }else{
            cout << endl << "error4";
        }
                }else{
            cout << endl << "error3";
        }
            }else{
            cout << endl << "error2";
        }
        }else{
            cout << endl << "error1";
        }
    }else{
        cout << "Error -> you don't save the file on contact game service";
    }
 }
  #endif // PLUGINS_H
