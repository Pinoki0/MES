#include <iostream>
#include "InputData.h"
#include "Element.h"
#include <cmath>
#include "Grid.h"
#include "MatrixH.h"
#include "Jakobian2D.h"
#include "MatrixHbc2.h"
#include "MatrixC.h"
using namespace std;

int main()
{
    InputData input;
    Grid *grid=new Grid();
    //grid->printGrid();
    Jakobian2D jakobian2D;
     MatrixH matrixH;
     MatrixC matrixC;
     MatrixHbc2 matrixHbc2;
    grid->printGrid();
  int size = 4;
    float *ksi = new float[size];
  //  ksi = ;
    float *eta = new float[size];
    ksi[0] =-1/sqrt(3);
    ksi[1]=1/sqrt(3);
    ksi[2]=1/sqrt(3);
    ksi[3]=-1/sqrt(3);
    eta[0]=-1/sqrt(3);
    eta[1]=-1/sqrt(3);
    eta[2]=1/sqrt(3);
    eta[3]=1/sqrt(3);
    float**pkt = new float*[size];//[2]{{0,0},{0.025,0},{0.025,0.025},{0,0.025}};
    for(int i = 0; i < size; i ++)
    {
        pkt[i] = new float[2];

    }
    pkt[0][0] =0;
    pkt[0][1]=0;
    pkt[1][0]=0.025;
    pkt[1][1]=0;
    pkt[2][0]=0.025;
    pkt[2][1]=0.025;
    pkt[3][0]=0;
    pkt[3][1]=0.025;

    jakobian2D.generateJakobian2D(ksi,eta,pkt,size);
    matrixH.generateMatrixH(jakobian2D.getJakobianPrzezDet(),jakobian2D.getJakobian(),jakobian2D.getDetJakobian() ,jakobian2D.getKsztaltWzgledemEta(),jakobian2D.getKsztaltWzgledemKsi(), size);
    matrixC.generateMatrixC(jakobian2D.getJakobianPrzezDet(),jakobian2D.getJakobian(),jakobian2D.getDetJakobian() ,jakobian2D.getN() , size);
    matrixHbc2.generateMatrixHbc2(size,pkt);
    matrixC.generateGlobalMatrixC(grid->getElements());
   // matrixH.generateGlobalMatrixH(grid->getElements());
    return 0;
}


