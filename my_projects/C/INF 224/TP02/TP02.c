
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "TP02.h"


void charPermu(char *cht){
    // I couldn't manage to do it :(
}

int calculateLength(char* ch){
    int count=0;
    while (*ch !='\0'){
        count++;
        ch++;
    }
    return count;
}
int findFact(const int n){
    if(n==0) return 1;
    else return (n*findFact(n-1));
}
int are_friends(const int number1, const int number2) {
    int i, j, sum1 = 1, sum2 = 1;
    

    for (i = 2; i <= (int)sqrt(number1); i++) {
        if (number1 % i == 0) {
            sum1 += i;
            if (i != number1 / i) {
                sum1 += number1 / i;
            }
        }
    } 
    for (i = 2; i <= (int)sqrt(number2); i++) {
        if (number2 % i == 0) { 
            sum2 += i;
            if (i != number2 / i) {
                sum2 += number2 / i;
            }
        }
    }
    return ((number1 == sum2) && (number2 == sum1)) ? 1 : 0;
}

int is_harshad(int number){
    int sumofDigits=0;
    int operandNumber = number;
    while(operandNumber!=0){
        sumofDigits += operandNumber % 10;
        operandNumber /= 10;
    }
    return (number % sumofDigits == 0) ? 1 : 0;
}

int digital_root(int num){
    int sumofDigits=0;
    int operandNumber = num;
    while(1){
        while(operandNumber!=0){
            sumofDigits += operandNumber % 10;
            operandNumber /= 10;
        }
        if(sumofDigits<10) break;
        else{
            operandNumber = sumofDigits;
            sumofDigits=0;
            continue;
        }
    }
    return sumofDigits;
}

int isConsecutive(int length, int arr[]){
    for(int i=0; i<length; i++){
        for(int j=i; j>0; j--){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }    
    }
    int incrementAmount = arr[1]-arr[0];
    for(int k=0;k<length-1;k++){
        if(arr[k+1]!=arr[k]+incrementAmount) return 0;
    }
    return 1;
}



int findMissingSmallest(int length, int arr[]) {
    int l = 0;

    for (int k=0;k<length;k++) {
        if (arr[k] == l) {
            l++;
            continue;
        } else {
            return l;
        }
    }

    return l;
}
int day_of_year(int day, int mon, int year){
    int sum=0;
    if(day<1||mon<1||year<1) return -1;
    else if(mon>12) return -1;
    else if(mon==2){
        if(year%4==0){
            if(day>29) return -1; 
        } 
        else if(day>28) return -1;  
    }
    else if(mon==4||mon==6||mon==9||mon==11){
        if(day>30) return -1;
    }
    else if(day>31) return -1;
    
    sum = day+31*(mon-1); 
    if(year%4==0){
        if(mon>11) sum -= 6;
        else if(mon>9) sum -= 5;
        else if(mon>6) sum -= 4;
        else if(mon>4) sum -= 3;
        else if(mon>2) sum -= 2;    
    }
    else{
        if(mon>11) sum -= 7;
        else if(mon>9) sum -= 6;
        else if(mon>6) sum -= 5;
        else if(mon>4) sum -= 4;
        else if(mon>2) sum -= 3;    
    }
    return sum;

}

int closest_prime(int value){
    int j, isprime;
    int operandValue = value;
    while(operandValue>=2){
        isprime=1;
        for(j=2; j<=sqrt(operandValue); j++){
            if(operandValue%j==0){
                isprime=0;
                break;
            }
        }
        
        if(isprime){
            if(operandValue == value) operandValue--;
            else return operandValue;   
        }     
        operandValue--;
    }
    return -1;
    
}

bool FHRNTester(){
    int a, b, c, d, i=0, HRN;
    int* arrayofHRNumbers = (int*) malloc(sizeof(int));
    printf("Enter four numbers that will suit a^3+b^3 = c^3+d^3: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(pow(a,3)+pow(b,3)!=pow(c,3)+pow(d,3)) return false;
    else{
        HRN=pow(a,3)+pow(b,3);
        arrayofHRNumbers[i]=HRN;
        i++;
    }
}


void findHardyRamanujanNumbers(int limit){
    int* arrayofHRNumbers = (int*)malloc(sizeof(int));
    int i,j,k,l,HRN,count=0;
    int *uniqueResults = (int*)malloc(sizeof(int));
    int uniqueCount = 0;
    int isUnique;
    for(i=0;i<cbrt(limit);i++){
        for(j=0;j<cbrt(limit);j++){
            for(k=0;k<cbrt(limit);k++){
                for(l=0;l<cbrt(limit);l++){
                    if(i==k||i==l||j==k||j==l||i==j||k==l) continue;
                    else{
                        if(pow(i,3)+pow(j,3)==pow(k,3)+pow(l,3)){
                            HRN=pow(i,3)+pow(j,3);
                            int isUnique = 1;
                            
                            for (int n=0; n<uniqueCount; n++) {
                                if (HRN == uniqueResults[n]) {
                                    isUnique = 0;
                                    break;
                                }
                            }
                            
                            if(isUnique){
                                uniqueResults = (int*) realloc(uniqueResults,(uniqueCount+1)*sizeof(int));
                                uniqueResults[uniqueCount] = HRN;
                                arrayofHRNumbers = (int*) realloc(arrayofHRNumbers,(count+1)*sizeof(int));
                                arrayofHRNumbers[count]=HRN;
                                uniqueCount++;
                                printf("%d = %d^3 + %d^3 = %d^3 + %d^3\n", arrayofHRNumbers[count], i, j, k, l);
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }
    free(arrayofHRNumbers);
    free(uniqueResults);
}

