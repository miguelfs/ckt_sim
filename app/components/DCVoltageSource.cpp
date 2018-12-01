//
// Created by Miguel Sousa on 02/11/18.
//

#include "DCVoltageSource.h"
#include "../netlist/OperationMethod.h"

DCVoltageSource::DCVoltageSource(std::string row, int quantityOfArguments, int wire) : Component(voltageSource) {

    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);

    this->wire = wire;
    this->voltage = strtod(arguments[4].c_str(), nullptr);
}


void DCVoltageSource::stampG(double **G, OperationMethod operationMethod) {

    G[0][wire] += 1.0;
    G[1][wire] += -1.0;
    G[wire][0] += -1.0;
    G[wire][1] += 1.0;

}

void DCVoltageSource::stampSolutionVector(double *solutionVector) {

}

void DCVoltageSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

    rightSideVector[wire] += -1.0 * voltage;
}
