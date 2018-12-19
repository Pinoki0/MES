#include "Jakobian2D.h"
#include <cmath>
using namespace std;
#include <iostream>

float N1(float ksi, float eta)
{
    return 0.25*(1-ksi)*(1-eta);
}
float N2(float ksi, float eta)
{
    return 0.25*(1+ksi)*(1-eta);
}
float N3(float ksi, float eta)
{
    return 0.25*(1+ksi)*(1+eta);
}
float N4(float ksi, float eta)
{
    return 0.25*(1-ksi)*(1+eta);
}
float calculateX(float *N, float**x, int size)
{
    float suma = 0;
    for(int i = 0; i < size; i++)
    {
        suma+=N[i]*x[i][0];
    }
    return suma;
}
float calculateY(float *N, float**y, int size)
{
    float suma = 0;
    for(int i = 0; i < size; i++)
        suma+=N[i]*y[i][1];
    return suma;
}
float pochodnaFunkcjiKsztaltuWzgledemKsi1(float eta)
{
    return -0.25*(1-eta);
}
float pochodnaFunkcjiKsztaltuWzgledemKsi2(float eta)
{
    return 0.25*(1-eta);
}
float pochodnaFunkcjiKsztaltuWzgledemKsi3(float eta)
{
    return 0.25*(1+eta);
}
float pochodnaFunkcjiKsztaltuWzgledemKsi4(float eta)
{
    return -0.25*(1+eta);
}
float pochodnaFunkcjiKsztaltuWzgledemEta1(float ksi)
{
    return -0.25*(1-ksi);
}
float pochodnaFunkcjiKsztaltuWzgledemEta2(float ksi)
{
    return -0.25*(1+ksi);
}
float pochodnaFunkcjiKsztaltuWzgledemEta3(float ksi)
{
    return 0.25*(1+ksi);
}
float pochodnaFunkcjiKsztaltuWzgledemEta4(float ksi)
{
    return 0.25*(1-ksi);
}
float calculateJakobianX(float *a, float**x)
{
    float suma = 0;
    for(int i = 0 ; i < 4; i++)
    {
        suma+=a[i]*x[i][0];
    }
    return suma;
}
float calculateJakobianY(float *a, float**x)
{
    float suma = 0;
    for(int i = 0 ; i < 4; i++)
    {
        suma+=a[i]*x[i][1];
    }
    return suma;
}
float detJ(float *a)
{
    return a[0]*a[3]-a[1]*a[2];
}

Jakobian2D::Jakobian2D()
{
    //ctor
}

Jakobian2D::~Jakobian2D()
{
    //dtor
}

float* Jakobian2D::getDetJakobian()
{
    return detJakobian;
}

float** Jakobian2D::getJakobian()
{
    return jakobian;
}

float** Jakobian2D::getJakobianPrzezDet()
{
    return jakobianPrzezDet;
}

float** Jakobian2D::getKsztaltWzgledemEta()
{
    return ksztaltWzgledemEta;
}

float** Jakobian2D::getKsztaltWzgledemKsi()
{
    return ksztaltWzgledemKsi;
}

float** Jakobian2D::getN()
{
    return N;
}




void Jakobian2D::generateJakobian2D(float *ksi, float *eta, float **pkt, int size)
{
    N = new float*[size]();
    for(int i = 0; i < size; i++)
        N[i]= new float[size]();
    for(int i = 0; i < size; i++)
    {
        N[i][0] = N1(ksi[i],eta[i]);
        N[i][1] = N2(ksi[i],eta[i]);
        N[i][2] = N3(ksi[i],eta[i]);
        N[i][3] = N4(ksi[i],eta[i]);
    }
    for(int i = 0; i < size; i++)
    {
        cout<<ksi[i]<<" "<<eta[i]<<" "<<N[i][0]<<" "<<N[i][1]<<" "<<N[i][2]<<" "<<N[i][3]<<endl;
    }
    float**pktEnd = new float*[size];
    for(int i = 0; i < size; i ++)
    {
        pktEnd[i] = new float[2];

    }
    for(int i = 0; i < size; i++)
    {
        pktEnd[i][0] = calculateX(N[i],pkt,size);
        pktEnd[i][1] = calculateY(N[i],pkt,size);
    }
    for(int i = 0; i < size; i++)
    {
        cout<<"X:"<<pktEnd[i][0]<<" Y:"<<pktEnd[i][1]<<endl;
    }
    ksztaltWzgledemKsi = new float*[size];
    ksztaltWzgledemEta = new float*[size];
    for(int i = 0; i < size; i ++)
    {
        ksztaltWzgledemKsi[i] = new float[size];
        ksztaltWzgledemEta[i] = new float[size];
    }
    for(int i = 0; i < size; i++)
    {
        ksztaltWzgledemEta[i][0] = pochodnaFunkcjiKsztaltuWzgledemEta1(ksi[i]);
        ksztaltWzgledemEta[i][1] = pochodnaFunkcjiKsztaltuWzgledemEta2(ksi[i]);
        ksztaltWzgledemEta[i][2] = pochodnaFunkcjiKsztaltuWzgledemEta3(ksi[i]);
        ksztaltWzgledemEta[i][3] = pochodnaFunkcjiKsztaltuWzgledemEta4(ksi[i]);

        ksztaltWzgledemKsi[i][0] = pochodnaFunkcjiKsztaltuWzgledemKsi1(eta[i]);
        ksztaltWzgledemKsi[i][1] = pochodnaFunkcjiKsztaltuWzgledemKsi2(eta[i]);
        ksztaltWzgledemKsi[i][2] = pochodnaFunkcjiKsztaltuWzgledemKsi3(eta[i]);
        ksztaltWzgledemKsi[i][3] = pochodnaFunkcjiKsztaltuWzgledemKsi4(eta[i]);
    }
    for( int i = 0; i < size; i++)
    {
        for(int j =0 ; j < size; j++)
            cout<<ksztaltWzgledemEta[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;
    for( int i = 0; i < size; i++)
    {
        for(int j =0 ; j < size; j++)
            cout<<ksztaltWzgledemKsi[i][j]<<" ";
        cout<<endl;
    }

    jakobian = new float*[size];
    for(int i = 0; i < size; i ++)
    {
        jakobian[i] = new float[size];
    }

    jakobian[0][0] = calculateJakobianX(ksztaltWzgledemKsi[0],pkt);
    jakobian[0][1] = calculateJakobianY(ksztaltWzgledemKsi[1],pkt);
    jakobian[0][2] = calculateJakobianX(ksztaltWzgledemEta[2],pkt);
    jakobian[0][3] = calculateJakobianY(ksztaltWzgledemEta[3],pkt);

    jakobian[1][0] = calculateJakobianX(ksztaltWzgledemKsi[0],pkt);
    jakobian[1][1] = calculateJakobianY(ksztaltWzgledemKsi[1],pkt);
    jakobian[1][2] = calculateJakobianX(ksztaltWzgledemEta[2],pkt);
    jakobian[1][3] = calculateJakobianY(ksztaltWzgledemEta[3],pkt);

    jakobian[2][0] = calculateJakobianX(ksztaltWzgledemKsi[0],pkt);
    jakobian[2][1] = calculateJakobianY(ksztaltWzgledemKsi[1],pkt);
    jakobian[2][2] = calculateJakobianX(ksztaltWzgledemEta[2],pkt);
    jakobian[2][3] = calculateJakobianY(ksztaltWzgledemEta[3],pkt);

    jakobian[3][0] = calculateJakobianX(ksztaltWzgledemKsi[0],pkt);
    jakobian[3][1] = calculateJakobianY(ksztaltWzgledemKsi[1],pkt);
    jakobian[3][2] = calculateJakobianX(ksztaltWzgledemEta[2],pkt);
    jakobian[3][3] = calculateJakobianY(ksztaltWzgledemEta[3],pkt);

    detJakobian = new float[size];
    detJakobian[0] = detJ(jakobian[0]);
    detJakobian[1] = detJ(jakobian[1]);
    detJakobian[2] = detJ(jakobian[2]);
    detJakobian[3] = detJ(jakobian[3]);
    for(int i = 0; i<size; i++)
        cout<<detJakobian[i]<<" ";

    cout<<endl<<endl;

    jakobianPrzezDet = new float*[size];
    for(int i = 0; i < size; i ++)
    {
        jakobianPrzezDet[i] = new float[size];

    }


    jakobianPrzezDet[0][0] = jakobian[0][3]/detJakobian[0];
    jakobianPrzezDet[0][1] = -jakobian[0][1]/detJakobian[0];
    jakobianPrzezDet[0][2] = jakobian[0][2]/detJakobian[0];
    jakobianPrzezDet[0][3] = jakobian[0][0]/detJakobian[0];

    jakobianPrzezDet[1][0] = jakobian[1][3]/detJakobian[1];
    jakobianPrzezDet[1][1] = -jakobian[1][1]/detJakobian[1];
    jakobianPrzezDet[1][2] = jakobian[1][2]/detJakobian[1];
    jakobianPrzezDet[1][3] = jakobian[1][0]/detJakobian[1];

    jakobianPrzezDet[2][0] = jakobian[2][3]/detJakobian[2];
    jakobianPrzezDet[2][1] = -jakobian[2][1]/detJakobian[2];
    jakobianPrzezDet[2][2] = jakobian[2][2]/detJakobian[2];
    jakobianPrzezDet[2][3] = jakobian[2][0]/detJakobian[2];

    jakobianPrzezDet[3][0] = jakobian[3][3]/detJakobian[3];
    jakobianPrzezDet[3][1] = -jakobian[3][1]/detJakobian[3];
    jakobianPrzezDet[3][2] = jakobian[3][2]/detJakobian[3];
    jakobianPrzezDet[3][3] = jakobian[3][0]/detJakobian[3];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<jakobianPrzezDet[i][j]<<" ";
        }
        cout<<endl<<endl;
    }

}
