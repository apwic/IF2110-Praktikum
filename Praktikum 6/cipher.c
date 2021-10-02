// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 30-09-2021
// Topik    : Implementasi Word Machine

#include <stdio.h>
#include "wordmachine.h"


boolean endWord;
Word currentWord;

char geser(char c, int i) {
    int a;
    a = 'A';
    return ((c - a + i)%26 + a);
}

int main() {
    startWord();
    int i, n;
    i = 0;
    n = currentWord.length; // panjang kata pertama

    while (!endWord) {
        for (i=0; i<currentWord.length; i++){
            printf("%c",geser(currentWord.contents[i], n));
        }
        if (currentChar == MARK) {
            printf("%c\n", MARK);
        } else {
            printf("%c", BLANK);
        }
        advWord();
    }
    return 0;
}