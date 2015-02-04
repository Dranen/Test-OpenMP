#ifndef CALCUL_VENT_OPENMP_H
#define CALCUL_VENT_OPENMP_H

#include "vecteur3.h"

class Calcul_vent_OpenMP
{
public:
    Calcul_vent_OpenMP(double v_inf, double erreur, double epsilon, double lambda, double taille[3], bool(*q_fixe)(vecteur3 crd));
    ~Calcul_vent_OpenMP()
    {
        delete potentiel1;
        delete potentiel2;
    }
    void calcul_vent();

protected :
    double epsilon;
    double lambda;
    double erreur;
    unsigned long long int taille[3];
    std::vector<std::vector<std::vector<vecteur3>>> *potentiel1;
    std::vector<std::vector<std::vector<vecteur3>>> *potentiel2;
    std::vector<std::vector<std::vector<bool>>> fixe;
    std::vector<std::vector<std::vector<vecteur3>>> vent;
};

#endif // CALCUL_VENT_OPENMP_H
