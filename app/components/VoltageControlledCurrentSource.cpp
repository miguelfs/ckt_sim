//
// Created by Miguel Sousa on 02/11/18.
//

#include "VoltageControlledCurrentSource.h"
#include "../netlist/OperationMethod.h"

VoltageControlledCurrentSource::VoltageControlledCurrentSource(std::string row, int quantityOfArguments) : Component(
        voltageControlledCurrentSource) {

    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    nodes[2] = stoi(arguments[3]);
    nodes[3] = stoi(arguments[4]);

    this->gain = strtod(arguments[5].c_str(), nullptr);
}

void VoltageControlledCurrentSource::stampG(double **Gmatrix, OperationMethod operationMethod) {
    Gmatrix[nodes[0]][nodes[2]] += gain;
    Gmatrix[nodes[0]][nodes[3]] += -1.0 * gain;
    Gmatrix[nodes[1]][nodes[2]] += -1.0 * gain;
    Gmatrix[nodes[1]][nodes[3]] += gain;
}

void VoltageControlledCurrentSource::stampSolutionVector(double *solutionVector) {

}

void VoltageControlledCurrentSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}
