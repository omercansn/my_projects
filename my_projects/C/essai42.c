// Decimal to Binary Calculator

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

void convert_to_binary(int number){
    int i=0;
    int digit=(int)(log2(number)); 
    // actual digit is 1 more but as you know the arrays start at zeroth index so I didn't add 1 in order to make the calculation easier
    char one='1', zero='0';
    char* binary_digits;
    binary_digits = (char*) malloc(digit*sizeof(int));
    while(number>0){
        binary_digits[i] = number % 2 == 1 ? one : zero;
        number/=2;
        i++;
    }
    char temp = NULL;
    for(i=0; i<=digit/2; i++){
        temp=binary_digits[i];
        binary_digits[i]=binary_digits[digit-i];
        binary_digits[digit-i]=temp;
    } 
    temp = NULL;
    for(i=0; i<=digit; i++){
        printf("%c", binary_digits[i]);
    }
    free(binary_digits);
}


int main(void){
    int n;
    printf("Enter a decimal number to convert to binary form: ");
    scanf("%d", &n);
    printf("In binary form: "); convert_to_binary(n);
    sleep(1);
    printf("\nPress any key to exit...");
    getch();
    return 0;
}
