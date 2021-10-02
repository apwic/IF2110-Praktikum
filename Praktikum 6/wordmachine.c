// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 28-09-2021
// Topik    : Word Machine


#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

boolean endWord;
Word currentWord;

void ignoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK) {
        adv();
    }
}

void startWord() {
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    start();
    ignoreBlank();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        endWord = false;
        copyWord();
    }
}

void advWord() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
    ignoreBlank();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        copyWord();
        ignoreBlank();
    }
}

void copyWord() {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    int i;
    i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK)) {
        currentWord.contents[i] = currentChar;
        adv();
        i++;
    }
    
    if (i > CAPACITY) {
        currentWord.length = CAPACITY;
    } else {
        currentWord.length = i;
    }
}   