// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 18-11-2021
// Topik    : Undian

#include "listrec.h"
// #include "listrec.c"

void CreateList (List *l){
    *l = NULL;
}

List splitOddIndex (List l){
    if (isEmpty(l)){
        return NULL;
    } else if (length(l) <= 2){
        return konsb(NULL, head(l));
    } else {
        return konso(splitOddIndex(tail(tail(l))), head(l));
    }
}

List splitEvenIndex (List l){
    if (length(l) <= 1){
        return NULL;
    } else {
        return konso(splitEvenIndex(tail(tail(l))), head(tail(l)));
    }
}

List splitBeforeX(List l, ElType x){
    if (isEmpty(l)){
        return NULL;
    } else if (head(l) == x){
        return NULL;
    } else {
        return konso(splitBeforeX(tail(l), x), head(l));
    }
}

List reverseList (List l){
    if (length(l) <= 1){
        return l;
    } else {
        return konsb(reverseList(tail(l)), head(l));
    }
}

int main(){
    List l;
    ElType val;
    char command;
    CreateList(&l);

    scanf("%c", &command);
    while (command != 'X'){
        if (command == 'B'){
            scanf("%d", &val);
            l = konsb(l, val);
        }
        else if (command == 'F'){
            scanf("%d", &val);
            l = konso(l, val);
        }
        else if (command == 'O'){
            l= splitOddIndex(l);
        }
        else if (command == 'E'){
            l = splitEvenIndex(l);
        }
        else if (command == 'R'){
            l = reverseList(l);
        }
        else if (command == 'P'){
            scanf("%d", &val);
            l = splitBeforeX(l, val);
        } else {
            scanf("%c", &command);
            continue;     
        }
        scanf("%c", &command);
    }

    if (isEmpty(l)){
        printf("Semua gugur\n");
    } else {
        displayList(l);
    }
}