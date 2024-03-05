//
//  main.c
//  stack
//
//  Created by timoteosonurozcelik on 08/04/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

int is_palindrome(int number) {
    struct node* top = NULL;
    int digit = log10(number) + 1;
    int i, digitValue;
    for(i = 1; i <= digit; i++) { 
        digitValue = number % ((int)pow(10, i)) / (int)pow(10, i-1);
        push(&top, digitValue);
    }
    int reversedNumber = 0;
    int powerof10 = 1;
    while(!is_empty(top)) {
        reversedNumber += pop(&top) * powerof10;
        powerof10 *= 10; 
    }
    return(number == reversedNumber ? 1 : 0);
}
int main(int argc, const char * argv[]) {
    int i = 0;
    int N = 3;
    int arr[] = {0, 123, 232};
    for(; i<N; i++) {
        if(is_palindrome(arr[i])) {
            printf("%d is a palindrome number \n", arr[i]);
        } else {
            printf("%d is not a palindrome number \n", arr[i]);
        }
    }
    return 0;
}











