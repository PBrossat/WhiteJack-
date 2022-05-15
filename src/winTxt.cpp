#include "WinTxt.h"
#include <stdlib.h>
#include <stdio.h>

#if _WIN32
#include <windef.h>
#include <windows.h>

#else
#include <unistd.h>
#include <termios.h>

#endif

void termClear()  // efface le terminal
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


