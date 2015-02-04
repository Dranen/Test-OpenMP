#include "vecteur3.h"
#include <cmath>

vecteur3::vecteur3()
{
    crd[0] = 0;
    crd[1] = 0;
    crd[2] = 0;
}

vecteur3::vecteur3(double n_x, double n_y, double n_z)
{
    crd[0] = n_x;
    crd[1] = n_y;
    crd[2] = n_z;
}

vecteur3::vecteur3(vecteur3 const& A)
{
    crd[0] = A.crd[0];
    crd[1] = A.crd[1];
    crd[2] = A.crd[2];
}

double& vecteur3::operator[](std::size_t const& i)
{
    return crd[i];
}

double const& vecteur3::operator[](std::size_t const& i) const
{
    return crd[i];
}

vecteur3& vecteur3::operator+=(vecteur3 const& A)
{
    crd[0] += A.crd[0];
    crd[1] += A.crd[1];
    crd[2] += A.crd[2];
    return *this;
}

vecteur3& vecteur3::operator-=(vecteur3 const& A)
{
    crd[0] -= A.crd[0];
    crd[1] -= A.crd[1];
    crd[2] -= A.crd[2];
    return *this;
}

vecteur3& vecteur3::operator*=(double const& A)
{
    crd[0] *= A;
    crd[1] *= A;
    crd[2] *= A;
    return *this;
}

vecteur3& vecteur3::operator=(vecteur3 const& A)
{
    crd[0] = A.crd[0];
    crd[1] = A.crd[1];
    crd[2] = A.crd[2];
    return *this;
}

vecteur3 operator+(vecteur3 const& A, vecteur3 const& B)
{
    vecteur3 C(A);
    C+=B;
    return C;
}

vecteur3 operator-(vecteur3 const& A, vecteur3 const& B)
{
    vecteur3 C(A);
    C-=B;
    return C;
}

vecteur3 operator*(vecteur3 const& A, double const& B)
{
    vecteur3 C(A);
    C*=B;
    return C;
}

vecteur3 operator*(double const& B, vecteur3 const& A)
{
    vecteur3 C(A);
    C*=B;
    return C;
}

double norme(vecteur3 const& A)
{
    return std::sqrt(A[0]*A[0]+A[1]*A[1]+A[2]*A[2]);
}
