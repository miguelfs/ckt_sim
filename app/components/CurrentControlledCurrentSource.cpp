//
// Created by Miguel Sousa on 02/11/18.
//

#include "CurrentControlledCurrentSource.h"
#include "../netlist/OperationMethod.h"

CurrentControlledCurrentSource::CurrentControlledCurrentSource(std::string row, int quantityOfArguments, int wire)
        : Component(currentControlledCurrentSource) {
    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    nodes[2] = stoi(arguments[3]);
    nodes[3] = stoi(arguments[4]);
    this->wire = wire;

    this->gain = strtod(arguments[5].c_str(), nullptr);
}

void CurrentControlledCurrentSource::stampG(double **Gmatrix, OperationMethod operationMethod) {

    Gmatrix[nodes[0]][wire] += gain;
    Gmatrix[nodes[1]][wire] += -1.0 * gain;
    Gmatrix[nodes[2]][wire] += 1.0;
    Gmatrix[nodes[3]][wire] += -1.0;
    Gmatrix[wire][nodes[2]] += -1.0;
    Gmatrix[wire][nodes[3]] += 1.0;
}

void CurrentControlledCurrentSource::stampSolutionVector(double *solutionVector) {

}

void CurrentControlledCurrentSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}
