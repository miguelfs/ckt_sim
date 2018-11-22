//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_AMPOP_H
#define CKT_SIM_AMPOP_H


#include "Component.h"

class AmpOp : public Component{

private:

    int nodes[4];
    int wire;

public:
    AmpOp(std::string row, int quantityOfArguments, int wire);

    void stampG(double **G) override;
    void stampSolutionVector(double* solutionVector) override;
    void stampRightSideVector(double* rightSideVector) override;
};


#endif //CKT_SIM_AMPOP_H
