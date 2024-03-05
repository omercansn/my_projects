#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
int main(int argc, char* argv[]){
    srand(time(0));
    int dizi[12];
    printf("Before:");
    for(int i=0; i<12;i++){
        dizi[i]=rand()%77;
        printf("%d ", dizi[i]);
    }
    printf("\nAfter:");
    for(int i=0; i<12;i++){
        int a=atoi(argv[1]);
        printf("%d ", a+dizi[i]);
    }
    return 0;
}