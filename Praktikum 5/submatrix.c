// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 23-09-2021
// Topik    : Submatrix

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

int totalMatrix (Matrix m, int a, int b, int n){
    // Prekondisi: isSquare
    int total = 0, i,j;

    for (i=a; i<a+n; i++) {
        for (j=b; j<b+n; j++) {
            total += ELMT(m, i, j);
        }
    }

    return total;
}

int main() {
    Matrix M;
    int n, m, max, i, j, k, x;
    scanf("%d", &x);

    for (k = 0; k<x; k++) {
        scanf("%d", &n);
        CreateMatrix(n, n, &M);
        readMatrix(&M, n, n);

        scanf("%d", &m);

        max = totalMatrix(M, 0, 0, m-1);

        for (i=0; i<=(n-m);i++) {
            for (j=0; j<=(n-m); j++) {
                if (max < totalMatrix(M, i, j, m)) {
                    max = totalMatrix(M, i, j, m);
                }
            }
        }

        printf("%d\n", max);

    }

    return 0;
}