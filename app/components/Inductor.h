//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_INDUCTOR_H
#define CKT_SIM_INDUCTOR_H


#include "Component.h"
#include "../netlist/OperationMethod.h"

class Inductor : public Component{

public:
    Inductor(std::string row, int i, double timeStep, int wire);

    bool doesHaveInitialCondition() override;

private:
    double inductance;
    int nodes[2];
    int wire;
    double initialCurrent;
    double timeStep;

    void stampG(double** Gmatrix) override;
    void stampSolutionVector(double* solutionVector) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) override;
    void isEqualsZero(double number);
};


#endif //CKT_SIM_INDUCTOR_H
