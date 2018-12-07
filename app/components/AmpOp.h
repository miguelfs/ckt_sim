//
// Created by Miguel Sousa on 02/11/18.
//

#ifndef CKT_SIM_AMPOP_H
#define CKT_SIM_AMPOP_H


#include "Component.h"
#include "../netlist/OperationMethod.h"

class AmpOp : public Component{

private:

    int nodes[4];
    int wire;

public:
    AmpOp(std::string row, int quantityOfArguments, int wire);

    void stampG(double **G, OperationMethod operationMethod) override;
    void stampSolutionVector(double* solutionVector) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) override;
};


#endif //CKT_SIM_AMPOP_H
