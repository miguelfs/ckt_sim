//
// Created by Miguel Sousa on 01/11/18.
//

#ifndef CKT_SIM_NETLIST_H
#define CKT_SIM_NETLIST_H

#include <string>
#include <vector>
#include "../components/Component.h"
#include "Transient.h"
#include "SystemOfEquations.h"

class Netlist {
public:

    explicit Netlist(std::string);

    void buildThatG();

    void buildThatRSVector();


    void doOperatingPointIfNeeded();

    void solveSystem();

private:
    std::vector<Component *> components;
    double** GMatrix;
    double* rightSideVector;
    SystemOfEquations systemOfEquations;

public:

private:
    int quantityOfComponents;
    int quantityOfNodes;
    int quantityOfAuxiliarCurrents;
    int orderOfMatrixG;
    Transient transient;

    void initializeComponents(std::string *text, int i, double timeStep);

    bool isAuxiliarEquationNeeded(Component_Type type);

    void setTransient(const std::string *text, int numberOfLines);

};


#endif //CKT_SIM_NETLIST_H