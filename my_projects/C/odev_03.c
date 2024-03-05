
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float mean(float n[]);
float minimum(float n[]); // stdlib kütüphanesini ekledigim icin dogrudan float min ve float max oalrak tanimlayamiyorum cunku min ve max i fonksiyon olarak algiliyor sanirim o kutuphanede.
float maximum(float n[]);
float std(float n[]);

int main(int argc, char* argv){
    int i, a; // i buyuk donguler icin, a da kucuk dongu icin
    float odevtop=0;
    float n[111];
    float odevnot[6];
    
    srand(time(0));
    for(i=0; i<111; i++){
        for(a=0; a<6; a++){
            odevtop+=rand()%101;   
        }
        n[i]=odevtop/a;
        odevtop=0;
    }
    
    // asagidakiler ilgili harf notlarini alan ogrencileri saymaya yariyor:
    int AA=0;
    int BA=0;
    int BB=0;
    int CB=0;
    int CC=0;
    int F=0;
    
    for(i=0; i<111; i++){
        printf("%d. ogrencinin notu ve harf notu: %.2f - ", i+1, n[i]);
        if((mean(n) + 3*std(n)/2) <= n[i]) {
            printf("AA\n"); 
            AA++;
        }
        else if(((mean(n) + std(n)) <= n[i]) && (n[i] < (mean(n) + 3*std(n)/2))) {
            printf("BA\n"); 
            BA++;
        }
        else if(((mean(n) + std(n)/2) <= n[i]) && (n[i] < (mean(n) + std(n)))) {
            printf("BB\n"); 
            BB++;
        }
        else if((mean(n) <= n[i]) && (n[i] < (mean(n) + std(n)/2))) {
            printf("CB\n"); 
            CB++;
        }
        else if(((mean(n) - std(n)) <= n[i]) && (n[i] < mean(n))) {
            printf("CC\n"); 
            CC++;
        }
        else if(n[i] < (mean(n) - std(n))){
            printf("F\n"); 
            F++;
        }
    }
    
    printf("\n");
    printf("En yuksek ogrenci notu: %.2f\n", maximum(n));
    printf("En dusuk ogrenci notu: %.2f\n\n", minimum(n));
    printf("Sinif ortalamasi: %.2f\n", mean(n));
    printf("Standart sapma: %.2f\n\n", std(n));

    printf("AA: ");
    for(int k=0; k<=AA; k++){ // her birine k tanimladim
        printf("*");
    }

    printf("\n");

    printf("BA: ");
    for(int k=0; k<=BA; k++){
        printf("*");
    }

    printf("\n");

    printf("BB: ");
    for(int k=0; k<=BB; k++){
        printf("*");
    }

    printf("\n");

    printf("CB: ");
    for(int k=0; k<=CB; k++){
        printf("*");
    }

    printf("\n");

    printf("CC: ");
    for(int k=0; k<=CC; k++){
        printf("*");
    }
    printf("\n");

    printf("F:  ");
    for(int k=0; k<=F; k++){
        printf("*"); 
    }

    return 0;
}

float mean(float n[]){
int i;
float geneltop=0, genelort;
for(i=0; i<111; i++){
    geneltop+=n[i];   
}
genelort=geneltop/i;
return genelort;
}

float maximum(float n[]){
    float max=n[0];
    for(int i=0; i<111; i++){
        if(max<n[i]){
            max=n[i];
        }
    }
    return max;
}

float minimum(float n[]){
    float min=n[0];
    for(int i=0; i<111; i++){
        if(min>n[i]){
            min=n[i];    
        }
    }
    return min;
}

float std(float n[]){
    int i;
    float stddev; // standart sapma
    float meantop=0; // dizinin ilgili elemani ile dizideki tüm elemanlarinin ortalamasinin farkinin karesi
    for(i=0; i<111; i++){
        meantop+=pow((n[i]-mean(n)),2);
    }
    stddev=sqrt(meantop/(i-1));
    return stddev;
}