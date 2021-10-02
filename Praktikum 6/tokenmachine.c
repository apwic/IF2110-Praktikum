// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 30-09-2021
// Topik    : Token Machine

#include "tokenmachine.h"

boolean endToken;
Token currentToken;

void ignoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK && currentChar != MARK) {
        adv();
    }
}

void startToken() {
/* I.S. : currentChar sembarang 
   F.S. : endToken = true, dan currentChar = MARK; 
          atau endToken = false, currentToken adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    start();
    ignoreBlank();
    if (currentChar == MARK) {
        endToken = true;
    } else {
        endToken = false;
        salinToken();
    }
}

void advToken() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentToken adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endToken = true.		  
   Proses : Akuisisi kata menggunakan procedure salinToken */
    ignoreBlank();
    if (currentChar == MARK) {
        endToken = true;
    } else {
        salinToken();
        ignoreBlank();
    }
}

void salinToken() {
/* Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
   I.S. : currentChar adalah karakter pertama dari Token
   F.S. : currentToken berisi Token yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata "dipotong" */
    int i;
    i = 0;
    currentToken.val = 0;
    while ((currentChar != MARK) && (currentChar != BLANK)) {
       if (currentChar == '+' ||
            currentChar == '-' ||
            currentChar == '*' ||
            currentChar == '/' ||
            currentChar == '^') {
                currentToken.val = -1;
                currentToken.tkn = currentChar;
        } else {
            currentToken.val = (currentToken.val * 10) + currentChar - 48;
            currentToken.tkn = 'b';
        }
        adv();
        i++;
    }
}

