#include "terminal_utils.h"
#include <stdio.h> 

void clear_terminal() {
    
#ifdef _WIN32
    system("cls"); 
    
#else
    system("clear");
    
#endif
}