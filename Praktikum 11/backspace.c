// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 11-11-2021
// Topik    : Backspace

#include <stdio.h>
#include "boolean.h"
#include "stack_linked.h"
// #include "stack_linked.c"

int main() {
    int n, m, i, j, elmtN, elmtM;
    Stack stackN, stackM;
    ElType temp, val1, val2;
    boolean compare;

    scanf("%d %d", &n, &m);
    CreateStack(&stackN);
    CreateStack(&stackM);

    for (i = 0; i<n; i++){
        scanf("%d", &elmtN);
        if (elmtN != 0) {
            push(&stackN, elmtN);
            // printf("%d\n", elmtN);
        } else {
            if (!isEmpty(stackN)){
                pop(&stackN, &temp);
            }
            // printf("%d\n", temp);
        }
    }
    
    for (j = 0; j<m; j++){
        scanf("%d", &elmtM);
        if (elmtM != 0){
            push(&stackM, elmtM);
            // printf("%d\n", elmtM);
        } else {
            if (!isEmpty(stackM)){
                pop(&stackM, &temp);
            }
            // printf("%d\n", temp);
        }
    }

    compare = true;
    while ((!isEmpty(stackN) && !(isEmpty(stackM)) && compare)){
        pop(&stackN, &val1);
        // printf("%d\n", val1);
        pop(&stackM, &val2);
        // printf("%d\n", val2);
        if (val1 != val2){
            compare = false;
        }
    }

    if ((isEmpty(stackN) && !isEmpty(stackM)) || (!isEmpty(stackN) && isEmpty(stackM))){
        compare = false;
    } 

    if (compare){
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }

    return 0;
}