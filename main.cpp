#include <iostream>
#include <sdl.h>

#include "forwardDeclerations.h"

#include "App.h"

int main(int argc, char* argv[])
{
    App test;

    test.init("Top down shooter", false);

    
    while (test.runningStatus())
    {
        test.runApp();
    }
    
    test.clean();
    
    

    return 0;
}