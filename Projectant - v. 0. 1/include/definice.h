#ifndef DEFINICE_H
#define DEFINICE_H

#define MENA_CZK 1
#define MENA_EUR 0.038
#define MENA_NORMAL 1

#define BURZA_NORMAL 1

#define CRITICAL "CRITICAL"
#define SPECIAL "SPECIAL"
#define INFO "INFO"
#define WARNING "WARNING"
#define EROR "ERROR"
#define UNKNOWN "UNKNOWN"

/** PRACE:

 "engineer150"
 "servicer75"
 "dustman60"
 "cleaner60"

SOUBOR: "C:/projectant/trade_data/traders.projectant"
**/

#define SALARY_ENGINEER 150
#define SALARY_SERVICER 75
#define SALARY_DUSTMAN 60
#define SALARY_CLEANER 60
/**
ERRORY:
E1   | SPATNE VYGENEROVANA CHYTROST         |  OBCHODNIK.H
E2   | SPATNE VYGENEROVANE CISLO PRO JMENO  |  OBCHODNIK.H
E3   | SPATNE VYTVORENY SOUBOR              |  STARTAUPRAVY.H
E4   | NEVYTVOREN SOUBOR LOG                |  LOGOVANI.H
E5   | NENAJIT SOUBOR STRANKY.HTML          |  STARTAUPRAVY.H
E6   | NENAJIT SOUBOR OPENTTXT.BAT          |  STARTAUPRAVY.H
E7   | NENAJIT SOUBOR OPENTEXE.BAT          |  STARTAUPRAVY.H
E8   | SPATNE VYGENEROVANE CISLO PRO PENIZE |  OBCHODNIK.H
E9   | PRILIS VELKE CISLO U LOADING         |  STARTAUPRAVY.H
MAIN | SPATNE FUNGUJE FUNKCE V MAIN         |  MAIN.CPP
*/

#define CESTINA true
#define ANGLICTINA false

#define CHYBA EXIT_FAILURE
#define VPORADKU EXIT_SUCCESS

#define BARVA
#define NEURCENA -1
#define CERVENA 0
#define ZELENA 1
#define ZLUTA 2
#define MODRA 3
#define FIALOVA 4
#define SEDA 5

/**COLOR ID	system("color background+text);
1	Blue	9	Light Blue
2	Green	0	Black
3	Aqua	A	Light Green
4	Red	B	Light Aqua
5	Purple	C	Light Red
6	Yellow	D	Light Purple
7	White	E	Light Yellow
8	Gray	F	Bright White*/

#endif
