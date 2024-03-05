#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int convert_to_decimal(long long int binary_number){
    int i;
    long long int digit = (long long int)log10(binary_number)+1;
    long long int sumof_digitValue = 0;
    for(i=1; i<=digit; i++){
        long long int digitValue = binary_number % (long long int)pow(10, i) / (long long int)pow(10,i-1);
        if(!(digitValue==1 || digitValue==0)){
            return -1;
        }
        sumof_digitValue += digitValue*pow(2,i-1);
    }
    return(sumof_digitValue);
}


int main(void){
    long long int n;
    printf("Enter a binary number to convert to decimal form: ");
    scanf("%lld", &n);
    if(convert_to_decimal(n)==-1){
        printf("This is not a binary number. Please enter a binary one !");
        return -1;
    };
    printf("In decimal form: %d", convert_to_decimal(n)); 
    sleep(1);
    printf("\nPress any key to exit...");
    getch();
    return 0;
}