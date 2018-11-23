//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_RESISTOR_H
#define CKT_SIM_RESISTOR_H


#include "Component.h"
#include "../netlist/OperationMethod.h"

class Resistor: public Component{
public:

    Resistor(std::string row, int quantityOfArguments);

    double resistance;

    void stampG(double** Gmatrix) override;
    void stampSolutionVector(double* solutionVector) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) override;
};


#endif //CKT_SIM_RESISTOR_H
