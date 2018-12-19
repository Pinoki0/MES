#include "MatrixHbc2.h"
#include <cmath>
using namespace std;
#include <iostream>

float N111(float ksi, float eta)
{
    return 0.25*(1-ksi)*(1-eta);
}
float N222(float ksi, float eta)
{
    return 0.25*(1+ksi)*(1-eta);
}
float N333(float ksi, float eta)
{
    return 0.25*(1+ksi)*(1+eta);
}
float N444(float ksi, float eta)
{
    return 0.25*(1-ksi)*(1+eta);
}


MatrixHbc2::MatrixHbc2()
{
}

MatrixHbc2::~MatrixHbc2()
{
}
void MatrixHbc2::generateMatrixHbc2(int size, float** pkt)
{



    float Powierzchnia[4];
    Powierzchnia[0]=1;
    Powierzchnia[1]=0;
    Powierzchnia[2]=0;
    Powierzchnia[3]=0;
    float alfa=300;
    float dlugoscBokuL[size];
    dlugoscBokuL[0]=sqrt(pow((pkt[0][0]-pkt[1][0]),2)+pow((pkt[0][1]-pkt[1][1]),2));
    dlugoscBokuL[1]=sqrt(pow((pkt[1][0]-pkt[2][0]),2)+pow((pkt[1][1]-pkt[2][1]),2));
    dlugoscBokuL[2]=sqrt(pow((pkt[2][0]-pkt[3][0]),2)+pow((pkt[2][1]-pkt[3][1]),2));
    dlugoscBokuL[3]=sqrt(pow((pkt[3][0]-pkt[0][0]),2)+pow((pkt[3][1]-pkt[0][1]),2));

    float pow1detJ=dlugoscBokuL[0]/2;
    float pow1ksi[2];
    float pow1eta[2];

    pow1ksi[0]=-1/sqrt(3);
    pow1ksi[1]=1/sqrt(3);
    pow1eta[0]=-1;
    pow1eta[1]=-1;

    float pow1pc2po4N[2][4];
    for(int i=0;i<2;i++)
    {
        pow1pc2po4N[i][0]=N111(pow1ksi[i],pow1eta[i]);
        pow1pc2po4N[i][1]=N222(pow1ksi[i],pow1eta[i]);
        pow1pc2po4N[i][2]=N333(pow1ksi[i],pow1eta[i]);
        pow1pc2po4N[i][3]=N444(pow1ksi[i],pow1eta[i]);

    }

    float ** matrixHpow1pc1 = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHpow1pc1[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHpow1pc1[i][j]=pow1pc2po4N[0][i]*pow1pc2po4N[0][j]*alfa;
        }

    }
    cout<<"matrixHpow1pc1:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHpow1pc1[i][j]<<" ";
        }
        cout<<endl;
    }


        float ** matrixHpow1pc2 = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHpow1pc2[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHpow1pc2[i][j]=pow1pc2po4N[1][i]*pow1pc2po4N[1][j]*alfa;
        }

    }
    cout<<"matrixHpow1pc2:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHpow1pc2[i][j]<<" ";
        }
        cout<<endl;

    }

    float ** matrixHpow1 = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHpow1[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHpow1[i][j]=(matrixHpow1pc1[i][j]+matrixHpow1pc2[i][j])*pow1detJ;
        }

    }

     cout<<"matrixHpow1:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHpow1[i][j]<<" ";
        }
        cout<<endl;
    }



    ////////////////////////////////////////////////



    float pow2detJ=dlugoscBokuL[1]/2;
    float pow2ksi[2];
    float pow2eta[2];

    pow2ksi[0]=1;
    pow2ksi[1]=1;
    pow2eta[0]=-1/sqrt(3);
    pow2eta[1]=1/sqrt(3);

    float pow2pc2po4N[2][4];
    for(int i=0;i<2;i++)
    {
        pow2pc2po4N[i][0]=N111(pow2ksi[i],pow2eta[i]);
        pow2pc2po4N[i][1]=N222(pow2ksi[i],pow2eta[i]);
        pow2pc2po4N[i][2]=N333(pow2ksi[i],pow2eta[i]);
        pow2pc2po4N[i][3]=N444(pow2ksi[i],pow2eta[i]);

    }

    float ** matrixHpow2pc1 = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHpow2pc1[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHpow2pc1[i][j]=pow2pc2po4N[0][i]*pow2pc2po4N[0][j]*alfa;
        }

    }
    cout<<"matrixHpow2pc1:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHpow2pc1[i][j]<<" ";
        }
        cout<<endl;
    }


        float ** matrixHpow2pc2 = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHpow2pc2[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHpow2pc2[i][j]=pow2pc2po4N[1][i]*pow2pc2po4N[1][j]*alfa;
        }

    }
    cout<<"matrixHpow2pc2:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHpow1pc2[i][j]<<" ";
        }
        cout<<endl;

    }

    float ** matrixHpow2 = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHpow2[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHpow2[i][j]=(matrixHpow2pc1[i][j]+matrixHpow2pc2[i][j])*pow2detJ;
        }

    }

     cout<<"matrixHpow2:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHpow2[i][j]<<" ";
        }
        cout<<endl;
    }

/////////////////////////////////////////////////////////////////////

    float pow3detJ=dlugoscBokuL[2]/2;
    float pow3ksi[2];
    float pow3eta[2];

    pow3ksi[0]=1/sqrt(3);
    pow3ksi[1]=-1/sqrt(3);
    pow3eta[0]=1;
    pow3eta[1]=1;

    float pow3pc2po4N[2][4];
    for(int i=0;i<2;i++)
    {
        pow3pc2po4N[i][0]=N111(pow3ksi[i],pow3eta[i]);
        pow3pc2po4N[i][1]=N222(pow3ksi[i],pow3eta[i]);
        pow3pc2po4N[i][2]=N333(pow3ksi[i],pow3eta[i]);
        pow3pc2po4N[i][3]=N444(pow3ksi[i],pow3eta[i]);

    }

    float ** matrixHpow3pc1 = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHpow3pc1[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHpow3pc1[i][j]=pow3pc2po4N[0][i]*pow3pc2po4N[0][j]*alfa;
        }

    }
    cout<<"matrixHpow3pc1:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHpow3pc1[i][j]<<" ";
        }
        cout<<endl;
    }


        float ** matrixHpow3pc2 = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHpow3pc2[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHpow3pc2[i][j]=pow3pc2po4N[1][i]*pow3pc2po4N[1][j]*alfa;
        }

    }
    cout<<"matrixHpow3pc2:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHpow3pc2[i][j]<<" ";
        }
        cout<<endl;

    }

    float ** matrixHpow3 = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHpow3[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHpow3[i][j]=(matrixHpow3pc1[i][j]+matrixHpow3pc2[i][j])*pow3detJ;
        }

    }

     cout<<"matrixHpow3:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHpow3[i][j]<<" ";
        }
        cout<<endl;
    }
/////////////////////////////////////////////////////

    float pow4detJ=dlugoscBokuL[3]/2;
    float pow4ksi[2];
    float pow4eta[2];

    pow4ksi[0]=-1;
    pow4ksi[1]=-1;
    pow4eta[0]=1/sqrt(3);
    pow4eta[1]=-1/sqrt(3);

    float pow4pc2po4N[2][4];
    for(int i=0;i<2;i++)
    {
        pow4pc2po4N[i][0]=N111(pow4ksi[i],pow4eta[i]);
        pow4pc2po4N[i][1]=N222(pow4ksi[i],pow4eta[i]);
        pow4pc2po4N[i][2]=N333(pow4ksi[i],pow4eta[i]);
        pow4pc2po4N[i][3]=N444(pow4ksi[i],pow4eta[i]);

    }

    float ** matrixHpow4pc1 = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHpow4pc1[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHpow4pc1[i][j]=pow4pc2po4N[0][i]*pow4pc2po4N[0][j]*alfa;
        }

    }
    cout<<"matrixHpow4pc1:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHpow4pc1[i][j]<<" ";
        }
        cout<<endl;
    }


        float ** matrixHpow4pc2 = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHpow4pc2[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHpow4pc2[i][j]=pow4pc2po4N[1][i]*pow4pc2po4N[1][j]*alfa;
        }

    }
    cout<<"matrixHpow4pc2:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHpow4pc2[i][j]<<" ";
        }
        cout<<endl;

    }

    float ** matrixHpow4 = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHpow4[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHpow4[i][j]=(matrixHpow4pc1[i][j]+matrixHpow4pc2[i][j])*pow4detJ;
        }

    }

     cout<<"matrixHpow4:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHpow4[i][j]<<" ";
        }
        cout<<endl;
    }


     float ** matrixHbc2d = new float*[size];
    for(int i = 0; i < size; i++)
        matrixHbc2d[i] = new float[size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrixHbc2d[i][j]=matrixHpow1[i][j]*Powierzchnia[0]+matrixHpow2[i][j]*Powierzchnia[1]+matrixHpow3[i][j]*Powierzchnia[2]+matrixHpow4[i][j]*Powierzchnia[3];
        }

    }

     cout<<"matrixHbc2d:"<<endl;

     for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<matrixHbc2d[i][j]<<" ";
        }
        cout<<endl;
    }


}
