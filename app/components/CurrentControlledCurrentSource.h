//
// Created by Miguel Sousa on 02/11/18.
//

#ifndef CKT_SIM_CURRENTCONTROLLEDCURRENTSOURCE_H
#define CKT_SIM_CURRENTCONTROLLEDCURRENTSOURCE_H


#include "Component.h"
#include "../netlist/OperationMethod.h"

class CurrentControlledCurrentSource : public Component {

public:
    CurrentControlledCurrentSource(std::string row, int quantityOfArguments, int wire);

    void stampG(double **Gmatrix, OperationMethod operationMethod) override;
    void stampSolutionVector(double* solutionVector) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) override;

    int wire;
    double gain;
};


#endif //CKT_SIM_CURRENTCONTROLLEDCURRENTSOURCE_H
