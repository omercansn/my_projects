#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <unistd.h>
#define pi 3.141592

float rad_to_deg(float deg);
float toplama(float x, float y);
float cikarma(float x, float y);
float carpma(float x, float y);
float bolme(float x, float y);
int moduler_aritmetik(float x, int y);
float trigonometri(float x);
float kare(float x);
float karekok(float x);


int main(){
    float x,y; // girilecek değerler
    int islem; // yapacağımız işlem numarası
    int b=0; // döngü kontrolü için
    printf("Hesap Makinesine Hos Geldiniz!\n");
    
    while(b>=0){
        printf("\nYapilabilecek Tum Islemler:\n1. Toplama\n2. Cikarma\n3. Carpma\n4. Bolme\n5. Moduler Aritmetik\n6. Kare Alma\n7. Karekok Alma\n8. Trigonometrik Islemler\n\n0. Kapat\n\n");
        printf("Islemi giriniz: ");
        scanf("%d", &islem);
        printf("\n");
        if(islem==0) break;
        else if(islem==1) toplama(x,y);
        else if(islem==2) cikarma(x,y);
        else if(islem==3) carpma(x,y);
        else if(islem==4) bolme(x,y);
        else if(islem==5) moduler_aritmetik(x,y);
        else if(islem==6) kare(x);
        else if(islem==7) karekok(x);
        else if(islem==8) trigonometri(x);
        else{
            b--;
            printf("Lutfen gecerli bir sayi giriniz!");
        }
        printf("\n");
        sleep(1);
        b++;
    }
    printf("Yapilan islem adedi: %d\n", b);
    printf("Hoscakalin!");
    sleep(1);
    printf("\nCikmak icin bir tusa basin...");
    getch();
    return 0;
}

float toplama(float x, float y){
    float toplam;
    printf("1. degeri girin: ");
    scanf("%f", &x);
    printf("2. degeri girin: ");
    scanf("%f", &y);
    toplam=x+y;
    if(toplam==(int)toplam) printf("Sonuc: %d", (int)toplam);
    else printf("Sonuc: %f", toplam);
    
    return toplam;
}

float cikarma(float x, float y){
    float fark;
    printf("1. degeri girin: ");
    scanf("%f", &x);
    printf("2. degeri girin: ");
    scanf("%f", &y);
    fark=x-y;
    if(fark==(int)fark) printf("Sonuc: %d", (int)fark);
    else printf("Sonuc: %f", fark);
    return fark;
}

float carpma(float x, float y){
    float carpim;
    printf("1. degeri girin: ");
    scanf("%f", &x);
    printf("2. degeri girin: ");
    scanf("%f", &y);
    carpim=x*y;
    if(carpim==(int)carpim) printf("Sonuc: %d", (int)carpim);
    else printf("Sonuc: %f", carpim);
    return carpim;
}

float bolme(float x, float y){
    float bolme=0;
    printf("1. degeri girin: ");
    scanf("%f", &x);
    printf("2. degeri girin: ");
    scanf("%f", &y);
    bolme=x/y;
    if(x==0 && y==0) printf("0/0 belirsizdir!");
    else if(y==0) printf("Bu deger tanimsizdir!");
    else if(bolme==(int)bolme) printf("Sonuc: %d", (int)bolme);
    else printf("Sonuc: %f", bolme);
    return bolme;
}

int moduler_aritmetik(float x, int y){
    int mod;
    printf("Sayiyi girin: ");
    scanf("%f", &x);
    if(x!=(int)x){
        printf("Tam olmayan sayilarin moduler aritmetigi soz konusu degildir!");
        return -1;
    }
    printf("Kac ile bolumden kalanin yazdirilacagini girin: ");
    scanf("%d", &y);
    
    mod = (int)x % y;
    printf("%d nin %d ile bolumunden kalan: %d", (int)x, y, mod);
}

float kare(float x){
    float Kare;
    printf("Sayiyi girin: ");
    scanf("%f", &x);
    Kare=x*x;
    if(Kare==(int)Kare) printf("Sonuc: %d", (int)Kare);
    else printf("Sonuc: %f", Kare);
    return(Kare);
}

float karekok(float x){
    float Karekok;
    printf("Sayiyi girin: ");
    scanf("%f", &x);
    Karekok=sqrt(x);
    if(Karekok==(int)Karekok) printf("Sonuc: %d", (int)Karekok);
    else printf("Sonuc: %f", Karekok);
}

float rad_to_deg(float deg){
    float rad;
    rad=(deg*pi)/180;
    return rad;
}

float trigonometri(float x){
    
    int islemt; // yapacağımız işlem numarası
    int a; // döngüyü yönetmek için 
    float k; // 90 ve katlarını tanımlamak için
    while(a==0){
        printf("\nTum trigonometrik islemler:\n");
        printf("1. Sinus alma:\n");
        printf("2. Kosinus alma:\n");
        printf("3. Tanjant alma:\n");
        printf("4. Kotanjant alma:\n");
        printf("5. Sekant alma:\n");
        printf("6. Kosekant alma:\n\n");
        printf("0. Ana Menuye Don\n\n");
        
        printf("Yapilacak islem: ");
        scanf("%d", &islemt);
        if(islemt==0){
            printf("Ana menuye donuldu.");
            break;
        }
        
        if(islemt==1){
            printf("Aci degeri girin: ");
            scanf("%f", &x);
            x=rad_to_deg(x);
            k=x/(pi/2);
            printf("Sonuc: %.3f", sin(x));
            
        }
        else if(islemt==2){
            printf("Aci degeri girin: ");
            scanf("%f", &x);
            x=rad_to_deg(x);
            k=x/(pi/2);
            printf("Sonuc: %.3f", cos(x));
            
        }
        else if(islemt==3){ 
            printf("Aci degeri girin: ");
            scanf("%f", &x);
            x=rad_to_deg(x);
            k=x/(pi/2);
            if((int)k%2!=0 && k==(int)k) 
                printf("Bu deger tanimsizdir!\n\n");
            else{
                printf("Sonuc: %.3f", tan(x));
                
            }
        }
        else if(islemt==4){
            printf("Aci degeri girin: ");
            scanf("%f", &x);
            x=rad_to_deg(x);
            k=x/(pi/2);
            if((int)k%2==0 && k==(int)k) 
                printf("Bu deger tanimsizdir!\n\n");
            else {
                printf("Sonuc: %.3f", 1/tan(x));
                
            }
            
        }
        else if(islemt==5){
            printf("Aci degeri girin: ");
            scanf("%f", &x);
            x=rad_to_deg(x);
            k=x/(pi/2);
            if((int)k%2!=0 && k==(int)k) 
                printf("Bu deger tanimsizdir!\n\n");
            else{
                printf("Sonuc: %.3f", 1/cos(x));
                
            }
        }
        else if(islemt==6){
            printf("Aci degeri girin: ");
            scanf("%f", &x);
            x=rad_to_deg(x);
            k=x/(pi/2);
            if((int)k%2==0 && k==(int)k) 
                printf("Bu deger tanimsizdir!\n\n");
            else {
                printf("Sonuc: %.3f", 1/sin(x));
                
            }
        }
        else {
            printf("Lutfen gecerli bir sayi girin!\n\n");
        }
    sleep(1);
    }
    return x;     
}
