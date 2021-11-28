#include <stdio.h>
#include "my_mat.h"



int main()    
{  
    int (*p_arr)[N]; //global variable
    while (1){
        char comand;
        scanf("%c", &comand);
    switch(comand)
    {
        case 'A':
            p_arr = getArray();
            floydAlgo(p_arr);
            break;
        case 'B':
            isConect(p_arr);
            printf("\n");
            break;
        case 'C':
            shortest(p_arr);
            printf("\n");
            break;
        case 'D':
            return 0;
        default:
            break;
    }
}
return 0;
}