// NIM      : Adiyansa Prasetya Wicaksana
// Nama     : 13520044
// Tanggal  : 9 September 2021
// Topik    : Implementasi ADT List

#include <stdio.h>
#include <stdlib.h>
#include "listpos.h"

int main() {
    ListPos l1;
    ElType min, max;
    int x, idx;
    CreateListPos(&l1);
    readList(&l1);
    scanf("%d", &x);
    extremes(l1,  &max, &min);
    idx = length(l1);

    if (indexOf(l1, x) != IDX_UNDEF) {
        displayList(l1);
        printf("\n");
        printf("%d", indexOf(l1, x));
        printf("\n");
        sort(&l1, true);

        if (max == x) {
            printf("maksimum\n");
        }

        if (min == x) {
            printf("minimum\n");
        }

        if (idx % 2 == 0) {
            if (ELMT(l1, idx/2 -1) == x) {
                printf("median\n");
            }
        } else {
            if (ELMT(l1, (idx/2)) == x) {
                printf("median\n");
            }
        }

    } else {
        displayList(l1);
        printf("\n");
        printf("%d tidak ada", x);
        printf("\n");
    }

    return 0;
}