//
// Created by Miguel Sousa on 01/12/18.
//

#include "PulseVoltageSource.h"
#include "PulseParameters.h"

PulseVoltageSource::PulseVoltageSource(std::string row, int quantityOfArguments, int wire, double timeStep) : Component(voltageSource){
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
    this->wire = wire;
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    this->voltage = 0;
}

void PulseVoltageSource::stampG(double **G, OperationMethod operationMethod) {
    G[nodes[0]][wire] += 1.0;
    G[nodes[1]][wire] += -1.0;
    G[wire][nodes[0]] += -1.0;
    G[wire][nodes[1]] += 1.0;
}


void PulseVoltageSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) {

    pulseParameters->setValue(time);
    voltage = pulseParameters->getValue();
    rightSideVector[wire] += -1.0 * voltage;
}

