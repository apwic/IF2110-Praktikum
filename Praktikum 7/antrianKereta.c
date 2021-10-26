// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 07-10-2021
// Topik    : Antrian Kereta

#include <stdio.h>
#include "queue.h"
// #include "queue.c"

float avgQ (Queue q){
    int i, len;
    ElType val, temp;
    temp = 0;
    len = length(q);
    for (i = IDX_HEAD(q); i<=IDX_TAIL(q); i++){
        dequeue(&q, &val);
        temp += val;
    }
    return ((float) temp/ (float) len);
}

int main() {
    Queue q;
    int n, m, i;
    double avg;
    ElType val, temp, len;
    CreateQueue(&q);

    scanf("%d", &n);
    while (n != 0){
        if (n == 1) {
            scanf("%d", &m);
            if (isFull(q)){
                printf("Queue penuh\n");
            } else {
                enqueue(&q, m);
            }
        } else if (n == 2) {
            if (isEmpty(q)) {
                printf("Queue kosong\n");
            } else {
                dequeue(&q, &val);
            }
        }
        scanf("%d", &n);
    }

    len = length(q);

    printf("%d\n", len);
    if (len == 0){
        printf("Tidak bisa dihitung\n");
    } else {
        printf("%.2f\n", avgQ(q));
    }


    return 0;
}