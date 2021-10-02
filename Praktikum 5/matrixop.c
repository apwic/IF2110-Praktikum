#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

float rowMean (Matrix m, Index i){
    float total, n, temp;
    int a;
    total = 0;
    n = COLS(m);

    for (a = 0; a<n; a++) {
        temp = ELMT(m, i, a);
        total = total + temp;
    }

    return (total/n);
}

float colMean (Matrix m, Index i) {
    float total, n, temp;
    int a;
    total = 0;
    n = ROWS(m);

    for (a = 0; a<n; a++) {
        temp = ELMT(m, a, i);
        total = total + temp;
    }
    return (total/n);
}

void rowExtremes (Matrix m, Index i, ElType *max, ElType *min) {
    int a,n;
    n = COLS(m);
    *max = ELMT(m, i, 0);
    *min = ELMT(m, i, 0);

    for (a=0;a<n;a++){
        if (ELMT(m, i, a) > *max) {
            *max = ELMT(m, i, a);
        }
        
        if (ELMT(m, i, a) < *min) {
            *min = ELMT(m, i ,a);
        }
    }
}

void colExtremes (Matrix m, Index i, ElType *max, ElType *min) {
    int a,n;
    n = ROWS(m);
    *max = ELMT(m, 0, i);
    *min = ELMT(m, 0, i);

    for (a=0;a<n;a++){
        if (ELMT(m, a, i) > *max) {
            *max = ELMT(m, a, i);
        }
        
        if (ELMT(m, a, i) < *min) {
            *min = ELMT(m, a, i);
        }
    }
}

int countValOnRow (Matrix m, Index i, ElType val) {
    int a, n, count = 0;
    n = COLS(m);

    for (a=0; a<n;a++) {
        if (val == ELMT(m, i ,a)) {
            count ++;
        }
    }

    return count;
}

int countValOnCol (Matrix m, Index i, ElType val) {
    int a, n, count = 0;
    n = ROWS(m);

    for (a=0; a<n;a++) {
        if (val == ELMT(m, a, i)) {
            count ++;
        }
    }

    return count;
}