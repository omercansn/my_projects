#include <stdio.h>
int main(int argc, char* argv[]){
    FILE*f=fopen("C:\\Users\\Tuf\\Desktop\\les fichiers codeaux\\xd\\sehir\\sehir.txt","r");
    if(f==NULL){ 
        printf("File not found.");
        return 1;
    }
    int i;
    int plaka[81];
    char sehir[81][20];
    int uzaklik[81];
    char *maxsehir=sehir[0];
    char *minsehir=sehir[0];
    int max=uzaklik[0];
    int min=uzaklik[0];
    for(i=0;!feof(f);i++) {
        fscanf(f,"%d %s %d\n",&plaka[i],sehir[i],&uzaklik[i]);
        if(max<uzaklik[i]){
            max=uzaklik[i];
            maxsehir=sehir[i];
        } 
        if(min>uzaklik[i]){
            min=uzaklik[i];
            minsehir=sehir[i];
        } 
    }
    printf("Istanbul'a en uzak sehir: %s (%d km)\n", maxsehir, max);
    printf("Istanbul'a en yakin sehir: %s (%d km)\n", minsehir, min);
    float ort=0;
    ort=(max+min)/2;
    printf("Iki sehrin Istanbul'a ortalama uzakligi: %.2f", ort);
    fclose(f);
    return 0;
}