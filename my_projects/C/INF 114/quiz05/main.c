#include"data.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 100

/* Alistirma 6
 * Bir dosyadan veri okuyup, uzerinde lineer regresyon
 *  uygulayan programi yazin.
 * Adim 1: Veriyi read_data fonksiyonu ile okuyup mainData 
 *         degiskenine yazin. read_data fonksiyonuna vereceginiz
 *         dosya adini argv kullanarak komut satirindan almalisiniz.
 * Adim 2: Veriyle ilgili bilgileri get_information 
 *         fonksiyonunu kullanarak ekrana basin.
 * Adim 3: Veriyi sort_values fonksiyonunu kullanarak
 *         siralayin.
 * Adim 4: sorted_data.txt isimli bir dosya olusturup,
 *         icine siralanmis X ve Y degerlerini yazin.
 *         (data.txt ile ayni formatta yazilmali!)
 * Adim 5: find_line fonksiyonunu kullanarak veri uzerinde
 *         lineer regresyon uygulayin. Elde ettiginiz 
 *         sonuclari a ve b degiskenlerine yazin. Ardindan
 *         bu sonuclari ekrana basin.
 * 
 * Basarilar
 */
int main(int argc, char *argv[]){
  data mainData;
  mainData.dataX=malloc(SIZE * sizeof(int));
  mainData.dataY=malloc(SIZE * sizeof(int));
  char* filename = "data.txt";
  // Adim 1
  // TODO
  if(argc<2){
    printf("You must enter the filename!");
    exit(0);
  }
  if((strcmp(argv[1], filename ) != '\0')){
    printf("Wrong filename.");
    exit(0);
  }
  read_data(argv[1], &mainData);
  // Adim 2
  // TODO
  printf("\nInformations about x:\n");
  get_information(mainData.dataX);
  printf("\nInformations about y:\n");
  get_information(mainData.dataY);
  // Adim 3
  // TODO
  sort_values(&mainData);
  // Adim 4
  // TODO
  FILE * fdest = fopen("sorted_data.txt", "w");
  if(fdest==NULL){
    printf("\"sorted_data.txt\" not found. Program will be terminated.");
    exit(0);
  }
  for(int m=0; m<SIZE; m++){
    fprintf(fdest, "%d , %d\n", mainData.dataX[m], mainData.dataY[m]);
  }
  // Adim 5
  double a; 
  double b;
  // TODO
  find_line(&mainData, &a, &b);
  if(b<0) printf("\nY = %.2lf - %.2lfX", a, (-1)*b);
  else printf("\nY = %.2lf + %.2lfX", a, b);
  fclose(fdest);
  free(mainData.dataX);
  free(mainData.dataY);
  return 0;
}
