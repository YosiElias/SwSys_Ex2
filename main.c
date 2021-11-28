#include <stdio.h>
#include "my_mat.h"



int main()    
{  
    int (*p_arr)[N];  ///////////////////////////static variable
    while (1){
        // printf("ENTER CHAR TO START: ");

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
            return 1;
        default:
            // printf("\n---- NONE ----\n");
            break;
    }
}
printf("***** END *****");
return 1;
}