#include <iostream>
#include "vecteur3.h"
#include "calcul_vent_seq.h"

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
    Calcul_vent_seq a(50, 0.1, 0.1, 0.1, taille, boule);
    a.calcul_vent();
    return 0;
}

