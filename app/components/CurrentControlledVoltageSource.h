//
// Created by Miguel Sousa on 02/11/18.
//

#ifndef CKT_SIM_CURRENTCONTROLLEDVOLTAGESOURCE_H
#define CKT_SIM_CURRENTCONTROLLEDVOLTAGESOURCE_H


#include "Component.h"
#include "../netlist/OperationMethod.h"

class CurrentControlledVoltageSource  : public Component{

public:
    CurrentControlledVoltageSource(std::string row, int quantityOfArguments, int wireX,
                                   int wireY);

    void stampG(double **Gmatrix, OperationMethod operationMethod) override;
    void stampSolutionVector(double* solutionVector) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) override;

    int wireX;
    double gain;
    int wireY;
};


#endif //CKT_SIM_CURRENTCONTROLLEDVOLTAGESOURCE_H
