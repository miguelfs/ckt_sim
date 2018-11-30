//
// Created by Miguel Sousa on 02/11/18.
//

#ifndef CKT_SIM_CAPACITOR_H
#define CKT_SIM_CAPACITOR_H


#include "Component.h"
#include "../netlist/OperationMethod.h"

class Capacitor : public Component{

public:
    Capacitor(std::string row, int quantityOfArguments, double timeStep);

    void stampG(double **Gmatrix, OperationMethod operationMethod) override;
    void stampSolutionVector(double* solutionVector) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) override;

    bool doesHaveInitialCondition() override;

private:
    double capacitance;
    int nodes[2];
    double initialVoltage;
    double timeStep;


    void isEqualsZero(double step);

};


#endif //CKT_SIM_CAPACITOR_H
