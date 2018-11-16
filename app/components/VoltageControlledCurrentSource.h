//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_VOLTAGECONTROLLEDCURRENTSOURCE_H
#define CKT_SIM_VOLTAGECONTROLLEDCURRENTSOURCE_H


#include "Component.h"

class VoltageControlledCurrentSource : public Component {

public:
    VoltageControlledCurrentSource(std::string basic_string, int i);
    void stampG(double** Gmatrix) override;
    void stampSolutionVector(double* solutionVector) override;
    void stampRightSideVector(double* rightSideVector) override;
};


#endif //CKT_SIM_VOLTAGECONTROLLEDCURRENTSOURCE_H
