//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_VOLTAGESOURCE_H
#define CKT_SIM_VOLTAGESOURCE_H


#include "Component.h"

class VoltageSource : public Component {

public:

    VoltageSource(std::string row, int quantityOfArguments, int wire);

    void stampG(double **G) override;
    void stampSolutionVector(double* solutionVector) override;
    void stampRightSideVector(double* rightSideVector) override;

private:
    int wire;
};


#endif //CKT_SIM_VOLTAGESOURCE_H
