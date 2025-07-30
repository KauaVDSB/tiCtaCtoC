#ifndef TERMINAL_UTILS_H
#define TERMINAL_UTILS_H

#ifdef _WIN32
    #include <windows.h>

#else
    #include <stdlib.h>

#endif

void clear_terminal();

#endif