#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#define N 10

// la definition de la structure
struct complexe{
	double reel;
	double imaginaire;
}; 

// retourne la partie reelle du nombre complexe z
double partieReel(struct complexe z) {
	return z.reel;
}

// retourne la partie imaginaire du nombre complexe z
double partieImag(struct complexe z) {
	return z.imaginaire;  
}

// affiche a l'ecran le nombre complexe z en format z = a + bi avec a = re(z) et b = im(z)
void afficheComplexe(struct complexe *z) {
	if (z->imaginaire<0) printf("z = %.2lf - %.2lfi\n", z->reel, -1*(z->imaginaire));
	else printf("z = %.2lf + %.2lfi\n", z->reel, z->imaginaire);
}

// calcule et retourne le module du nombre complexe z
double moduleComplexe(struct complexe *z) {
	double grandeur = sqrt(pow(z->reel,2)+pow(z->imaginaire,2));
	return grandeur;
}

// saisit de l'utilisateur le nombre complexe z, remplit les champs (re, im) et le retourne a la fin
struct complexe saisitComplexe(void) {
	struct complexe c;
	printf("Entrez la partie reelle: ");
	scanf("%lf", &c.reel);
	printf("Entrez la partie imaginaire: ");
	scanf("%lf", &c.imaginaire);
	return c;
}

// multiplie 2 nombres complexes a et b, retourne le nombre complexe resultant
struct complexe multiComplexe(struct complexe a, struct complexe b) {
	struct complexe multiplicationComplexe;
	multiplicationComplexe.reel= (partieReel(a)*partieReel(b)-partieImag(a)*partieImag(b));
	multiplicationComplexe.imaginaire=(partieImag(b)*partieReel(a)+partieImag(a)*partieReel(b));
	return multiplicationComplexe;
}

// remplit alleatoirement un tableau de nombre complexe de longueur N
void remplitTableau(struct complexe *z) {
	z->reel=(rand()%1000)/100.0;
	z->imaginaire=(rand()%1000)/100.0;
}
int main() {
	// definissez ici les variables que vous allez utiliser comme par ex. int i, etc...
	int i;
	double maxModule;
	int maxIndice;
	srand(time(0));
	// definissez les nombres complexes que vous allez utiliser
	struct complexe complexe1;
	struct complexe complexe2;
	struct complexe complexemultiplie;
	struct complexe complexeMax; 
	printf("Entrez le 1er nombre complexe\n");
	// saisissez de l'utilisateur le premier nombre
	complexe1=saisitComplexe();
	// affichez le premier nombre a l'ecran
	afficheComplexe(&complexe1);
	printf("\nEntrez le 2eme nombre complexe\n");
	// saisissez de l'utilisateur le deuxieme nombre
	complexe2=saisitComplexe();
	// affichez le deuxieme nombre a l'ecran
	afficheComplexe(&complexe2);
	printf("\nMultiplication de 2 complexes\n");
	// multipliez les 2 nombres complexes
	complexemultiplie=multiComplexe(complexe1, complexe2);
	// affichez le resultat a l'ecran
	afficheComplexe(&complexemultiplie);
	// affichez a l'ecran le module du nombre complexe resultant de la multiplication
	printf("|z| = %.2lf\n", moduleComplexe(&complexemultiplie));
	// segment de controle pour voir le tableau des structures ou non
	sleep(1);
	while(1){
		int uniteControle;
		printf("\nPour voir le tableau des structures, entrez 1, sinon entrez 0: ");
		scanf("%d", &uniteControle);
		switch(uniteControle){
			case 0: break;
			case 1: 
				printf("\n-------- Tableau des structures --------\n");
				
				// definissez un tableau de nombres complexes de N elements
				struct complexe autresComplexes[N];
				
				// remplissez le tableau avec des nombres complexes alleatoire
				for(i=0;i<N;i++){
					remplitTableau(&autresComplexes[i]);
				}
				
				// affichez les elements de tableau et leur module
				for(i=0;i<N;i++){
					printf("complexe[%d]: z = %.2lf + %.2lfi, |z|= %.2lf\n", i, autresComplexes[i].reel, autresComplexes[i].imaginaire, moduleComplexe(&autresComplexes[i]));
				}

				printf("\nLe nombre complexe avec le max module:\n");
				
				// trouvez et affichez le nombre complexe qui a le module max, son module et son indice
				maxModule=moduleComplexe(&autresComplexes[0]);
				for(i=1;i<N;i++){
					if (maxModule<moduleComplexe(&autresComplexes[i])){
						complexeMax.reel=partieReel(autresComplexes[i]);
						complexeMax.imaginaire=partieImag(autresComplexes[i]);
						maxModule=moduleComplexe(&complexeMax);
						maxIndice=i;
					}
				}
				printf("z = %.2lf + %.2lfi\n|z| = %.2lf\nindice = %d", complexeMax.reel, complexeMax.imaginaire, maxModule, maxIndice);
				break;
			default:
				printf("Veuillez entrer seulement 1 et 0 !");
				continue;
			}
		break;
	}
	return 0;
}
