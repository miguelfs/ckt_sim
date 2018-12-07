//
// Created by Miguel Sousa on 02/11/18.
//

#ifndef CKT_SIM_RESISTOR_H
#define CKT_SIM_RESISTOR_H


#include "Component.h"
#include "../netlist/OperationMethod.h"

class Resistor: public Component{
public:

    Resistor(std::string row, int quantityOfArguments);

    double resistance;

    void stampG(double **Gmatrix, OperationMethod operationMethod) override;
    void stampSolutionVector(double* solutionVector) override;

    void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) override;
};


#endif //CKT_SIM_RESISTOR_H
