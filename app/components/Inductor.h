//
// Created by Miguel Sousa on 02/11/18.
//

#ifndef CKT_SIM_INDUCTOR_H
#define CKT_SIM_INDUCTOR_H


#include "Component.h"
#include "../netlist/OperationMethod.h"

class Inductor : public Component{

public:
    Inductor(std::string row, int i, double timeStep, int wire);

    bool doesHaveInitialCondition() override;

    void setCurrent(double current);

private:
    double inductance;
    int nodes[2];
    int wire;
    double current;
    double timeStep;

    void stampG(double **Gmatrix, OperationMethod operationMethod) override;
    void stampSolutionVector(double* solutionVector) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) override;
    void isEqualsZero(double number);

    void setValue(double *SolutionVector) override;
};


#endif //CKT_SIM_INDUCTOR_H
