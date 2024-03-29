#include "stdio.h"
#include "stdlib.h"
#include "point.h"
#include "math.h"

POINT MakePOINT (float X, float Y) {
/* Membentuk sebuah POINT dari komponen-komponennya */
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}


/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */      

void BacaPOINT (POINT *P) {
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    float X;
    float Y;
    scanf("%f %f", &X, &Y);
    *P = MakePOINT(X, Y);
}

void TulisPOINT (POINT P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
    tanpa spasi, enter, atau karakter lain di depan, belakang, 
    atau di antaranya 
    Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
 */
 /* I.S. P terdefinisi */
 /* F.S. P tertulis di layar dengan format "(X,Y)" */
    printf("(%.2f, %.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */

boolean EQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
   if (Absis(P1) ==  Absis(P2) && Ordinat(P1) == Ordinat(P2)) {
       return true;
   } else {
       return false;
   }
}

boolean NEQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 tidak sama dengan P2 */
   if (Absis(P1) ==  Absis(P2) && Ordinat(P1) == Ordinat(P2)) {
       return false;
   } else {
       return true;
   }    
}

/* *** Kelompok menentukan di mana P berada *** */

boolean IsOrigin (POINT P) {
/* Menghasilkan true jika P adalah titik origin */
    if (Absis(P) == (float)0 && Ordinat(P) == (float)0) {
        return true;
    } else {
        return false;
    }
}

boolean IsOnSbX (POINT P) {
/* Menghasilkan true jika P terletak Pada sumbu X */
    if (Ordinat(P) == 0 && !(IsOrigin(P))) {
        return true;
    } else {
        return false;
    }
}

boolean IsOnSbY (POINT P) {
/* Menghasilkan true jika P terletak pada sumbu Y */
    if (Absis(P) == 0 && !(IsOrigin(P))) {
        return true;
    } else {
        return false;
    }
}

int Kuadran (POINT P) {
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    if (Absis(P) > 0 && Ordinat(P) > 0) {
        return 1;
    } else if (Absis(P) < 0 && Ordinat(P) > 0) {
        return 2;
    } else if (Absis(P) < 0 && Ordinat(P) < 0)  {
        return 3;
    } else if (Absis(P) > 0 && Ordinat(P) < 0) {
        return 4;
    }
}


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P) {
/* Mengirim salinan P dengan absis ditambah satu */
    POINT P1;
    float nextX;

    nextX = Absis(P) + 1;
    P1 = MakePOINT(nextX, Ordinat(P));
    return P1;
}

POINT NextY (POINT P) {
/* Mengirim salinan P dengan ordinat ditambah satu */
    POINT P1;
    float nextY;

    nextY = Ordinat(P) + 1;
    P1 = MakePOINT(Absis(P), nextY);
    return P1;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    POINT P1;
    float nextX;
    float nextY;

    nextX = Absis(P) + deltaX;
    nextY = Ordinat(P) + deltaY;
    P1 = MakePOINT(nextX, nextY);
    return P1;
}

POINT MirrorOf (POINT P, boolean SbX) {
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    if (SbX) {
        POINT P1;
        float nextY;

        nextY = Ordinat(P)*(-1);
        P1 = MakePOINT(Absis(P), nextY);
        return P1;
    } else {
        POINT P1;
        float nextX;

        nextX = Absis(P)*(-1);
        P1 = MakePOINT(nextX, Ordinat(P));
        return P1; 
    }
}

float Jarak0 (POINT P) {
/* Menghitung jarak P ke (0,0) */
    float jarak;
    jarak = sqrt(pow(Absis(P),2) + pow(Ordinat(P),2));
    return jarak;
}

float Panjang (POINT P1, POINT P2) {
/* Menghitung jarak yang dibentuk antara P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
    POINT deltaPOINT;
    float jarak;

    deltaPOINT = MakePOINT(Absis(P2)-Absis(P1), Ordinat(P2)-Ordinat(P1));
    jarak = Jarak0(deltaPOINT);
    return jarak;
}

void Geser (POINT *P, float deltaX, float deltaY) {
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    POINT P1;
    float newX, newY;
    newX = Absis(*P) + deltaX;
    newY = Ordinat(*P) + deltaY;
    P1 = MakePOINT(newX, newY);
    *P = P1;
}

void GeserKeSbX (POINT *P) {
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    Ordinat(*P) += (-1)*Ordinat(*P);
}

void GeserKeSbY (POINT *P) {
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    Absis(*P) += (-1)*Absis(*P);
}

void Mirror (POINT *P, boolean SbX) {
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    if (SbX) {
        Ordinat(*P) *= -1;
    } else {
        Absis(*P) *= -1;
    }
}
 
void Putar (POINT *P, float Sudut) {
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
    float X = Absis(*P);
    float Y = Ordinat(*P);
    Absis(*P) = (cos(Sudut*M_PI/180)*X) - (sin(Sudut*M_PI/180)*Y);
    Ordinat(*P) = (sin(Sudut*M_PI/180)*X) + (cos(Sudut*M_PI/180)*Y);
}
