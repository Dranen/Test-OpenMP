#include <iostream>
#include "vecteur3.h"
#include "calcul_vent_seq.h"
#include "calcul_vent_openmp.h"

using namespace std;

bool boule(vecteur3 crd)
{
    vecteur3 centre(10, 10, 10);
    double rayon = 5;
    if(norme(crd-centre)<rayon)
    {
        return true;
    }
    return false;
}

int main()
{
    double taille[3]={20,20,20};
    /*Calcul_vent_OpenMP a(50, 0.1, 0.1, 1, taille, boule);
    a.calcul_vent();
    Calcul_vent_seq b(50, 0.1, 0.1, 1, taille, boule);
    b.calcul_vent();*/

    Calcul_vent_OpenMP *a;
    Calcul_vent_seq *b;

    cout<<"Taille 2"<<endl<<endl;
    cerr<<"Taille 2"<<endl<<endl;
    a = new Calcul_vent_OpenMP(50, 0.1, 0.1, 2, taille, boule);
    a->calcul_vent();
    delete a;
    b = new Calcul_vent_seq(50, 0.1, 0.1, 2, taille, boule);
    b->calcul_vent();
    delete b;

    cout<<endl<<endl<<"Taille 1.5"<<endl<<endl;
    cerr<<endl<<endl<<"Taille 1.5"<<endl<<endl;
    a = new Calcul_vent_OpenMP(50, 0.1, 0.1, 1.5, taille, boule);
    a->calcul_vent();
    delete a;
    b = new Calcul_vent_seq(50, 0.1, 0.1, 1.5, taille, boule);
    b->calcul_vent();
    delete b;

    cout<<endl<<endl<<"Taille 1"<<endl<<endl;
    cerr<<endl<<endl<<"Taille 1"<<endl<<endl;
    a = new Calcul_vent_OpenMP(50, 0.1, 0.1, 1, taille, boule);
    a->calcul_vent();
    delete a;
    b = new Calcul_vent_seq(50, 0.1, 0.1, 1, taille, boule);
    b->calcul_vent();
    delete b;

    cout<<endl<<endl<<"Taille 0.5"<<endl<<endl;
    cerr<<endl<<endl<<"Taille 0.5"<<endl<<endl;
    a = new Calcul_vent_OpenMP(50, 0.1, 0.1, 0.5, taille, boule);
    a->calcul_vent();
    delete a;
    b = new Calcul_vent_seq(50, 0.1, 0.1, 0.5, taille, boule);
    b->calcul_vent();
    delete b;

    cout<<endl<<endl<<"Taille 0.1"<<endl<<endl;
    cerr<<endl<<endl<<"Taille 0.1"<<endl<<endl;
    a = new Calcul_vent_OpenMP(50, 0.1, 0.1, 0.1, taille, boule);
    a->calcul_vent();
    delete a;
    b = new Calcul_vent_seq(50, 0.1, 0.1, 0.1, taille, boule);
    b->calcul_vent();
    delete b;

    return 0;
}

