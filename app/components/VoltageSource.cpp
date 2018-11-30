//
// Created by Miguel Sousa on 02/11/18.
//

#include "VoltageSource.h"
#include "../netlist/OperationMethod.h"

VoltageSource::VoltageSource(std::string row, int quantityOfArguments, int wire) : Component(voltageSource) {

    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    nodes[2] = stoi(arguments[3]);
    nodes[3] = stoi(arguments[4]);

    this->wire = wire;
}

void VoltageSource::stampG(double **G, OperationMethod operationMethod) {

    G[0][wire] += 1.0;
    G[1][wire] += -1.0;
    G[wire][0] += -1.0;
    G[wire][1] += 1.0;

}

void VoltageSource::stampSolutionVector(double *solutionVector) {

}

void VoltageSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}
