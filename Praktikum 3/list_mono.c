// NIM      : Adiyansa Prasetya Wicaksana
// Nama     : 13520044
// Tanggal  : 9 September 2021
// Topik    : List Mono

#include <stdio.h>
#include <stdlib.h>
#include "listpos.h"

int main() {
    ListPos l1, temp1, temp2;
    CreateListPos(&l1);
    readList(&l1);

    temp1 = l1;
    temp2 = l1;
    sort(&temp1, false);
    sort(&temp2, true);


    if (isListEqual(temp1, l1) && isListEqual(temp2, l1)) {
        printf("Static Monotonic List\n");
    } else if (isListEqual(temp1, l1)) {
        printf("Non-ascending Monotonic List\n");
    } else if (isListEqual(temp2, l1)) {
        printf("Non-descending Monotonic List\n");
    } else {
        printf("Non-monotonic List\n");
    }

    return 0;
}