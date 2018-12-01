//
// Created by Miguel Sousa on 01/12/18.
//

#ifndef CKT_SIM_SINEWAVEVOLTAGESOURCE_H
#define CKT_SIM_SINEWAVEVOLTAGESOURCE_H


#include "Component.h"
#include "SineWaveParameters.h"

class SineWaveVoltageSource : public Component {

public:
    SineWaveVoltageSource(std::string row, int quantityOfArguments, int wire);

    void stampG(double **G, OperationMethod operationMethod) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) override;

    SineWaveParameters *sineWaveParameters;
    int voltage;
    int wire;
};


#endif //CKT_SIM_SINEWAVEVOLTAGESOURCE_H
