//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_VOLTAGESOURCE_H
#define CKT_SIM_VOLTAGESOURCE_H


#include "Component.h"

class VoltageSource : public Component {

public:
    VoltageSource(std::string basic_string, int i);
    void stampG(double** Gmatrix) override;
    void stampSolutionVector(double* solutionVector) override;
    void stampRightSideVector(double* rightSideVector) override;
};


#endif //CKT_SIM_VOLTAGESOURCE_H
