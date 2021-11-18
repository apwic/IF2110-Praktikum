// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 11-11-2021
// Topik    : mQueue

#include <stdio.h>
#include "boolean.h"
#include "queue_linked.h"
// #include "queue_linked.c"

int main() {
    int n, i, count;
    ElType t;
    Queue Q;
    Address p;

    CreateQueue(&Q);
    scanf("%d", &n);

    for (i=0; i<n; i++){
        scanf("%d", &t);
        enqueue(&Q, t);
        p = ADDR_HEAD(Q);
        count = 1;

        while (p != ADDR_TAIL(Q)){
            if (t - INFO(p) <= 300){
                count++;
            }
            p = NEXT(p);
        }
        printf("%d\n", count);
    }
    return 0;
}