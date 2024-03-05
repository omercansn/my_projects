#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
    FILE* fichier1 = fopen("fichier.txt", "r");
    FILE* fichier2 = fopen("turingtest.txt", "w");
    FILE* fichier3 = fopen("stats.txt", "w");
    if(fichier1==NULL) {
        printf("\"fichier.txt\" not found");
        return 99;
    }
    if(fichier2==NULL) {
        printf("\"turingtest.txt\" not found");
        return 98;
    }
    if(fichier3==NULL) {
        printf("\"stats.txt\" not found");
        return 97;
    }
    int i,j; // for dongusu icin
    int lignes=0; // satir basi sayaci
    int mots=0; // kelime sayaci
    char c[4096]; // karakter karakter okumak icin
    char controle1; // A-Z kontrol birimi
    char controle2; // a-z kontrol birimi
    char newChar[4096]; // c-3
    int alphabetCounter[26]={0}; // harf sayaci
    char* nomFichier1="fichier.txt";
    char* nomFichier2="turingtest.txt";
    if(argc<3){
        printf("Arguments non suffisants. Veuillez entrer plus d'arguments.");
        return 96;
    }
    if(strcmp(argv[1], nomFichier1) != '\0'){
        printf("Nom de premier fichier incorrect, veuillez reessayer.\n");
        return 95; 
    }
    if(strcmp(argv[2], nomFichier2) != '\0'){
        printf("Nom de deuxieme fichier incorrect, veuillez reessayer.");
        return 94; 
    }
    for(i=0;!feof(fichier1); i++){
        fscanf(fichier1, "%c", &c[i]);
        if(feof(fichier1)){
            fprintf(fichier2, "\n");
            lignes++;
            mots++;
            break;
        }
        if(c[i]=='\n'){
            fprintf(fichier2, "\n");
            lignes++;
        }
        newChar[i]=c[i]-('#'-' ');
        fprintf(fichier2, "%c", newChar[i]);
        if(isspace(newChar[i])) mots++;
        if(isalpha(newChar[i])){
            for(controle1='A',controle2='a',j=0 ; controle1<='Z',controle2<='z',j<26 ; controle1++,controle2++,j++){
                if(newChar[i]==controle1 ^ newChar[i]==controle2){
                    alphabetCounter[j]++;
                    break;
                }
            }
        }
    }
    printf("Le fichier est dechiffre!");
    
    fprintf(fichier3, "Nom du fichier: %s\n", argv[2]);
    fprintf(fichier3, "Nombres de lignes: %d\n", lignes);
    fprintf(fichier3, "Nombres de mots: %d\n", mots);
    fprintf(fichier3, "Nombre d'occurence des lettres:\n");
    for(char k='a',j=0; k<='z',j<26; k++,j++) 
        fprintf(fichier3, "%c : %d\n", k, alphabetCounter[j]);
    fclose(fichier1);
    fclose(fichier2);
    fclose(fichier3);
    return 0; 
}