//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_RESISTOR_H
#define CKT_SIM_RESISTOR_H


#include "Component.h"

class Resistor: public Component{
public:
    Resistor(char*, int[]);

    Resistor(std::string row, int quantityOfArguments);

    explicit Resistor(std::string row);

    Resistor(char *name, int *nodes, double value);

    double resistance;

    void stampG(double** Gmatrix) override;
    void stampSolutionVector(double* solutionVector) override;
    void stampRightSideVector(double* rightSideVector) override;
};


#endif //CKT_SIM_RESISTOR_H
