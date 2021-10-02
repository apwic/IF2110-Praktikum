// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 15-09-2021
// Topik    : ADT List Dinamik

/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include "boolean.h"
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (int*) malloc(capacity * sizeof(int));
    NEFF(*l) = 0;
}

void dealocate(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    if (i >= 0 && i < CAPACITY(l)) {
        return true;
    } else {
        return false;
    }
}

boolean isIdxEff(ListDin l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    if (i >= 0 && i < NEFF(l)) {
        return true;
    } else {
        return false;
    }
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
    return (NEFF(l) == 0);
}

boolean isFull(ListDin l) {
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return (NEFF(l) == CAPACITY(l));
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
    int n;
    scanf("%d", &n);
    while (n < 0 || n > CAPACITY(*l)) {    
        scanf("%d", &n);
    }

    NEFF(*l) = n;
    int i;
    for (i=0; i<n;i++) {
        scanf("%d", &ELMT(*l,i));
        }     
}

void displayList(ListDin l) {
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
    if (isEmpty(l)) {
        printf("[]");
    } else {
        int i;
        printf("[");
        for (i = 0; i<NEFF(l); i++) {
            if (i != NEFF(l) -1) {
                printf("%d,", ELMT(l, i));
            } else {
                printf("%d", ELMT(l, i));
            } 
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
    ListDin ld;
    CreateListDin(&ld, CAPACITY(l1));
    NEFF(ld) = NEFF(l1);
    if (plus) {
        int i;
        for (i=0;i<length(l1);i++){
            ELMT(ld, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else {
        int i;
        for (i=0;i<length(l2);i++){
            ELMT(ld, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return ld;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    if (NEFF(l1) == NEFF(l2)) {
        int i = 0;
        boolean flag = true;
        while ((i <=  NEFF(l1)-1) && (flag)) {
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
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
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
void extremes(ListDin l, ElType *max, ElType *min) {
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
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
void copyList(ListDin lIn, ListDin *lOut) {
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
    dealocate(lOut);
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    int i;
    for (i = 0; i<NEFF(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

ElType sumList(ListDin l) {
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
    if (isEmpty(l)) {
        return 0;
    } else {
        int i, sum;
        sum = 0;

        for (i = 0; i < length(l); i++) {
            sum += ELMT(l, i);
        }
        return sum;
    }
}

int countVal(ListDin l, ElType val) {
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    int i, count;
    count = 0;

    if (isEmpty(l)) {
        return count;
    } else {
        for (i = 0; i < length(l); i++) {
            if (ELMT(l, i) == val) {
                count++;
            }
        }
        return count;
    }
}

boolean isAllEven(ListDin l) {
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
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
void sort(ListDin *l, boolean asc) {
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
void insertLast(ListDin *l, ElType val) {
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
    if (!isFull(*l)) {
        NEFF(*l) = NEFF(*l) + 1;
        ELMT(*l, length(*l)-1) = val;
    }
}

void deleteLast(ListDin *l, ElType *val) {
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    if (!isEmpty(*l)) {
        *val = ELMT(*l, length(*l)-1);
        NEFF(*l) = NEFF(*l) - 1;
    }  
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num) {
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    // CAPACITY(*l) = CAPACITY(*l) + num;
    ListDin lTemp;
    CreateListDin(&lTemp, CAPACITY(*l));
    copyList(*l, &lTemp);
    int temp = NEFF(*l);
    dealocate(l);
    CreateListDin(l, CAPACITY(lTemp) + num);
    NEFF(*l) = temp;
    
    int i;
    for (i = 0; i < length(lTemp); i++) {
        ELMT(*l, i) = ELMT(lTemp, i);
    }
}

void shrinkList(ListDin *l, int num) {
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    // CAPACITY(*l) = CAPACITY(*l) - num;
    ListDin lTemp;
    CreateListDin(&lTemp, CAPACITY(*l));
    copyList(*l, &lTemp);
    int temp = NEFF(*l);
    dealocate(l);
    CreateListDin(l, CAPACITY(lTemp) - num);
    if (NEFF(lTemp) > CAPACITY(lTemp) - num){
        NEFF(*l) = CAPACITY(lTemp) - num;
    } else {
        NEFF(*l) = NEFF(lTemp);
    }

    int i;
    for (i = 0; i < NEFF(*l); i++) {
        ELMT(*l, i) = ELMT(lTemp, i);
    }
}

void compactList(ListDin *l) {
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
    // CAPACITY(*l) = NEFF(*l);
    shrinkList(l, CAPACITY(*l)-NEFF(*l));
}
