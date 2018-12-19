#ifndef MATRIXH_C
#define MATRIXH_C
#include "Element.h"



class MatrixC
{
    float **matrixC;
    float **matrixCGlobal;

    public:
        MatrixC();
        virtual ~MatrixC();
        float** generateMatrixC(float** jakobianPrzezDet,float** jakobian,float* detJakobian ,float **N , int size);
        float** generateGlobalMatrixC(Element** Elements);

};

#endif // LICZ_H
