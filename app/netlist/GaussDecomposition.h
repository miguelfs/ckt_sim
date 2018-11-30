//
// Created by Miguel Sousa on 24/11/18.
//

#ifndef CKT_SIM_GAUSSDECOMPOSITION_H
#define CKT_SIM_GAUSSDECOMPOSITION_H


class GaussDecomposition {

public:

    void solve(double **G, double *RHSVector, int dimension);

private:

    void swapRows(double **squareMatrix, int rowA, int rowB, int dimension);

    void swapRows(double *vector, int rowA, int rowB, int dimension);

    void isEqualsZero(double number);

};


#endif //CKT_SIM_GAUSSDECOMPOSITION_H
