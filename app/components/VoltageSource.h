//
// Created by Miguel Sousa on 02/11/18.
//

#ifndef CKT_SIM_VOLTAGESOURCE_H
#define CKT_SIM_VOLTAGESOURCE_H


#include "Component.h"
#include "../netlist/OperationMethod.h"

class VoltageSource : public Component {

public:

    VoltageSource(std::string row, int quantityOfArguments, int wire);

    void stampG(double **G, OperationMethod operationMethod) override;
    void stampSolutionVector(double* solutionVector) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) override;

private:
    int wire;
};


#endif //CKT_SIM_VOLTAGESOURCE_H
