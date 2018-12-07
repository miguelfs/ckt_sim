//
// Created by Miguel Sousa on 01/12/18.
//

#ifndef CKT_SIM_PULSECURRENTSOURCE_H
#define CKT_SIM_PULSECURRENTSOURCE_H


#include "Component.h"
#include "PulseParameters.h"

class PulseCurrentSource : public Component {

public:
    PulseCurrentSource(std::string row, int quantityOfArguments, double timeStep);

    void stampG(double **G, OperationMethod operationMethod) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) override;

    PulseParameters *pulseParameters;
    double current;
};


#endif //CKT_SIM_PULSECURRENTSOURCE_H
