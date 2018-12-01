//
// Created by Miguel Sousa on 02/11/18.
//

#ifndef CKT_SIM_CURRENTSOURCE_H
#define CKT_SIM_CURRENTSOURCE_H


#include "Component.h"
#include "../netlist/OperationMethod.h"
#include "SineWaveParameters.h"

class DCCurrentSource : public Component {

public:
    DCCurrentSource(std::string row, int quantityOfArguments);

    void stampG(double **Gmatrix, OperationMethod operationMethod) override;
    void stampSolutionVector(double* solutionVector) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) override;

    double current;
    SineWaveParameters *sineWaveParameters;
};


#endif //CKT_SIM_CURRENTSOURCE_H
