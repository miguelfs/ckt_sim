//
// Created by Miguel Sousa on 16/11/18.
//

#ifndef CKT_SIM_SYSTEMOFEQUATIONS_H
#define CKT_SIM_SYSTEMOFEQUATIONS_H


#include "../components/Component.h"

class SystemOfEquations {
public:
    double **G;

    void setOrderOfMatrixG(int orderOfMatrixG);

    void initializeGMatrix();

    void buildThatG(int quantityOfComponents, std::vector<Component *> &components);

private:
    int orderOfMatrixG;

    void printThatG();
};


#endif //CKT_SIM_SYSTEMOFEQUATIONS_H
