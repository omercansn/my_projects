#ifndef VEHICULE_H
#define VEHICULE_H


#include <iostream>
#include <string>
using namespace std;

class Vehicule{
    protected:
        char marque[32];
        double taille, largeur;
    public:
        virtual void QuestceQueCest() = 0;
        virtual void setLargeur(double) = 0;
        double getLargeur();
        virtual void setTaille(double) = 0;
        double getTaille();
        char* const getMarque();
};

class Voiture : public Vehicule{
    public:
        Voiture (char const[]);
        void QuestceQueCest();
        void setTaille(double);
        void setLargeur(double);
};

class Avion : public Vehicule{
    public:
        Avion(char const[]);
        void QuestceQueCest();
        void setTaille(double);
        void setLargeur(double);
};

class Bateau : public Vehicule{
    public:
        Bateau(char const[]);
        void QuestceQueCest();
        void setTaille(double);
        void setLargeur(double);
};

#endif