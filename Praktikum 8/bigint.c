// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 21-10-2021
// Topik    : Big Int

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "stack.h"

int main() {
    Stack S1, S2, SPlus;
    CreateStack(&S1);
    CreateStack(&S2);
    CreateStack(&SPlus);

    char num1[100], num2[100], result;
    int i, j, tempPlus, trace;

    scanf("%s", &num1);
    scanf("%s", &num2);

    for (i=0; num1[i] != '#'; i++){
        push(&S1, num1[i]-48);
    }

    for (j=0; num2[j] != '#'; j++){
        push(&S2, num2[j]-48);
    }

    ElType val, val1, val2;
    trace = 0;

    while (!isEmpty(S1) || !isEmpty(S2)) {
        if (isEmpty(S1)){
            val1 = 0;
            pop(&S2, &val2);
        }
        else if (isEmpty(S2)){
            val2 = 0;
            pop(&S1, &val1);

        } else {
            pop(&S1, &val1);
            pop(&S2, &val2);
        }
        
        tempPlus = val1 + val2 + trace;

        if (tempPlus > 9) {
            tempPlus -= 10;
            trace = 1;
        } else {
            trace = 0;
        }

        push(&SPlus, tempPlus);
    }

    if (trace == 1) {
        push(&SPlus, 1);
    }

    while (!isEmpty(SPlus)) {
        pop(&SPlus, &val);
        printf("%d", val);
    }

    printf("\n");

    return 0;
}