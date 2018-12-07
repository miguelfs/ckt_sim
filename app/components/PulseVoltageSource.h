//
// Created by Miguel Sousa on 01/12/18.
//

#ifndef CKT_SIM_PULSEVOLTAGESOURCE_H
#define CKT_SIM_PULSEVOLTAGESOURCE_H


#include "Component.h"
#include "PulseParameters.h"

class PulseVoltageSource : public Component {

public:
    PulseVoltageSource(std::string row, int quantityOfArguments, int wire, double timeStep);

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) override;

    void stampG(double **G, OperationMethod operationMethod) override;

    PulseParameters *pulseParameters;
    double voltage;
    int wire;
};


#endif //CKT_SIM_PULSEVOLTAGESOURCE_H
