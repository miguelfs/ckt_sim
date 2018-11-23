//
// Created by Miguel Sousa on 16/11/18.
//

#ifndef CKT_SIM_SYSTEMOFEQUATIONS_H
#define CKT_SIM_SYSTEMOFEQUATIONS_H


#include "../components/Component.h"
#include "OperationMethod.h"

class SystemOfEquations {
public:

    SystemOfEquations();

    double **G;

    double *RightSideVector;

    void setOrderOfMatrixG(int orderOfMatrixG);

    void initializeGMatrix();

    void buildThatG(int quantityOfComponents, std::vector<Component *> &components);

    void isOperatingPointNeeded(bool i);

private:
    int orderOfMatrixG;

    void printThatG();

    OperationMethod operationMethod;

    void setStampsForInitialCondition(int quantityOfComponents, std::vector<Component *> &components);

    void initializeRSVector();

    void buildThatRSVector(int quantityOfComponents, std::vector<Component *> &components);
};


#endif //CKT_SIM_SYSTEMOFEQUATIONS_H
