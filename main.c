#include <stdlib.h>
#include <stdio.h>
#if defined(_WIN32)
    #include "windows.h"
#endif

int main(void)
{
    #if defined(_WIN32)
        SetConsoleOutputCP(CP_UTF8);
    #endif
    return 0;
}