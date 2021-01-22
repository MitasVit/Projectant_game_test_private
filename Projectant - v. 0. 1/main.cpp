#define _WIN32_WINNT 0x0500

#include "../Projectant - v. 0. 1/Projectant.h"
#include "../Projectant - v. 0. 1/resource.h"

using namespace std;

/**UKLADANI DAT DO TRIDY HRAC*/
hrac novy;

/**STRUKTURA PRO ARGUMENTY MENU - > NAHRADIM JE DATY Z TRIDY HRAC*/
menu_arg start_menu;

int main()
{
    try{
        /**NAHRAZENI DAT ZE STRUKTURY ZA DATA ZE TRIDY HRAC*/
        start_menu.jmenoa = novy.jmeno;
        start_menu.zemea = novy.zeme;
        start_menu.pracea = novy.prace;
        start_menu.plata = novy.plat;
        /**ZAPIS VERZI*/
        thread vlakno_verze1(novaverze,"1.0.0", "prvni vydani, zadne upravy", "changes/CHANGELOG1.md");
        thread vlakno_verze2(novaverze,"1.0.1", "druhe vydani, loading hotovo", "changes/CHANGELOG2.md");
        thread vlakno_verze3(novaverze, "1.0.2", "treti vydani, 4 prace, vylepsene menu", "changes/CHANGELOG3.md");

        thread vlakno_plugin(vytvorScript_plugin, "C:/projectant/Plugins/plugin1.projectant");

        /**NASTAVENI SLOZEK, PRACI*/
        thread vlakno_nastav(nastav);
        thread vlakno_prace(vytvorsoubor_prace);
        /**ZAPOJ VLAKNA*/
        vlakno_verze1.join();
        vlakno_verze2.join();
        vlakno_verze3.join();
        vlakno_nastav.join();
        vlakno_prace.join();

        vlakno_plugin.join();

        /**LOADING - > MENU -> HRA - > */
        system("CLS");


        thread menicko(menu, start_menu);
        menicko.join();

        /** !! NEFUNGUJE: !!

            ODMITNUTI NACITANI
            NACITANI OTAZKA V PLATU A NAZVU PRACE

        **/

        /**ZAPOZNAMKOVANO -> START() JE SOUCASTI MENU()*/
        /*start(jmeno1, zeme1);*/

        /**VSE PROBEHLO V PORADKU*/
        return VPORADKU;

    }catch(int chyba){

        /**NECO SE POKAZILO*/
        logEv(ERROR, chyba, "C:/projectant/logs/main.log");

        /**POZN.: SOUPIS ZACHYCENÝCH CHYB Z OSTATNÍH SOUBORU VIZ DEFINICE.H*/
        return CHYBA;
    }
}
