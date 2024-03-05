#include <stdio.h>
#include <math.h>
#include <unistd.h>

int is_prime(int number);
int is_relatively_prime(int number1, int number2);
int gcd(int number1, int number2); // Greatest Common Divisor

int main(int argc, char** argv){
    int num1, num2;
    printf("Enter a number:");
    scanf("%d", &num1);
    if(is_prime(num1)){
        printf("%d is a prime number.", num1);  
    }
    else{
        printf("%d is NOT a prime number.", num1);
    }
    printf("\n");
    sleep(1);
    // Now we will practice the relatively primes.
    
    printf("Enter an another number:");
    scanf("%d", &num2);
    if(is_prime(num1)){
        printf("%d and %d are relatively prime numbers.", num1, num2);
    }
    else if(is_relatively_prime(num1,num2)){
        printf("%d and %d are relatively prime numbers.", num1, num2);
    }
    else{
        printf("%d and %d are NOT relatively prime numbers.", num1, num2);
    }
    
    return 0;
}   

int is_prime(int number){
    if (number <= 1) {
        return 0;
    }
    int rootofNumber = (int)sqrt(number);
    for(int i = 2; i<=rootofNumber; i++){
        if(number % i == 0){
            return 0;
        }
    }
    return 1;
}

int gcd(int number1, int number2) {
    if (number2 == 0) {
        return number1;
    }
    
    return gcd(number2, number1 % number2);
}

int is_relatively_prime(int number1, int number2){
    if(number1==number2) return 0;
    if(number1==number2+1 || number2==number1+1) return 1;
    if(gcd(number1,number2)==1) return 1;
    return 0;
}