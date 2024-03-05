#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

    if((argc<2)){
        printf("Sekil ismi girmedigin icin uygulama calistirilamiyor. Lutfen sekil ismi girerek tekrar dene!");
        return 310;
    }
    else if((argc<3)){
        printf("Lutfen en az bir sayi girerek tekrar dene!");
        return 311;
    }

    int islemNo, i, j, k; // i, satirlar icin; j, sutunlar icin; k bosluklar icin; islemNo da farkli varyasyonlar icindir.
    int satirNo, sutunNo, maxAsterisk, altTaban, ustTaban;
    /*  
        satirNo ucgen, kare, dikdortgen ve paralelkenar icin; 
        sutunNo kare, dikdortgen ve paralelkenar icin;
        maxAsterisk baklava icin;
        altTaban ve ustTaban yamuk icindir. 
    */

    maxAsterisk=atoi(argv[2]);
    sutunNo=atoi(argv[3]);
    satirNo=atoi(argv[2]);
    ustTaban=atoi(argv[2]);
    altTaban=atoi(argv[3]);

    if(strcmp(argv[1],"ucgen")==0){
        printf("Dik ucgen cizmek icin 1, eskenar ucgen cizmek icin 2 gir: ");
        scanf("%d", &islemNo);
        switch(islemNo){
            case 1:
            {
                for(i=1; i<=satirNo; i++){
                    for(j=1; j<=i; j++){
                        printf("* ");
                    }
                    printf("\n");
                }
                break;
            }
            case 2:
            {
                for(i=1; i<=satirNo; i++){
                    for(k=1; k<=(satirNo-i); k++){
                        printf(" ");
                    }
                    for(j=1; j<=i; j++){
                        printf("* ");
                    }
                    printf("\n");
                }
                break;
            }
            default:
            printf("Yanlis bir sayi girdin, lutfen dogru bir sayi girerek tekrar dene!");
        }
    }

    else if(strcmp(argv[1],"kare")==0){
        for(i=1; i<=satirNo; i++){
            for(j=1; j<=satirNo; j++){
                printf("* ");
            }
            printf("\n");
        }
    }

    else if(strcmp(argv[1],"dikdortgen")==0){
        if(argc<4) printf("Lutfen bir sayi daha gir!");
        else{
            for(i=1; i<=satirNo; i++){
                for(j=1; j<=sutunNo; j++){
                    printf("* ");
                }
                printf("\n");
            }
        }
    }

    else if(strcmp(argv[1],"baklava")==0){
        for(i=1; i<=maxAsterisk; i++){
            for(k=1; k<=(maxAsterisk-i); k++){
                printf(" ");
            }
            for(j=1; j<=(i); j++){
                printf("* ");
            }
            printf("\n");
        }
        
        for(i=maxAsterisk; i<=maxAsterisk*2-1; i++){
            for(k=1; k<=(i-maxAsterisk+1); k++){
                printf(" ");
            }
            for(j=(maxAsterisk*2-1-i); j>=1; j--){
                printf("* ");
            }
            printf("\n");
        }
    }

    else if(strcmp(argv[1],"paralelkenar")==0){
        if(argc<4) printf("Lutfen bir sayi daha gir!");
        else{
            for(i=1; i<=satirNo; i++){
                for(k=1; k<=(satirNo-i); k++){
                    printf(" ");
                }
                for(j=1; j<=sutunNo; j++){
                    printf("* ");
                }
                printf("\n");
            }
        }
    }

    else if(strcmp(argv[1],"yamuk")==0){
        if(argc<4) printf("Lutfen bir sayi daha gir!");
        else{
            if(ustTaban-altTaban==0) {
                printf("Alt tabanla ust taban degeri ayni olamaz. Lutfen farkli degerler girerek tekrar dene!");
            } else{
                printf("Normal yamuk icin 1, dik yamuk icin 2 gir: ");
            scanf("%d", &islemNo);
            switch(islemNo){
                case 1:
                {
                    if((ustTaban-altTaban)>0){
                        for(i=1; i<=(ustTaban-altTaban)+1; i++){
                            for(k=1; k<=i-1; k++){
                                printf(" ");
                            }
                            for(j=ustTaban-i+1; j>=1; j--){
                                printf("* ");
                            }
                            printf("\n");
                        }
                    }
                    else if((ustTaban-altTaban)<0){
                        for(i=1; i<=(altTaban-ustTaban)+1; i++){
                            for(k=1; k<=(altTaban-ustTaban)+1-i; k++){
                                printf(" ");
                            }
                            for(j=1; j<=ustTaban+i-1; j++){
                                printf("* ");
                            }
                            printf("\n");
                        }
                    }
                    break;
                }
                case 2:
                {
                    if((ustTaban-altTaban)>0){
                        for(i=1; i<=(ustTaban-altTaban)+1; i++){
                            for(j=ustTaban-i+1; j>=1; j--){
                                printf("* ");
                            }
                            printf("\n");
                        }
                    }
                    else if((ustTaban-altTaban)<0){
                        for(i=1; i<=(altTaban-ustTaban)+1; i++){
                            for(j=1; j<=ustTaban+i-1; j++){
                                printf("* ");
                            }
                            printf("\n");
                        }
                    }
                    break;
                    default:
                    printf("Yanlis bir sayi girdin, lutfen dogru bir sayi girerek tekrar dene!");
                }
            }
            
                
            }
        }
    }
    else{
        printf("Lutfen dogru bir sekil ismi gir!");
        return 312;
    }
    return 0;
}