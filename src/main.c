#include <stdio.h>
#include "grid.h"

int main (int argc, char** argv){
    
    //printf("Hello, world!");

    if(argc == 2){
        long int x = strtol(argv[1], NULL, 10);

        genGrid(x, x);
    }else if(argc == 3){

        long int x = strtol(argv[1], NULL, 10);
        long int y = strtol(argv[2], NULL, 10);
        genGrid(x,y);
    }

    return 0;
}