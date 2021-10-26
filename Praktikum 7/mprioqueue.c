// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 07-10-2021
// Topik    : Driver PrioQueue

#include <stdio.h>
#include "prioqueue.h"
// #include "prioqueue.c"
#include "boolean.h"

int main() {
    int N, T, I, M, D;
    PrioQueue pq;
    CreatePrioQueue(&pq);

    scanf("%d", &N);
    int i;
    ElType temp;
    for (i=0; i<N; i++){
        scanf("%d %d %d %d", &T, &I, &M, &D);
        temp.tArrival = T;
        temp.id = I;
        temp.score = M;
        temp.dService = D;
        enqueue(&pq, temp);
    }

    if (isEmpty(pq)) {
        printf("Tidak ada layanan\n");
    } else {
        int w;
        printf("%d %d %d\n", (pq).buffer[0].tArrival, (pq).buffer[0].id, 0);
        w = (pq).buffer[0].tArrival + (pq).buffer[0].dService;
        for (i=1; i<=IDX_TAIL(pq); i++){
            if (w < (pq).buffer[i].tArrival){
                printf("%d %d %d\n", (pq).buffer[i].tArrival, (pq).buffer[i].id, 0);
                w = (pq).buffer[i].tArrival;
            } else {
                printf("%d %d %d\n", w, (pq).buffer[i].id, w-(pq).buffer[i].tArrival);
                w += (pq).buffer[i].dService;
            }

        }
        printf("\n");
    }

    return 0;
}