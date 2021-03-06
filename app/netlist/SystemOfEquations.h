//
// Created by Miguel Sousa on 16/11/18.
//

#ifndef CKT_SIM_SYSTEMOFEQUATIONS_H
#define CKT_SIM_SYSTEMOFEQUATIONS_H


#include "../components/Component.h"
#include "OperationMethod.h"
#include <vector>

class SystemOfEquations {
public:

    SystemOfEquations();

    double **G;

    double *RHSVector;

    double *SolutionVector;

    void setOrderOfMatrixG(int orderOfMatrixG);

    void initializeGMatrix();

    void buildThatG(int quantityOfComponents, std::vector<Component *> &components,
                        OperationMethod operationMethod);

    void initializeRSVector();

    void initializeSolutionsVector();

    void buildThatRSVector(int quantityOfComponents, std::vector<Component *> &components, double time);

    void solveSystem();

    double *getSolutionVector();

    int getOrderOfMatrixG() const;

    void clearThatG();

    void clearThatRHSVector();

    void clearThatSolutionVector();

private:
    int orderOfMatrixG;

    OperationMethod operationMethod;
public:
    void setOperationMethod(OperationMethod operationMethod);

public:
    OperationMethod getOperationMethod();

private:


    void solve();

};


#endif //CKT_SIM_SYSTEMOFEQUATIONS_H
