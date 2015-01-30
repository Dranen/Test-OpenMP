#ifndef VECTEUR3_H
#define VECTEUR3_H

#include <vector>

class vecteur3
{
public:
    vecteur3();
    vecteur3(double n_x, double n_y, double n_z);
    vecteur3(vecteur3 const& A);
    double& operator[](std::size_t const& i);
    double const& operator[](std::size_t const& i) const;
    vecteur3& operator+=(vecteur3 const& A);
    vecteur3& operator-=(vecteur3 const& A);
    vecteur3& operator*=(double const& A);
    vecteur3& operator=(vecteur3 const& A);

protected :
    double crd[3];
};

vecteur3& operator+(vecteur3 const& A, vecteur3 const& B);
vecteur3& operator-(vecteur3 const& A, vecteur3 const& B);
vecteur3& operator*(vecteur3 const& A, double const& B);
vecteur3& operator*(double const& A, vecteur3 const& B);
double norme(vecteur3 const& A);

#endif // VECTEUR3_H
