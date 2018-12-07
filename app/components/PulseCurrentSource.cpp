//
// Created by Miguel Sousa on 01/12/18.
//

#include "PulseCurrentSource.h"
#include "PulseParameters.h"

PulseCurrentSource::PulseCurrentSource(std::string row, int quantityOfArguments, double timeStep) : Component(currentSource){
    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments);
    //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    this->pulseParameters = new PulseParameters(parse(arguments[4]), parse(arguments[5]),
                                                parse(arguments[6]), parse(arguments[7]),
                                                parse(arguments[8]), parse(arguments[9]),
                                                parse(arguments[10]), parse(arguments[11]),
                                                timeStep);

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    this->current = 0;
}

void PulseCurrentSource::stampG(double **G, OperationMethod operationMethod) {
}

void PulseCurrentSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) {
    pulseParameters->setValue(time);
    this->current = pulseParameters->getValue();

    rightSideVector[nodes[0]] += -1.0 * current;
    rightSideVector[nodes[1]] += current;
}