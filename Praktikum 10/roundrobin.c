// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 04-11-2021
// Topik    : Round Robin

#include <stdio.h>
#include "list_circular.h"
// #include "list_circular.c"   

float average(List l){
/* Menghasilkan nilai rata-rata elemen l. l tidak kosong. */
    /* KAMUS LOKAL */
    Address p = FIRST(l);
    float sum, length;

    /* ALGORITMA */
    sum = 0;
    length = 1;

    while (NEXT(p) != FIRST(l)){
        sum += INFO(p);
        length++;
        p = NEXT(p);
    }

    sum += INFO(p);
    return (sum/length);
}

void deleteRR(List *l, ElType tQ){
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
- jika INFO(last)>tQ, maka last "diantrikan" kembali sebagai first elemen dengan INFO(last)=INFO(last)-tQ
- jika INFO(last)<=tQ, maka deleteLast(l,x) dan menampilkan x ke layar */
/* Jika l kosong, cetak "List kosong" */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai aturan round-robin.
l mungkin menjadi kosong. */
    /* KAMUS LOKAL */
    Address last = FIRST(*l);
    ElType val;

    /* ALGORITMA */
    while(NEXT(last) != FIRST(*l)){
        last = NEXT(last);
    }

    if (INFO(last) <= tQ){
        printf("%d\n", INFO(last));
        deleteLast(l, &val);
    } else {
        printf("%d\n", tQ);
        INFO(last) = INFO(last) - tQ;
        FIRST(*l) = last;
    }
}

int main() {
    /* KAMUS */
    List l;
    int tQ, tA;
    char op;
    boolean flag;

    /* ALGORITMA */
    CreateList(&l);
    flag = true;

    // Pengecekan terhadap tQ
    scanf("%d", &tQ);
    while (tQ <= 0){
        scanf("%d", &tQ);
    }

    while (getchar() != '\n');

    // Loop utama
    while (flag){
        scanf("%c", &op);
        while (getchar() != '\n');
        if (op == 'A'){
            scanf("%d", &tA);
            while (getchar() != '\n');
            if (tA > 0){
                insertFirst(&l, tA);
            }
        } else if (op == 'D'){
            if (!isEmpty(l)){
                deleteRR(&l, tQ);
            } else {
                printf("List kosong\n");
            }
        } else if (op == 'F'){
            if (!isEmpty(l)){
                printf("%.2f\n", average(l));
            } else {
                printf("Proses selesai\n");
            }
            flag = false;
        } else {
            printf("Kode salah\n");
        }
    }
}