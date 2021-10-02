// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 21-09-2021
// Topik    : ADT Matrix

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m) {
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j) {
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
    return (i >= 0 && j >= 0) && (i < ROW_CAP && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m) {
/* Mengirimkan Index baris terbesar m */
    return ROWS(m) - 1;
}

Index getLastIdxCol(Matrix m) {
/* Mengirimkan Index kolom terbesar m */
    return COLS(m) - 1;
}

boolean isIdxEff(Matrix m, Index i, Index j) {
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return (i >= 0 && j >= 0) && (i < ROWS(m) && j < COLS(m));
}
ElType getElmtDiagonal(Matrix m, Index i) {
/* Mengirimkan elemen m(i,i) */
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes) {
/* Melakukan assignment MRes = MIn */
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    int i, j;
    for (i=0; i<ROWS(mIn);i++) {
        for (j=0; j<COLS(mIn);j++) {
            ELMT(*mRes, i, j) = ELMT(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
    int i, j;
    CreateMatrix(nRow, nCol, m);
    for (i=0; i<nRow;i++) {
        for (j=0; j<nCol;j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m) {
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/  
    int i,j;
    for (i=0; i<ROWS(m);i++) {
        for (j=0; j<COLS(m);j++) {
            if (j == COLS(m) - 1 && i == ROWS(m) - 1) {
                printf("%d", ELMT(m, i, j));
            } else if (j == COLS(m) - 1) {
                printf("%d\n", ELMT(m, i, j));
            } else {
                printf("%d ", ELMT(m, i, j));
            }
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
    Matrix m;
    int i,j;
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    for (i=0; i<ROWS(m);i++) {
        for (j=0; j<COLS(m);j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) + ELMT(m2, i ,j);
        }
    }
    return m;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    Matrix m;
    int i,j;
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    for (i=0; i<ROWS(m);i++) {
        for (j=0; j<COLS(m);j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) - ELMT(m2, i ,j);
        }
    }

    return m;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    Matrix m;
    int i,j,k;
    CreateMatrix(ROWS(m1), COLS(m2), &m);
    for (i=0; i<ROWS(m);i++) {
        for (j=0; j<COLS(m);j++) {
            int temp;
            temp = 0;
            for (k=0; k<COLS(m1); k++) {
                temp = temp + (ELMT(m1, i, k) * ELMT(m2, k, j));
            }
            ELMT(m, i, j) = temp;
        }
    }

    return m;
}
Matrix multiplyConst(Matrix m, ElType x) {
/* Mengirim hasil perkalian setiap elemen m dengan x */
    Matrix mOut;
    CreateMatrix(ROWS(m), COLS(m), &mOut);
    int i,j;
    for (i=0; i<ROWS(m);i++) {
        for (j=0; j<COLS(m);j++) {
            ELMT(mOut, i, j) = x*ELMT(m, i, j);
        }
    }

    return mOut;
}
void pMultiplyConst(Matrix *m, ElType k) {
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
    *m = multiplyConst(*m, k);
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    if ((count(m1) == count(m2)) && (getLastIdxCol(m1) == getLastIdxCol(m2))) {
        int i, j;
        boolean flag = true;
        i = 0;
        while (i < ROWS(m1) && flag) {
            j = 0;
            while (j < COLS(m1) && flag) {
                if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                    flag = false;
                } else {
                    j++;
                }
            }
            i ++;
        }
        return flag;

    } else {
        return false;
    }
}

boolean isNotEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    return (!isEqual(m1,m2));
}

boolean isSizeEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    return (ROWS(m1) == ROWS(m2)) && (COLS(m1) == COLS(m2));
}

/* ********** Operasi lain ********** */
int count(Matrix m) {
/* Mengirimkan banyaknya elemen m */
    return (ROWS(m)*COLS(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    return (ROWS(m) == COLS(m));
}

boolean isSymmetric(Matrix m) {
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
    if (isSquare(m)) {
        int i, j;
        boolean flag = true;
        i = 0;
        while (i < ROWS(m) && flag) {
            j = 0;
            while (j < COLS(m) && flag) {
                if (ELMT(m, i, j) != ELMT(m, j, i)) {
                    flag = false;
                } else {
                    j++;
                }
            }
            i ++;
        }
        return flag;

    } else {
        return false;
    }
}

boolean isIdentity(Matrix m) {
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    int i, j;
    boolean flag = true;
    if (isSquare(m)) {
        i = 0;
        while (i < ROWS(m) && flag) {
            j = 0;
            while (j < COLS(m) && flag) {
                if (i == j) {
                    if (ELMT(m, i, j) != 1) {
                        flag = false;
                    } else {
                        j++;
                    }
                } else {
                    if (ELMT(m, i, j) != 0) {
                        flag = false;
                    } else {
                        j++;
                    }
                }
            }
            i ++;
        }
        return flag;
    } else {
        return false;
    }
}

boolean isSparse(Matrix m) {
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    int bound = (5*count(m))/100;
    int count = 0;
    int i, j;

    for (i=0; i<ROWS(m);i++) {
        for (j=0; j<COLS(m);j++) {
            if (ELMT(m, i, j) != 0) {
                count = count + 1;
            }
        }
    }

    if (count <= bound) {
        return true;
    } else {
        return false;
    }
}

Matrix inverse1(Matrix m) {
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    Matrix mOut;
    CreateMatrix(ROWS(m), COLS(m), &mOut);
    int i, j;

    for (i=0; i<ROWS(m);i++) {
        for (j=0; j<COLS(m);j++) {
            ELMT(mOut, i, j) = (-1)*ELMT(m, i, j);
        }
    }

    return mOut;
}

void pInverse1(Matrix *m) {
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    *m = inverse1(*m);
}

Matrix cofactor(Matrix m, Matrix *mTemp, int p, int q, int n) {
    int i, j, a, b;
    a = 0;
    b = 0;

    for (i = 0; i<n;i++) {
        for (j = 0; j<n;j++) {
            if (i != p && j != q) {
                ELMT(*mTemp, a, b) = ELMT(m, i, j);
                b++;
                if (b == n - 1) {
                    b = 0;
                    a++;
                }
            }
        }
    }
}

float determinantMatrix (Matrix m, int n) {
    float d = 0;

    if (n == 1) {
        return ELMT(m, 0, 0);

    } else {
        Matrix mTemp;
        CreateMatrix(n, n, &mTemp);
        int sign = 1;
        int i;

        for (i=0; i<n;i++) {
            cofactor(m, &mTemp, 0, i, n);
            d += sign*ELMT(m, 0, i)*determinantMatrix(mTemp, n-1);
            sign = -sign;
        }

        return d;
    }
}


float determinant(Matrix m) {
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
    return determinantMatrix(m, ROWS(m));
}

void transpose(Matrix *m) {
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    Matrix mTemp;
    CreateMatrix(COLS(*m), ROWS(*m), &mTemp);

    int i, j;
    for (i = 0; i<ROWS(*m);i++) {
        for (j = 0; j<COLS(*m);j++) {
            ELMT(mTemp, i, j)  = ELMT(*m, j, i);
        }
    }
    copyMatrix(mTemp, m);
}
