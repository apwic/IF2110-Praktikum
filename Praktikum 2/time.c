#include "stdio.h"
#include "stdlib.h"
#include "time.h"


/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S) {
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
   if ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59)) {
      return true;
   } else {
      return false;
   }
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
TIME MakeTIME (int HH, int MM, int SS) {
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */ 
   TIME T;
   if (IsTIMEValid(HH, MM, SS)) {
      Hour(T) = HH;
      Minute(T) = MM;
      Second(T) = SS;
      return T;
   }
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T) {
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
   int HH, MM, SS;
   scanf("%d %d %d", &HH, &MM, &SS);

   while (!(IsTIMEValid(HH, MM, SS))) {
      printf("Jam Tidak valid\n");
      scanf("%d %d %d", &HH, &MM, &SS);
   }

   *T = MakeTIME(HH, MM, SS);
}
   
void TulisTIME (TIME T) {
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
   printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T) {
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
   int h = 3600*Hour(T);
   int m = 60*Minute(T);
   int s = Second(T);

   return h + m + s;
}

TIME DetikToTIME (long N){
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
   int detik = N % 86400;

   if (detik < 0) {
      detik += 86400;
   } 
   
   int h = detik/3600;
   detik = detik % 3600;
   int m = detik/60;
   detik = detik % 60;
   int s = detik;

   return MakeTIME(h,m,s);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2) {
/* Mengirimkan true jika T1=T2, false jika tidak */
   if (TIMEToDetik(T1) == TIMEToDetik(T2)) {
      return true;
   } else {
      return false;
   }
}

boolean TNEQ (TIME T1, TIME T2){
/* Mengirimkan true jika T1 tidak sama dengan T2 */
   if (TIMEToDetik(T1) == TIMEToDetik(T2)) {
      return false;
   } else {
      return true;
   }
}

boolean TLT (TIME T1, TIME T2) {
/* Mengirimkan true jika T1<T2, false jika tidak */
   if (TIMEToDetik(T1) < TIMEToDetik(T2)) {
      return true;
   } else {
      return false;
   }
}

boolean TGT (TIME T1, TIME T2){
/* Mengirimkan true jika T1>T2, false jika tidak */
/* *** Operator aritmatika TIME *** */
   if (TIMEToDetik(T1) < TIMEToDetik(T2)) {
      return false;
   } else {
      return true;
   }
}

TIME NextDetik (TIME T) {
/* Mengirim 1 detik setelah T dalam bentuk TIME */ 
   return DetikToTIME(TIMEToDetik(T) + 1);
}

TIME NextNDetik (TIME T, int N){
/* Mengirim N detik setelah T dalam bentuk TIME */
   return DetikToTIME(TIMEToDetik(T) + N);
}

TIME PrevDetik (TIME T){
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
   return DetikToTIME(TIMEToDetik(T) - 1);
}

TIME PrevNDetik (TIME T, int N) {
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
   return DetikToTIME(TIMEToDetik(T) - N);
}

long Durasi (TIME TAw, TIME TAkh) {
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
   int dAw = TIMEToDetik(TAw);
   int dAkh = TIMEToDetik(TAkh);

   if (dAw > dAkh) {
      return (86400 + dAkh - dAw);
   } else {
      return (dAkh - dAw);
   }
}