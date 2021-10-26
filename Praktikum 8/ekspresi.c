// Nama     : Adiyansa Prasetya Wicaksana   
// NIM      : 13520044
// Tanggal  : 21-10-2021
// Topik    : Ekspresi

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "stack.h"
#include "tokenmachine.h"
#include "math.h"

boolean isOperator(){
    return (currentToken.tkn != 'b');
}

int evaluate(int op1, int op2,char operator){
    int result;

    switch (operator){
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1 - op2;
            break;
        case '*':
            result = op1 * op2;
            break;
        case '/':
            result = op1 / op2;
            break;
        case '^':
            result = pow(op1, op2);
            break;
    }

    return result;
}

int main() {
    Stack S;
    ElType val1, val2;

    CreateStack(&S);
    startToken();

    if (endToken) {
        printf("Ekspresi kosong\n");
    } else {
        do {
            if (!isOperator()) {
                push(&S, currentToken.val);
                printf("%d\n", currentToken.val);
            } else {
                pop(&S, &val2);
                pop(&S, &val1);
                push(&S, evaluate(val1, val2, currentToken.tkn));
                printf("%d %c %d\n", val1, currentToken.tkn, val2);
                printf("%d\n",evaluate(val1, val2, currentToken.tkn));
            }
            advToken();
        } while (!endToken);
        printf("Hasil=%d\n", TOP(S));
    }
    
    return 0;
}