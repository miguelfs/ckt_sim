//
// Created by Miguel Sousa on 02/11/18.
//

#include <sstream>
#include <vector>
#include "Resistor.h"
#include "../netlist/OperationMethod.h"


Resistor::Resistor(std::string row, int quantityOfArguments) : Component(resistor) {

    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, row, arguments);
    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    resistance = atof(arguments[3].c_str());
}

//inspiration: jspice by timmolter, https://github.com/knowm/jspice
void Resistor::stampG(double **G, OperationMethod operationMethod) {

    double conductance = 1 / this->resistance;

    double stamp[2][2];
    stamp[0][0] = conductance;
    stamp[0][1] = -1 * conductance;
    stamp[1][0] = -1 * conductance;
    stamp[1][1] = conductance;

    //check for ground nodes
    GstampFor2x2Component(G, stamp, nodes);
}

void Resistor::stampSolutionVector(double *solutionVector) {
//do nothing
}

void Resistor::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {
    //do nothing
}
    

