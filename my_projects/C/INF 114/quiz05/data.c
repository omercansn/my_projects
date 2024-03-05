#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100
/* ONEMLI BILGI
 * Asagida kullanilan tum listelerin uzunluklari
 * yukaridaki SIZE'a esit olacaktir.
 * Fonksiyonlarinizda (read_data haric) gonlunuzce kullanin.
 */


/* Alistirma 1
 * Istediginiz bir sort algoritmasini yazin
 * Bu algoritmayi data.h dosyasinda tanimlamayi unutmayin!
 * Dogru calistigi surece onceki calismalardan kopyalabilirsiniz.
 * Tip: Kolay bir tane secin, asagida bunu tekrar yazacaksiniz
 *      (Performans cok onemli degil, 100 eleman olacak zaten)
 */
// TODO: SORT FONKSIYONU
void insertion_sort(int *array, int size) {
  for (int i=1; i<size; i++) {
    int pivot = array[i];
    int j;
    for(j=i;j>0;j--){
      if(pivot<array[j-1]){
        array[j]=array[j-1];
      }
      else break;
    }
    array[j] = pivot;
  }
}


/* Alistirma 2
 * Dosyayi satir satir okuyup, dt degiskeninin
 *  dataX ve dataY arraylerine yazan fonksiyonu yazin.
 * Dosyadaki sayilar virgul (,) ile ayrilmistir. Virgulden
 *  onceki deger x, sonraki deger y degeridir.
 * Dosyayi okuyamazsa error versin ki bilelim :)
 * Tip 1: feof() komutu dosya okurken cok kullanislidir.
 * Tip 2: Isiniz bitince dosyayi kapatmayi unutmayin.
 */
void read_data(char* filename, data* dt){
  FILE* fsrc = fopen(filename, "r");
  if(fsrc==NULL){
    printf("%s not found. Program will be terminated.", filename);
    exit(0);
  }
  int i;
  for(i=0; !feof(fsrc); i++){
    fscanf(fsrc, "%d , %d", &dt->dataX[i], &dt->dataY[i]);
  }
  fclose(fsrc);
  
}



/* Alistirma 3
 * Aldigi param_list degiskeninde asagidaki bilgileri 
 *  sirasiyla bulup ekrana basan fonksiyon:
 * - Eleman sayisi
 * - Ortalama
 * - Minimum
 * - Maximum
 * Tip: Min ve max bulmadan once sort ederseniz 
 *      isiniz cok daha kolay olur.
 */
void get_information(int* param_list){
  int i;
  int elementCounter=0;
  double sum=0.0;
  double aver;
  insertion_sort(param_list, SIZE);
  int min=param_list[0];
  int max=param_list[SIZE-1];
  for(i=0; i<SIZE; i++){
    sum+=param_list[i];
    elementCounter++;
  }
  aver = sum / elementCounter;
  for(i=0; i<SIZE; i++){
    if(min>param_list[i]) min=param_list[i];
    if(max<param_list[i]) max=param_list[i];
  }
  printf("Number of elements: %d\n", elementCounter);
  printf("Average of elements: %.2lf\n", aver);
  printf("Minimum element: %d\n", min);
  printf("Maximum element: %d\n", max);
}


/* Alistirma 4
 * Yukarida yazdiginiz sorting fonksiyonunu dt 
 *  degiskenine uygulayan sorting fonksiyonunu yazin.
 * Bu fonksiyonu yazarken onceki yazdiginiz sort
 *  fonksiyonunu kullanamazsiniz. Yani bu fonksiyon
 *  kendi basina calismali.
 */
void sort_values(data* dt){
  int j;
  for(j=1; j<SIZE; j++){
    int pivot1=dt->dataX[j];
    int pivot2=dt->dataY[j];
    int k;
    for(k=j; k>0; k--){
      if(pivot1<dt->dataX[k-1]){
        dt->dataX[k]=dt->dataX[k-1];
      }
      if(pivot2<dt->dataY[k-1]){
        dt->dataY[k]=dt->dataY[k-1];
      }
      else break;
    }
    dt->dataX[k]=pivot1;
    dt->dataY[k]=pivot2;
  }
}


/* Alistirma 5
 * dt degiskenindeki X ve Y degerlerini kullanarak
 *  lineer regresyon hesabi yapan fonksiyonu yazin.
 * Yani, Y = a + bX seklindeki formulun a ve b 
 *  parametreleri bulunacak.
 * Fonksiyon sonucu ekrana basmamali ve deger 
 *  geri dondurmemeli, b ve a uzerinden sonuca erisilmeli.
 * Tip: Gerekli formullerin hepsi PDF'te verilmistir.
 */
void find_line(data* dt, double* a, double* b){
  int n;
  double sumofx = 0.0;
  double sumofy = 0.0;
  double sumofxsq = 0.0;
  double sumofxy = 0.0;
  for(n=0; n<SIZE; n++){
    sumofx += dt->dataX[n];
    sumofy += dt->dataY[n];
    sumofxsq += pow(dt->dataX[n], 2);
    sumofxy += dt->dataX[n]*dt->dataY[n];
  }
  
  double denominator = n*sumofxsq - pow(sumofx,2);
  *a = (sumofy*sumofxsq - sumofx*sumofxy) / denominator;
  *b = (n*sumofxy - sumofx*sumofy) / denominator;
}

