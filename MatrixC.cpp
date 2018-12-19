#include "MatrixC.h"
#include <cmath>
#include "InputData.h"
using namespace std;
#include <iostream>
MatrixC::MatrixC()
{
    //ctor
}

MatrixC::~MatrixC()
{
    //dtor
}
   float** MatrixC::generateMatrixC(float** jakobianPrzezDet,float** jakobian,float* detJakobian,float **N , int size)
   {

    int c=700;
    int ro=7800;


    float ** matrixC1pc = new float*[size];
    for(int i = 0; i < size; i++)
        matrixC1pc[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixC1pc[i][j]=N[0][i]*N[0][j]*detJakobian[0]*c*ro;
        }

    }
    cout<<" MatrixC 1pc:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixC1pc[i][j]<<" ";
        }
        cout<<endl;
    }

        float ** matrixC2pc = new float*[size];
    for(int i = 0; i < size; i++)
        matrixC2pc[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixC2pc[i][j]=N[1][i]*N[1][j]*detJakobian[1]*c*ro;
        }

    }
    cout<<" MatrixC 2pc:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixC2pc[i][j]<<" ";
        }
        cout<<endl;
    }


            float ** matrixC3pc = new float*[size];
    for(int i = 0; i < size; i++)
        matrixC3pc[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixC3pc[i][j]=N[2][i]*N[2][j]*detJakobian[2]*c*ro;
        }

    }
    cout<<" MatrixC 3pc:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixC3pc[i][j]<<" ";
        }
        cout<<endl;
    }


            float ** matrixC4pc = new float*[size];
    for(int i = 0; i < size; i++)
        matrixC4pc[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixC4pc[i][j]=N[3][i]*N[3][j]*detJakobian[3]*c*ro;
        }

    }
    cout<<" MatrixC 4pc:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixC4pc[i][j]<<" ";
        }
        cout<<endl;
    }


    matrixC = new float*[size];
    for(int i = 0; i < size; i++)
        matrixC[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixC[i][j]=matrixC1pc[i][j]+matrixC2pc[i][j]+matrixC3pc[i][j]+matrixC4pc[i][j];
        }

    }
    cout<<" MatrixC:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixC[i][j]<<" ";
        }
        cout<<endl;
    }

    return matrixC;
   }

    float** MatrixC::generateGlobalMatrixC(Element** Elements)
    {

    int verticalNodeNumber = InputData::getVerticalNodeNumber()-1;
	int horizontalNodeNumber = InputData::getHorizontalNodeNumber()-1;

    matrixCGlobal = new float*[16];
    for(int i = 0; i < 16; i++)
        matrixCGlobal[i] = new float[16];

    int *nodes;


        for (int i = 0; i <verticalNodeNumber*horizontalNodeNumber; i++)
        {
            nodes = Elements[i]->getNodesId();
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                {
                matrixCGlobal[nodes[j]-1][nodes[k]-1]+=matrixC[j][k];
                }
            }

        }

        for(int i=0;i<16;i++)
        {
            for(int j=0;j<16;j++)
                cout<<matrixCGlobal[i][j]<<" | ";
            cout<<endl;
        }

        cout<<endl<<endl<<endl;
        return matrixCGlobal;
    }
