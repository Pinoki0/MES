#ifndef MATRIXH_H
#define MATRIXH_H
#include "Element.h"



class MatrixH
{
    float** matrixH;
    float** matrixHGlobal;
    public:
        MatrixH();
        virtual ~MatrixH();
        float** generateMatrixH(float** jakobianPrzezDet,float** jakobian,float* detJakobian ,float** ksztaltWzgledemEta, float **ksztaltWzgledemKsi, int size);
        float** generateGlobalMatrixH(Element** Elements);
};

#endif // LICZ_H
