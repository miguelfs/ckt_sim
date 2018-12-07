//
// Created by Miguel Sousa on 01/12/18.
//

#ifndef CKT_SIM_SINEWAVECURRENTSOURCE_H
#define CKT_SIM_SINEWAVECURRENTSOURCE_H


#include "Component.h"
#include "SineWaveParameters.h"

class SineWaveCurrentSource : public Component {
public:

    SineWaveCurrentSource(std::string row, int quantityOfArguments);

    void stampG(double **G, OperationMethod operationMethod) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) override;

    SineWaveParameters *sineWaveParameters;
    double current;
};


#endif //CKT_SIM_SINEWAVECURRENTSOURCE_H
