// NIM      : Adiyansa Prasetya Wicaksana
// Nama     : 13520044
// Tanggal  : 8 September 2021
// Topik    : ADT List

#include <stdio.h>
#include <stdlib.h>
#include "listpos.h"


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l) {
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan i */
    int i = 0;
    for (i; i < CAPACITY; i++) {
        ELMT(*l, i) = VAL_UNDEF;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l) {
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
    int i = 0;
    int n = 0;
    while ((i < CAPACITY) && (ELMT(l, i) != VAL_UNDEF)) {
        i++;
        n++;
    }
    return n;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    if ((i >= 0) && (i <= (CAPACITY-1))) {
        return true;
    } else {
        return false;
    }
}

boolean isIdxEff(ListPos l, int i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    if ((i >= 0) && (i <= (length(l)-1)))  {
        return true;
    } else {
        return false;
    }
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l) {
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return (length(l) == 0);
}
/* *** Test List penuh *** */
boolean isFull(ListPos l) {
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return (length(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l) {
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
    int n;
    CreateListPos(l);

    scanf("%d", &n);
    while (n < 0 || n > CAPACITY) {    
        scanf("%d", &n);
    }

    int i;
    for (i=0; i<n;i++) {
        scanf("%d", &ELMT(*l,i));
        }     
}

void displayList(ListPos l) {
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
    if (length(l) == 0) {
        printf("[]");
    } else {
        int i;
        printf("[");
        for (i = 0; i<length(l); i++) {
            if (i != length(l) -1) {
                printf("%d,", ELMT(l, i));
            } else {
                printf("%d", ELMT(l, i));
            } 
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus) {
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
    ListPos lp;
    CreateListPos(&lp);
    if (plus) {
        int i;
        for (i=0;i<length(l1);i++){
            ELMT(lp, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else {
        int i;
        for (i=0;i<length(l2);i++){
            ELMT(lp, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return lp;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2) {
    if (length(l1) == length(l2)) {
        int i = 0;
        boolean flag = true;
        while ((i <=  length(l1)-1) && (flag)) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                flag = false;
            } else {
                i++;
            }
        }
        return flag;

    } else {
        return false;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    if (isEmpty(l)) {
        return IDX_UNDEF;
    } else {
        int i = 0;
        boolean flag = false;
        while (!flag && (i < length(l))) {
            if (ELMT(l,i) == val) {
                flag = true;
            } else {
                i++;
            }
        }

        if (flag) {
            return i;
        } else {
            return IDX_UNDEF;
        }
    }
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (i=0;i<length(l);i++){
        if (ELMT(l,i) > *max) {
            *max = ELMT(l, i);
        }
        
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l) {
/* Menghailkan true jika semua elemen l genap */
    int i = 0;
    boolean flag = true;
    while ((flag) && (i < length(l))) {
        if ((ELMT(l, i) % 2) != 0) {
            flag = false;
        } else {
            i++;
        }
    }
    return flag;
}

/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc) {
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    int i, j, n, temp;
    n = length(*l);
    
    if (asc) {
        for (i=0; i < n; i++) {
            for (j = 0; j < n - i -1; j++) {
                if (ELMT(*l, j) > ELMT(*l, j+1)){
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j+1);
                    ELMT(*l, j+1) = temp;
                }
            }
        }
    } else {
    for (i=0; i < n; i++) {
        for (j = 0; j < n - i -1; j++) {
            if (ELMT(*l, j) < ELMT(*l, j+1)){
                temp = ELMT(*l, j);
                ELMT(*l, j) = ELMT(*l, j+1);
                ELMT(*l, j+1) = temp;
                }
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    if (!isFull(*l)) {
        ELMT(*l, length(*l)) = val;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPos *l, ElType *val) {
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT(*l, length(*l)-1);
    ELMT(*l, length(*l)-1) = VAL_UNDEF;
}

   
// displayList(l1);
// printf("\n");
// displayList(temp1);
// printf("\n");
// displayList(temp2);
// printf("\n");

// int i=0;
// boolean flag_non_des = true;
// while ((i <= length(l1)-2) && (flag_non_des)){
//     if (!(ELMT(l1, i) <= ELMT(l1, i+1))) {
//         flag_non_des = false;
//     } else {
//         i++;
//     }
// }

// int j=0;
// boolean flag_non_asc = true;
// while ((j <= length(l1)-2) && (flag_non_asc)){
//     if (!(ELMT(l1, j) >= ELMT(l1, j+1))) {
//         flag_non_asc = false;
//     } else {
//         j++;
//     }
// }

// int k=0;
// boolean flag_stat = true;
// while ((k <= length(l1)-2) && (flag_stat)){
//     if (!(ELMT(l1, k) == ELMT(l1, k+1))) {
//         flag_stat = false;
//     } else {
//         k++;
//     }
// }

// if (flag_non_des && flag_non_asc) {
//     printf("Static Monotonic List\n");
// } else if (flag_non_asc) {
//     printf("Non-ascending Monotonic List\n");
// } else if (flag_non_des) {
//     printf("Non-descending Monotonic List\n");
// } else {
//     printf("Non-monotonic List\n");
// }
