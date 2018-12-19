#ifndef JAKOBIAN2D_H
#define JAKOBIAN2D_H



class Jakobian2D
{

    float** jakobianPrzezDet;
    float** jakobian;
    float* detJakobian;
    float**ksztaltWzgledemKsi;
    float**ksztaltWzgledemEta;
    float **N;

    public:
        Jakobian2D();
        virtual ~Jakobian2D();
        void generateJakobian2D(float *ksi,float*eta,float**pkt, int size);

        float** getJakobianPrzezDet();
        float** getJakobian();
        float* getDetJakobian();

        float** getKsztaltWzgledemKsi();
        float** getKsztaltWzgledemEta();
        float** getN();
};

#endif // LICZ_H
