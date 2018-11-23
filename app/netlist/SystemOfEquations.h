//
// Created by Miguel Sousa on 16/11/18.
//

#ifndef CKT_SIM_SYSTEMOFEQUATIONS_H
#define CKT_SIM_SYSTEMOFEQUATIONS_H


#include "../components/Component.h"
#include "InitializationMethod.h"

class SystemOfEquations {
public:

    SystemOfEquations();

    double **G;

    void setOrderOfMatrixG(int orderOfMatrixG);

    void initializeGMatrix();

    void buildThatG(int quantityOfComponents, std::vector<Component *> &components);

    void isOperatingPointNeeded(bool i);

private:
    int orderOfMatrixG;

    void printThatG();

    InitializationMethod initializationMethod;
};


#endif //CKT_SIM_SYSTEMOFEQUATIONS_H
