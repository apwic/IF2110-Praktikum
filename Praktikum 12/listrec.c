// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 18-11-2021
// Topik    : List Rekursif
#include "listrec.h"

/* Manajemen Memori */
Address newNode(ElType x){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l){
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
    return (l == NULL);
}

int isOneElmt(List l){
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
    return (!isEmpty(l) && isEmpty(tail(l)));
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l){
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
    return INFO(l);
}

List tail(List l){
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
    return NEXT(l);
}

List konso(List l, ElType e){
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
    Address p;
    p = newNode(e);
    if (p == NULL) {
        return l;
    } else {
        // Insert First
        NEXT(p) = l;
        return p;
    }
}

List konsb(List l, ElType e){
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 
    if (isEmpty(l)){
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l){
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
    if (isEmpty(l)){
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}

void displayList(List l){
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
    if (!isEmpty(l)) {
        printf("%d\n",head(l));
        displayList(tail(l));
    }
}

ElType maxList(List l){
    ElType max;

    if (length(l) <= 1){
        return head(l);
    } else if (length(l) == 2){
        if (head(l) >= head(tail(l))){
            return head(l);
        } else {
            return head(tail(l));
        }
    } else {
        max = maxList(tail(l));
        if (head(l) > max){
            return head(l);
        } else {
            return max;
        }
    }
}

ElType minList(List l){
    ElType min;

    if (length(l) <= 1){
        return head(l);
    } else if (length(l) == 2){
        if (head(l) >= head(tail(l))){
            return head(tail(l));
        } else {
            return head(l);
        }
    } else {
        min = minList(tail(l));
        if (head(l) > min){
            return min;
        } else {
            return head(l);
        }
    }
}

ElType sumList(List l){
    ElType sum;
    sum = 0;

    if (length(l) <= 1){
        return head(l);
    } else {
        sum += head(l) + sumList(tail(l));
        return sum;
    }
}

float averageList(List l){
    float sum, len;
    sum = sumList(l);
    len = length(l);
    return sum/len;
}

List inverseList(List l){
    if (length(l) <= 1){
        return l;
    } else {
        return konsb(inverseList(tail(l)), head(l));
    }
}

List splitPos(List l){
    if (isEmpty(l)){
        return NULL;
    } else {
        if (head(l) >= 0){
            return konso(splitPos(tail(l)), head(l));
        } else {
            return splitPos(tail(l));
        }
    }
}

List splitNeg(List l) {
    if (isEmpty(l)){
        return NULL;
    } else {
        if (head(l) < 0){
            return konso(splitNeg(tail(l)), head(l));
        } else {
            return splitNeg(tail(l));
        }
    }
}

void splitPosNeg (List l, List *l1, List *l2){
    *l1 = splitPos(l);
    *l2 = splitNeg(l);
}

List splitGreaterX(List l, ElType x){
    if (isEmpty(l)){
        return NULL;
    } else {
        if (head(l) > x){
            return konso(splitGreaterX(tail(l), x), head(l));
        } else {
            return splitGreaterX(tail(l), x);
        }
    }
}

List splitLowerX(List l, ElType x){
    if (isEmpty(l)){
        return NULL;
    } else {
        if (head(l) <= x){
            return konso(splitLowerX(tail(l), x), head(l));
        } else {
            return splitLowerX(tail(l), x);
        }
    }
}

void splitOnX(List l, ElType x, List *l1, List *l2){
    *l1 = splitGreaterX(l, x);
    *l2 = splitLowerX(l, x);
}

int compareList(List l1, List l2){
    if (isEmpty(l1)){
        if (isEmpty(l2)){
            return 0;
        } else {
            return -1;
        }
    } else {
        if (isEmpty(l2)){
            return 1;
        } else if (head(l1) > head(l2)){
            return 1;
        } else if (head(l1) < head(l2)){
            return -1;
        } else {
            return compareList(tail(l1), tail(l2));
        }
    }
}


boolean isMember (List l, ElType x){
    if (isEmpty(l)) {
        return false;
    } else {
        if (x == head(l)){
            return true;
        } else {
            return isMember(tail(l), x);
        }
    }
}

boolean isAllExist (List l1, List l2){
    if (isEmpty(l1)){
        return false;
    } else if (isOneElmt(l1)) {
        return isMember(l2, head(l1));
        // if (isMember(l2, head(l1))){
        //     return isAllExist(l2, tail(l1));
        // } else {
        //     return false;
        // }
    } else {
        return isAllExist(tail(l1), l2) && isMember(l2, head(l1));
    }
}