//
// Created by Miguel Sousa on 23/11/18.
//

#ifndef CKT_SIM_LUDECOMPOSITION_H
#define CKT_SIM_LUDECOMPOSITION_H


class LUDecomposition {

    void LUPInvert(double **A, int *P, int N, double **IA);

public:
    int LUPDecompose(double **A, int N, double Tol, int *P);

    void LUPSolve(double **A, int *P, double *b, int N, double *x);
};


#endif //CKT_SIM_LUDECOMPOSITION_H
