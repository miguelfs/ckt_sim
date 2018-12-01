//
// Created by Miguel Sousa on 02/11/18.
//

#ifndef CKT_SIM_VOLTAGECONTROLLEDCURRENTSOURCE_H
#define CKT_SIM_VOLTAGECONTROLLEDCURRENTSOURCE_H


#include "Component.h"
#include "../netlist/OperationMethod.h"

class VoltageControlledCurrentSource : public Component {

public:
    VoltageControlledCurrentSource(std::string basic_string, int quantityOfArguments);

    void stampG(double **Gmatrix, OperationMethod operationMethod) override;
    void stampSolutionVector(double* solutionVector) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) override;

    double gain;
};


#endif //CKT_SIM_VOLTAGECONTROLLEDCURRENTSOURCE_H
