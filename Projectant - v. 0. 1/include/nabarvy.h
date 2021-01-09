#ifndef NABARVY_H_
#define NABARVY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdarg.h>

#ifdef _WIN32
#include <windows.h>
#endif

/*
 * FUNKCE NABRAVY S PARAMETREM BARVOU(ÈÍSLO)
 *
 * BARVA = -1 -> NEBAREVNE (STEJNE JAKU COUT/PRINT)
 *          0 -> ÈERVENÁ
 *          1 -> ZELENÁ
 *          2 -> ŽLUTÁ
 *          3 -> MODRÁ
 *          4 -> FIALOVÁ
 *          5 -> ŠEDÁ
 */
int nabarvy(int barva, const char *text, ...) {
	int fbarva = -1, retval = -99;
	va_list args;
#ifdef _WIN32
	if (barva == 0) {
		fbarva = FOREGROUND_RED;
	} else if (barva == 1) {
		fbarva = FOREGROUND_GREEN;
	} else if (barva == 2) {
		fbarva = FOREGROUND_RED | FOREGROUND_GREEN;
	} else if (barva == 3) {
		fbarva = FOREGROUND_BLUE;
	} else if (barva == 4) {
		fbarva = FOREGROUND_RED | FOREGROUND_BLUE;
	} else if (barva == 5) {
		fbarva = FOREGROUND_GREEN | FOREGROUND_BLUE;
	}
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	WORD wOldbarvaAttrs;
	HANDLE hStdout;
	if (fbarva != -1) {
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		if ((hStdout == NULL) || (hStdout == INVALID_HANDLE_VALUE)) {
			return -99;
		}
		if (GetConsoleScreenBufferInfo(hStdout, &csbiInfo) == 0) {
			return -99;
		}
		wOldbarvaAttrs = csbiInfo.wAttributes;
		if (SetConsoleTextAttribute(hStdout, fbarva | FOREGROUND_INTENSITY) == 0) {
			return -99;
		}
	}
#else
	if (barva == 0) {
		fbarva = 1;
	} else if (barva == 1) {
		fbarva = 2;
	} else if (barva == 2) {
		fbarva = 3;
	} else if (barva == 3) {
		fbarva = 4;
	} else if (barva == 4) {
		fbarva = 5;
	} else if (barva == 5) {
		fbarva = 6;
	}
	if (fbarva != -1 && printf("\033[1;3%dm", fbarva) < 0) {
		return -99;
	}
#endif
	va_start(args, text);
	if (!args) {
		return -99;
	}
	retval = vprintf(text, args);
	va_end(args);
	if (fbarva != -1) {
#ifdef _WIN32
		if (SetConsoleTextAttribute(hStdout, wOldbarvaAttrs) == 0) {
			return -99;
		}
#else
		if (printf("\033[0m") < 0) {
			return -99;
		}
#endif
	}
	return retval;
}

#ifdef __cplusplus
}
#endif

#endif
