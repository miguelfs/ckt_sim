//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_AMPOP_H
#define CKT_SIM_AMPOP_H


#include "Component.h"

class AmpOp : public Component{

public:

    AmpOp(std::string row, int quantityOfArguments);
public:
    void stampG(double** Gmatrix) override;
    void stampSolutionVector(double* solutionVector) override;
    void stampRightSideVector(double* rightSideVector) override;
};


#endif //CKT_SIM_AMPOP_H
