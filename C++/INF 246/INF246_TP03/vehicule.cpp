#include <iostream>
#include <string.h>
#include "vehicule.h"
using namespace std;

void Vehicule::QuestceQueCest(){
    cout << "Je suis une vehicule... mais devinez laquelle ?";
}

double Vehicule::getLargeur(){
    return largeur;
}

double Vehicule::getTaille(){
    return taille;
}

char* const Vehicule::getMarque(){
    return marque;
}

Voiture::Voiture(char const Marque[]) : Vehicule(){
    strcpy(marque, Marque);
}

void Voiture::QuestceQueCest(){
    cout << "Je suis une voiture !" << endl;
}

void Voiture::setLargeur(double l){
    largeur = l;
}

void Voiture::setTaille(double t){
    taille = t;
}

Avion::Avion(char const Marque[]) : Vehicule(){
    strcpy(marque, Marque);
}

void Avion::QuestceQueCest(){
    cout << "Je suis un avion !" << endl;
}

void Avion::setLargeur(double l){
    largeur = l;
}

void Avion::setTaille(double t){
    taille = t;
}

Bateau::Bateau(char const Marque[]) : Vehicule(){
    strcpy(marque, Marque);
}

void Bateau::QuestceQueCest(){
    cout << "Je suis un bateau !" << endl;
}

void Bateau::setLargeur(double l){
    largeur = l;
}

void Bateau::setTaille(double t){
    taille = t;
}