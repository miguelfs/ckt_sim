//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_VOLTAGECONTROLLEDVOLTAGESOURCE_H
#define CKT_SIM_VOLTAGECONTROLLEDVOLTAGESOURCE_H


#include "Component.h"

class VoltageControlledVoltageSource : public Component{

public:
    VoltageControlledVoltageSource(std::string row, int i);
    void stampG(double** Gmatrix) override;
    void stampSolutionVector(double* solutionVector) override;
    void stampRightSideVector(double* rightSideVector) override;
};


#endif //CKT_SIM_VOLTAGECONTROLLEDVOLTAGESOURCE_H
