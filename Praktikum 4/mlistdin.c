// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 16-09-2021
// Topik    : Implementasi ADT List Dinamik

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "listdin.h"

int main() {
    ListDin l;
    ElType temp;
    int n, i, countOp, op, num;
    scanf("%d", &n);
    CreateListDin(&l, n);
    readList(&l);

    scanf("%d", &countOp);
    for (i=0; i<countOp; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &num);
            if (isFull(l)) {
                printf("list sudah penuh\n");
            } else {
                insertLast(&l, num);
                printf("%d ", CAPACITY(l));displayList(l);printf("\n");
            }
        } else if (op == 2) {
            scanf("%d", &num);
            growList(&l, num);
            printf("%d ", CAPACITY(l));displayList(l);printf("\n");
        } else if (op == 3) {
            scanf("%d", &num);
            if (num > CAPACITY(l)) {
                printf("list terlalu kecil\n");
            } else {
                shrinkList(&l, num);
                printf("%d ", CAPACITY(l));displayList(l);printf("\n");
            }
        } else {
            compactList(&l);
            printf("%d ", CAPACITY(l));displayList(l);printf("\n");
        }
    }
    return 0;
}