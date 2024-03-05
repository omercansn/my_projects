#include <math.h>
#include <stdlib.h>
#define MIN_INT 0 
#define MAX_INT 1
/*
* Point yapisi koordinat duzleminde
* bir noktayi ifade eder.
* iki tane elemani vardir: x, y */
struct Point{ 
	float x;
	float y; 
};
/*
* Bir cemberi ifade eder.
* Bir merkez noktasi ve yaricapi elemanlaridir. */
struct Circle{
	struct Point center; 
	float r;
};
/*
* [min,max] arasinda rastgele sayi uretir */
float float_rand( float min, float max ) {
	float scale = rand() / 32767.0; /*[0, 1] */ 				// "RAND_MAX undeclared" hatasi aldigim icin 32767 ye boldum
	return min + scale * ( max - min ); /* [min, max] */ 
}

/*
* **********************************************SORU1
* Point tipindeki iki degısken arasinda
* uzakligi hesaplar.
* Uzaklik hesabi: ((x1-x2)^2 + (y1-y2)^2)^(1/2) */

double distance(struct Point *a, struct Point *b) {
	double dist=sqrt(pow(((a->x)-(b->x)),2)+pow(((a->y)-(b->y)),2));
	return dist;
}

/*
* **********************************************SORU2
* Verilen bir noktanin verilen cember
* icinde olup olmadigina bakar. 
*/
int is_in_circle(struct Point *a, struct Circle *c) {
	if(distance(a,&(c->center))<=(c->r)){
		return 1;
	}
	else return 0;
}
	

/*
* **********************************************SORU3
* N adet struct Point oluşturur ve pt_array ile adreslenen
* dizide tutar.
*
* Her Point'in x ve y değerleri [MIN_INT ,MAX_INT] = [0, 1.0] arasındadır 
*/
void create_point_array(struct Point *pt_array ,int N){
	for(int i=0;i<N;i++){
		pt_array[i].x=float_rand(0,1.0);
		pt_array[i].y=float_rand(0,1.0);
	}
}

/*
* **********************************************SORU5
* [MIN_INT ,MAX_INT] = [0, 1.0] arasında rastegele üretilen 
*  N adet struct Point'in kaçı merkezi 0.5 ve yarıçapı 0.5 olan 
*  çemberin içindedir? Bu sayı pi/4'e yakındır.
*
* Buna göre pi'yi hesaplayan fonksiyonu yazınız.
*/
double calculate_pi(int number_in, int number_all) {
	return (double)((number_in/number_all))*4.0;
}



