#include <iostream>
#include <string>
#include <math.h>
#include "vehicule.h"
using namespace std;

int main(){
    
    Vehicule* vehicule_array[3];
    vehicule_array[0] = new Voiture("Toyota");
    vehicule_array[1] = new Avion("Boeing");
    vehicule_array[2] = new Bateau("TCG");

    for(int i=0; i<3; i++){
        vehicule_array[i]->QuestceQueCest();
        vehicule_array[i]->setLargeur(pow(4,i+1));
        vehicule_array[i]->setTaille(pow(8,i+1));
        cout << "Ma marque est " << vehicule_array[i]->getMarque() << ", " 
        << "Ma largeur est " << vehicule_array[i]->getLargeur() << ", " 
        << "ma taille est " << vehicule_array[i]->getTaille() << endl;
    }
    return 0;
}