#include "calcul_vent_seq.h"
#include <iostream>
#include <chrono>
#include <iomanip>

Calcul_vent_seq::Calcul_vent_seq(double v_inf, double erreur, double epsilon, double lambda, double taille[3], bool(*q_fixe)(vecteur3 crd))
{
    this->epsilon = epsilon;
    this->lambda = lambda;
    this->erreur = erreur;
    this->taille[0] = static_cast<unsigned long long int>(taille[0]/lambda)+1;
    this->taille[1] = static_cast<unsigned long long int>(taille[1]/lambda)+1;
    this->taille[2] = static_cast<unsigned long long int>(taille[2]/lambda)+1;

    potentiel1 = new std::vector<std::vector<std::vector<vecteur3>>>;
    potentiel2 = new std::vector<std::vector<std::vector<vecteur3>>>;

    potentiel1->resize((2+this->taille[0]));
    potentiel2->resize((2+this->taille[0]));
    fixe.resize(2+this->taille[0]);
    vent.resize(this->taille[0]);

    for(unsigned long long int i = 0; i < 1+this->taille[0]; i++)
    {
        (*potentiel1)[i].resize((2+this->taille[1]));
        (*potentiel2)[i].resize((2+this->taille[1]));
        fixe[i].resize(2+this->taille[1]);
        if(i < (this->taille[0])-1)
        {
            vent[i].resize(this->taille[1]);
        }
    }

    for(unsigned long long int i = 0; i < 1+this->taille[0]; i++)
    {
        for(unsigned long long int j = 0; j < 1+this->taille[0]; j++)
        {
            (*potentiel1)[i][j].resize((2+this->taille[2]));
            (*potentiel2)[i][j].resize((2+this->taille[2]));
            fixe[i][j].resize(2+this->taille[2]);
            if(i < (this->taille[0])-1 && j < (this->taille[1])-1)
            {
                vent[i][j].resize(this->taille[2]);
            }
        }
    }

    for(unsigned long long int i = 0; i < 1+this->taille[0]; i++)
    {
        for(unsigned long long int j = 0; j < 1+this->taille[1]; j++)
        {
            for(unsigned long long int k = 0; k < 1+this->taille[2]; k++)
            {
                vecteur3 pos(lambda*static_cast<double>(i), lambda*static_cast<double>(j), lambda*static_cast<double>(k));
                fixe[i][j][k] = q_fixe(pos);

                if(fixe[i][j][k])
                {
                    (*potentiel1)[i][j][k] = vecteur3(0,-lambda*static_cast<double>(k)*(v_inf/2.0),lambda*static_cast<double>(j)*(v_inf/2.0));
                }
                else
                {
                    (*potentiel1)[i][j][k] = vecteur3(0,0,0);
                }

                if(i == 0 || i == 1+this->taille[0])
                {
                    fixe[i][j][k] = true;
                }
                else if(j == 0 || j == 1+this->taille[0])
                {
                    fixe[i][j][k] = true;
                }
                else if(k == 0 || k == 1+this->taille[0])
                {
                    fixe[i][j][k] = true;
                }
            }
        }
    }

}

void Calcul_vent_seq::calcul_vent()
{
    bool fin = true;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    double ecart_maximal;

    std::cout << "Debut calul vent sequentiel" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    do
    {
        ecart_maximal = 0;
        fin = true;
        for(unsigned long long int i = 1; i < this->taille[0]; i++)
        {
            for(unsigned long long int j = 1; j < this->taille[1]; j++)
            {
                for(unsigned long long int k = 1; k < this->taille[2]; k++)
                {
                    (*potentiel2)[i][j][k] = (*potentiel1)[i][j][k];
                    if(!fixe[i][j][k])
                    {
                        vecteur3 correction = epsilon*(-6.0*(*potentiel1)[i][j][k]+(*potentiel1)[i+1][j][k]+(*potentiel1)[i][j+1][k]+(*potentiel1)[i][j][k+1]+(*potentiel1)[i-1][j][k]+(*potentiel1)[i][j-1][k]+(*potentiel1)[i][j][k-1]);
                        (*potentiel2)[i][j][k] += correction;
                        if(norme(correction) > erreur)
                        {
                            fin = false;
                            ecart_maximal = std::max(norme(correction), ecart_maximal);
                        }
                    }
                }
            }
        }
        std::cerr << std::setprecision(16) <<ecart_maximal<<std::endl;
        std::swap(potentiel1, potentiel2);
    }while(!fin);
    for(unsigned long long int i = 1; i < this->taille[0]; i++)
    {
        for(unsigned long long int j = 1; j < this->taille[1]; j++)
        {
            for(unsigned long long int k = 1; k < this->taille[2]; k++)
            {
                vent[i-1][j-1][k-1] = (1.0/(2.0*lambda))*vecteur3((*potentiel1)[i][j+1][k][2]-(*potentiel1)[i][j-1][k][2]-(*potentiel1)[i][j][k+1][1]+(*potentiel1)[i][j][k-1][1], -(*potentiel1)[i+1][j][k][2]+(*potentiel1)[i-1][j][k][2], (*potentiel1)[i+1][j][k][1]-(*potentiel1)[i-1][j][k][1]);
            }
        }
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> temps=end-start;
    std::cout << "Fin calul vent sequentiel" << std::endl;
    std::cout << "Temps calul vent sequentiel : " << std::setprecision(16) << temps.count() << std::endl;
}
