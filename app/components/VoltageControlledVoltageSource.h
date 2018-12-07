//
// Created by Miguel Sousa on 02/11/18.
//

#ifndef CKT_SIM_VOLTAGECONTROLLEDVOLTAGESOURCE_H
#define CKT_SIM_VOLTAGECONTROLLEDVOLTAGESOURCE_H


#include "Component.h"
#include "../netlist/OperationMethod.h"

class VoltageControlledVoltageSource : public Component{

private:
    int wire;
    double gain;
    std::string name;
public:
    std::string getName() override;

public:
    VoltageControlledVoltageSource(std::string row, int quantityOfArguments, int wire);

    void stampG(double **Gmatrix, OperationMethod operationMethod) override;
    void stampSolutionVector(double* solutionVector) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) override;
};


#endif //CKT_SIM_VOLTAGECONTROLLEDVOLTAGESOURCE_H
