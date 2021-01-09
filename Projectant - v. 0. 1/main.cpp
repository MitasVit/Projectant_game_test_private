#include "../Projectant - v. 0. 1/Projectant.h"

using namespace std;

string jmeno1;
int zeme1;
string prace1;
float plat1;

menu_arg start_menu;



int main()
{
    try{
        start_menu.jmenoa = jmeno1;
        start_menu.zemea = zeme1;
        start_menu.pracea = prace1;
        start_menu.plata = plat1;
        thread first(novaverze,"1.0.0", "prvni vydani, zadne upravy", "CHANGELOG1.md");
        thread second(novaverze,"1.0.1", "druhe vydani, loading hotovo", "CHANGELOG2.md");
        thread third(nastav, true);
        thread special(vytvorsoubor_prace);
        first.join();
        second.join();
        third.join();
        special.join();

        system("CLS");
        menu(start_menu);
        /**start(jmeno1, zeme1); <<- V MENU*/
        return VPORADKU;
    }catch(int chyba){
        logE(ERROR, chyba, "C:/projectant/logs/main.log");
        return CHYBA;
    }
}
