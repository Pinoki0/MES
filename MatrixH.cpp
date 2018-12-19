#include "MatrixH.h"
#include <cmath>
using namespace std;
#include "InputData.h"
#include <iostream>



MatrixH::MatrixH()
{
}

MatrixH::~MatrixH()
{
}

float** MatrixH::generateMatrixH(float** jakobianPrzezDet,float** jakobian,float* detJakobian ,float** ksztaltWzgledemEta, float **ksztaltWzgledemKsi, int size)
{


    float**dN_po_dX = new float*[size];
    for(int i = 0; i < size; i ++)
    {
        dN_po_dX[i] = new float[size];

    }

    dN_po_dX[0][0]=jakobianPrzezDet[0][0]*ksztaltWzgledemKsi[0][0]+jakobianPrzezDet[0][1]*ksztaltWzgledemEta[0][0];
    dN_po_dX[0][1]=jakobianPrzezDet[0][0]*ksztaltWzgledemKsi[0][1]+jakobianPrzezDet[0][1]*ksztaltWzgledemEta[0][1];
    dN_po_dX[0][2]=jakobianPrzezDet[0][0]*ksztaltWzgledemKsi[0][2]+jakobianPrzezDet[0][1]*ksztaltWzgledemEta[0][2];
    dN_po_dX[0][3]=jakobianPrzezDet[0][0]*ksztaltWzgledemKsi[0][3]+jakobianPrzezDet[0][1]*ksztaltWzgledemEta[0][3];

    dN_po_dX[1][0]=jakobianPrzezDet[1][0]*ksztaltWzgledemKsi[1][0]+jakobianPrzezDet[1][1]*ksztaltWzgledemEta[1][0];
    dN_po_dX[1][1]=jakobianPrzezDet[1][0]*ksztaltWzgledemKsi[1][1]+jakobianPrzezDet[1][1]*ksztaltWzgledemEta[1][1];
    dN_po_dX[1][2]=jakobianPrzezDet[1][0]*ksztaltWzgledemKsi[1][2]+jakobianPrzezDet[1][1]*ksztaltWzgledemEta[1][2];
    dN_po_dX[1][3]=jakobianPrzezDet[1][0]*ksztaltWzgledemKsi[1][3]+jakobianPrzezDet[1][1]*ksztaltWzgledemEta[1][3];

    dN_po_dX[2][0]=jakobianPrzezDet[2][0]*ksztaltWzgledemKsi[2][0]+jakobianPrzezDet[2][1]*ksztaltWzgledemEta[2][0];
    dN_po_dX[2][1]=jakobianPrzezDet[2][0]*ksztaltWzgledemKsi[2][1]+jakobianPrzezDet[2][1]*ksztaltWzgledemEta[2][1];
    dN_po_dX[2][2]=jakobianPrzezDet[2][0]*ksztaltWzgledemKsi[2][2]+jakobianPrzezDet[2][1]*ksztaltWzgledemEta[2][2];
    dN_po_dX[2][3]=jakobianPrzezDet[2][0]*ksztaltWzgledemKsi[2][3]+jakobianPrzezDet[2][1]*ksztaltWzgledemEta[2][3];

    dN_po_dX[3][0]=jakobianPrzezDet[3][0]*ksztaltWzgledemKsi[3][0]+jakobianPrzezDet[3][1]*ksztaltWzgledemEta[3][0];
    dN_po_dX[3][1]=jakobianPrzezDet[3][0]*ksztaltWzgledemKsi[3][1]+jakobianPrzezDet[3][1]*ksztaltWzgledemEta[3][1];
    dN_po_dX[3][2]=jakobianPrzezDet[3][0]*ksztaltWzgledemKsi[3][2]+jakobianPrzezDet[3][1]*ksztaltWzgledemEta[3][2];
    dN_po_dX[3][3]=jakobianPrzezDet[3][0]*ksztaltWzgledemKsi[3][3]+jakobianPrzezDet[3][1]*ksztaltWzgledemEta[3][3];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<dN_po_dX[i][j]<<" ";
        }
        cout<<endl<<endl;
    }


    float**dN_po_dY = new float*[size];
    for(int i = 0; i < size; i ++)
    {
        dN_po_dY[i] = new float[size];

    }

    dN_po_dY[0][0]=jakobianPrzezDet[0][2]*ksztaltWzgledemKsi[0][0]+jakobianPrzezDet[0][3]*ksztaltWzgledemEta[0][0];
    dN_po_dY[0][1]=jakobianPrzezDet[0][2]*ksztaltWzgledemKsi[0][1]+jakobianPrzezDet[0][3]*ksztaltWzgledemEta[0][1];
    dN_po_dY[0][2]=jakobianPrzezDet[0][2]*ksztaltWzgledemKsi[0][2]+jakobianPrzezDet[0][3]*ksztaltWzgledemEta[0][2];
    dN_po_dY[0][3]=jakobianPrzezDet[0][2]*ksztaltWzgledemKsi[0][3]+jakobianPrzezDet[0][3]*ksztaltWzgledemEta[0][3];

    dN_po_dY[1][0]=jakobianPrzezDet[1][2]*ksztaltWzgledemKsi[1][0]+jakobianPrzezDet[1][3]*ksztaltWzgledemEta[1][0];
    dN_po_dY[1][1]=jakobianPrzezDet[1][2]*ksztaltWzgledemKsi[1][1]+jakobianPrzezDet[1][3]*ksztaltWzgledemEta[1][1];
    dN_po_dY[1][2]=jakobianPrzezDet[1][2]*ksztaltWzgledemKsi[1][2]+jakobianPrzezDet[1][3]*ksztaltWzgledemEta[1][2];
    dN_po_dY[1][3]=jakobianPrzezDet[1][2]*ksztaltWzgledemKsi[1][3]+jakobianPrzezDet[1][3]*ksztaltWzgledemEta[1][3];

    dN_po_dY[2][0]=jakobianPrzezDet[2][2]*ksztaltWzgledemKsi[2][0]+jakobianPrzezDet[2][3]*ksztaltWzgledemEta[2][0];
    dN_po_dY[2][1]=jakobianPrzezDet[2][2]*ksztaltWzgledemKsi[2][1]+jakobianPrzezDet[2][3]*ksztaltWzgledemEta[2][1];
    dN_po_dY[2][2]=jakobianPrzezDet[2][2]*ksztaltWzgledemKsi[2][2]+jakobianPrzezDet[2][3]*ksztaltWzgledemEta[2][2];
    dN_po_dY[2][3]=jakobianPrzezDet[2][2]*ksztaltWzgledemKsi[2][3]+jakobianPrzezDet[2][3]*ksztaltWzgledemEta[2][3];

    dN_po_dY[3][0]=jakobianPrzezDet[3][2]*ksztaltWzgledemKsi[3][0]+jakobianPrzezDet[3][3]*ksztaltWzgledemEta[3][0];
    dN_po_dY[3][1]=jakobianPrzezDet[3][2]*ksztaltWzgledemKsi[3][1]+jakobianPrzezDet[3][3]*ksztaltWzgledemEta[3][1];
    dN_po_dY[3][2]=jakobianPrzezDet[3][2]*ksztaltWzgledemKsi[3][2]+jakobianPrzezDet[3][3]*ksztaltWzgledemEta[3][2];
    dN_po_dY[3][3]=jakobianPrzezDet[3][2]*ksztaltWzgledemKsi[3][3]+jakobianPrzezDet[3][3]*ksztaltWzgledemEta[3][3];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<dN_po_dY[i][j]<<" ";
        }
        cout<<endl<<endl;
    }



    float ***mnozenieMacierzyXY = new float**[size*2];
    for(int i = 0; i < size*2; i ++)
    {
        mnozenieMacierzyXY[i]=new float *[size];
        for (int j=0; j<size; j++)
        {
            mnozenieMacierzyXY[i][j]=new float [size];
        }

    }
    int k=0;
    for (int i=0; i<size*2; i++)
    {
        for (int j=0; j<size; j++)
        {
            for (int b=0; b<size; b++)
            {
                if(i<size)
                    mnozenieMacierzyXY[i][j][b]=dN_po_dX[i][b]*dN_po_dX[i][j];
                else
                    mnozenieMacierzyXY[i][j][b]=dN_po_dY[k][b]*dN_po_dY[k][j];
            }
        }
        if(i>=size)
            k++;
    }


    float ***mnozenieMacierzyXYDet = new float**[size*2];
    for(int i = 0; i < size*2; i ++)
    {
        mnozenieMacierzyXYDet[i]=new float *[size];
        for (int j=0; j<size; j++)
        {
            mnozenieMacierzyXYDet[i][j]=new float [size];
        }

    }
    cout<<endl<<jakobian[0][0]<<endl;
    cout<<"XY * Det"<<endl<<endl;
    int x = 0;
    for (int i=0; i<size*2; i++)
    {
        for (int j=0; j<size; j++)
        {
            for (int b=0; b<size; b++)
            {
                int mnoznik = i%4;
                float value = detJakobian[mnoznik];
                mnozenieMacierzyXYDet[i][j][b] = mnozenieMacierzyXY[i][j][b]*value;

            }
        }
    }


    for (int i=0; i<size*2; i++)
    {
        for (int j=0; j<size; j++)
        {
            for (int b=0; b<size; b++)
            {

                cout<<mnozenieMacierzyXYDet[i][j][b]<<"  ";

            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    cout<<endl<<endl;
    float ***mnozenieMacierzyXYDetK = new float**[size];
    for(int i = 0; i < size; i ++)
    {
        mnozenieMacierzyXYDetK[i]=new float *[size];
        for (int j=0; j<size; j++)
        {
            mnozenieMacierzyXYDetK[i][j]=new float [size];
        }

    }
    cout<<"XY DET K"<<endl<<endl;
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            for (int b=0; b<size; b++)
            {
                int mnoznik = i%4;
                mnozenieMacierzyXYDetK[i][j][b] = (mnozenieMacierzyXYDet[i][j][b]+mnozenieMacierzyXYDet[i+size][j][b])*30;

            }
        }
    }

    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            for (int b=0; b<size; b++)
            {

                cout<<mnozenieMacierzyXYDetK[i][j][b]<<" ";

            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    cout<<"MACIERZ H"<<endl;
    float **matrixH = new float*[size];
    for(int i = 0; i < size; i++)
        matrixH[i] = new float[size];
    for(int i =0; i < size;i++)
    {
        for(int j = 0;j< size;j++)
        {
            for(int l = 0; l < size; l++)
            {
                matrixH[i][j] += mnozenieMacierzyXYDetK[l][i][j];
            }
        }
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixH[i][j]<<" ";
        }
        cout<<endl;
    }
    return matrixH;

}

    float** MatrixH::generateGlobalMatrixH(Element** Elements)
    {

    int verticalNodeNumber = InputData::getVerticalNodeNumber()-1;
	int horizontalNodeNumber = InputData::getHorizontalNodeNumber()-1;

    matrixHGlobal = new float*[16];
    for(int i = 0; i < 16; i++)
        matrixHGlobal[i] = new float[16];

    int *nodes;


        for (int i = 0; i <verticalNodeNumber*horizontalNodeNumber; i++)
        {
            nodes = Elements[i]->getNodesId();
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                matrixHGlobal[nodes[j]-1][nodes[k]-1]+=matrixH[j][k];
            }

        }

        for(int i=0;i<16;i++)
        {
            for(int j=0;j<16;j++)
                cout<<matrixHGlobal[i][j]<<" | ";
            cout<<endl;
        }


        return matrixHGlobal;
    }
