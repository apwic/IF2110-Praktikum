#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "time.c"

int main() {
    int N, i;
    TIME T1, T2, Temp1, Temp2, TMin, TMax;

    scanf("%i", &N);
    printf("\n[%d]\n", 1);
    BacaTIME(&T1);
    BacaTIME(&T2);
    
    if (TGT(T1, T2)) {
        printf("%i",Durasi(T2, T1));
        TMin = T2;
        TMax = T1;

    } else {
        printf("%i",Durasi(T1, T2));
        TMin = T1;
        TMax = T2;
    }     

    for (i = 2; i < (N+1); ++i) 
    {
        printf("\n[%d]\n", i);
        BacaTIME(&T1);
        BacaTIME(&T2);
        
        if (TGT(T1, T2)) {
            printf("%i",Durasi(T2, T1));
            
            if (TGT(T1, TMax)){
                TMax = T1;
            }

            if (TLT(T2, TMin)){
                TMin = T2;
            }

        } else {
            printf("%i",Durasi(T1, T2));
            
            if (TGT(T2, TMax)){
                TMax = T2;
            }

            if (TLT(T1, TMin)){
                TMin = T1;
            }
        }
        
    }

    printf("\n");
    TulisTIME(TMin);
    printf("\n");
    TulisTIME(TMax);

    return 0;
}

