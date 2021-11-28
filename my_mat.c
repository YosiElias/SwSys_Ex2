#include <stdio.h>
#include "my_mat.h"

#define N 10
// int printArr(int array[N][N]);

int (*(getArray)())[N]{
    int n;
    static int array[N][N];
    for(int i=0; i<N;i++)
    {
        for(int j=0; j<N;j++)
        {
            scanf("%d", &n);
            array[i][j] = n;
        }
    }
    // printArr(array);
    // printf("\n\n\n"); //Todo: dbs
    // int *p;
    // int (*ptr)[N];
    // ptr = array;
    // p = array[0][0];
    return array;
}

// int printArr(int array[N][N]){
//     /* output each array element's value */
//     // printf("%p", &array[0][0]);
//     // printf("\n%d\n", array[0][0]);

//    for(int i=0; i<N;i++)
//     {
//         for(int j=0; j<N;j++)
//         {
//             printf("\t%d", array[i][j]);  //Element[%d][%d] = 

//         }
//         printf("\n");
//    }
//     return 1;
// }


 

int floydAlgo(int (*arr)[N]){
    // int dist[N][N]; //i, j, k, 
    // for (int i=0; i<N; i++)  
    //    {
    //        for (int j=0; j<N; j++)  
    //        {
    //         dist[i][j] =  *(*(arr + i) + j);  //arr[i][j];   // *arr;
    //         // arr++;
    //        }
    //    }

    for (int k=0; k<N; k++) 
    {
       for (int i=0; i<N; i++)  
       {
           for (int j=0; j<N; j++)   
           {
              if (i==j)
                 *(*(arr + i) + j) = 0;
              else if (*(*(arr + i) + j) == 0 && *(*(arr + i) + k) != 0 && *(*(arr + k) + j) != 0)
               {
                *(*(arr + i) + j) = *(*(arr + i) + k) + *(*(arr + k) + j);
               }
                else if (*(*(arr + i) + k) == 0 || *(*(arr + k) + j) == 0)
                {
                       *(*(arr + i) + j) = *(*(arr + i) + j);
                }
                    else if (*(*(arr + i) + k) + *(*(arr + k) + j) < *(*(arr + i) + j))
                        *(*(arr + i) + j) = *(*(arr + i) + k) + *(*(arr + k) + j);
           }
       }
    }
    // printArr(arr);
      return 1;
}

int isConect(int (*arr)[N]){
    int i, j;
    scanf("%d", &i);
    scanf("%d", &j);
    // if (i==j)
    // {
    //     printf("False");
    //     return 1;
    // }
    if (*(*(arr + i) + j) != 0  ||  *(*(arr + j) + i) != 0)     //graf 'lo mechuvan'
        printf("True");
    else
        printf("False");
return 1;
}
  
int shortest(int (*arr)[N]){
    int i, j;
    scanf("%d", &i);
    scanf("%d", &j);
    // if (i==j)
    // {
    //     printf("-1");
    //     return 1;
    // }
    if (*(*(arr + i) + j) != 0  ||  *(*(arr + j) + i) != 0)
        if ((*(*(arr + i) + j) < *(*(arr + j) + i))  &&  (*(*(arr + i) + j) != 0)) //print the minimum 
            printf("%d", *(*(arr + i) + j));
            else
                printf("%d", *(*(arr + j) + i));
    else
        printf("-1");
return 1;
}
