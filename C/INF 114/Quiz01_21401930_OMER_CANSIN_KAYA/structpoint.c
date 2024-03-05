// gcc structpoint.c -o structpoint.out
// ./structpoint.out  

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "structpoint.h"

int main () {
	srand(time(NULL)); 

	struct Point p1;
	struct Point *pt1 = &p1; 
	pt1->x = float_rand(0,1.0);
	pt1->y = float_rand(0,1.0);
	printf("Nokta 1: (x,y) (%f,%f)\n",pt1->x,pt1->y);


	struct Circle cp1;
	struct Circle *c1 = &cp1;
	c1->center.x = 0.5; 
	c1->center.y = 0.5;
	c1->r = 0.5; 
	printf("Kure 1: (merkez,yaricap) ((%f,%f), %f)\n",
		c1->center.x,c1->center.y,
		c1->r);

	/*
	* **********************************************SORU1
	* pt1 ve cp1 merkezi arasındaki mesafeyi ölçün. 
	*/
	double dist = distance(pt1, &(cp1.center));
	printf("Uzaklik : %lf\n",dist);

	/*
	* **********************************************SORU2
	* pt1, c1 dairesi içinde midir?. 
	*/
	int is_in = is_in_circle(pt1,c1); 
	printf("In circle : %d\n",is_in);

	/*
	* **********************************************SORU3
	* 1000 adet Point oluştur ve pt_array içinde tut
	*/
	int n_point = 1000 ;
	struct Point pt_array[n_point]; 
	create_point_array(pt_array ,n_point);
	/*
	* **********************************************SORU4
	* 1000 adet Point'ten kaçı daire içindedir?
	*/
	int i;
	int nbr_in_circle = 0 ; 
	for(i=0;i<n_point;i++){
		if(distance((pt_array+i),&(cp1.center))<=(c1->r)){
			nbr_in_circle++;
		}
	}
	/*
	* **********************************************SORU5
	* Pi hesapla
	*/
	printf("Cember icinde olanlar: %d\n",nbr_in_circle);
	double calculated_pi = calculate_pi(nbr_in_circle,n_point); 
	printf("Hesaplanan pi sayisi: %lf\n",calculated_pi);
	return 0;
}