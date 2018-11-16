//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_CAPACITOR_H
#define CKT_SIM_CAPACITOR_H


#include "Component.h"

class Capacitor : public Component{

public:
    Capacitor(std::string row, int quantityOfArguments, double timeStep);
    void stampG(double** Gmatrix) override;
    void stampSolutionVector(double* solutionVector) override;
    void stampRightSideVector(double* rightSideVector) override;

private:
    double capacitance;
    int nodes[2];
    double initialCurrent;
    double timeStep;


    void isEqualsZero(double step);

};


#endif //CKT_SIM_CAPACITOR_H
