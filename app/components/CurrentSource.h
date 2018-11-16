//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_CURRENTSOURCE_H
#define CKT_SIM_CURRENTSOURCE_H


#include "Component.h"

class CurrentSource : public Component{

public:
    CurrentSource(std::string row, int i);
    void stampG(double** Gmatrix) override;
    void stampSolutionVector(double* solutionVector) override;
    void stampRightSideVector(double* rightSideVector) override;
};


#endif //CKT_SIM_CURRENTSOURCE_H
