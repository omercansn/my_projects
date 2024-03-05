#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char* argv[]){

    char* string=argv[1];
    if(argc<3){
        printf("\nEksik arguman girdin adamim...\n");
        return 1;
    }
    if(isdigit(*string)){
        printf("\nOnce yazdirilacak karakter dizisini gir dostum.\n");
        return 3;
    }
    int times=atoi(argv[2]);
    if(times<0){
        printf("\nNegatif sayi mi? Uzgunum fakat negatif sayi kadar yazdirma diye bir sey henuz icat edilmedi dostum.\n");
        return 4;
    }
    else{
        if(argc>3) printf("\nFazla arguman girdin... amaan bosver kendini yorma bir daha, iste sonucun:\n");
        for(int i=1; i<=times; i++){
            printf("%s ", argv[1]);
        }
    }
    printf("\n");
    return 0;
}