//
// Created by Miguel Sousa on 01/12/18.
//

#include "SineWaveVoltageSource.h"
#include "SineWaveParameters.h"

SineWaveVoltageSource::SineWaveVoltageSource(std::string row, int quantityOfArguments, int wire) {
    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments);
    //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    this->sineWaveParameters = new SineWaveParameters(parse(arguments[4]), parse(arguments[5]),
                                                      parse(arguments[6]), parse(arguments[7]),
                                                      parse(arguments[8]), parse(arguments[9]),
                                                      parse(arguments[10]));

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    this->wire = wire;
    this->voltage = 0;
}


void SineWaveVoltageSource::stampG(double **G, OperationMethod operationMethod) {
    G[0][wire] += 1.0;
    G[1][wire] += -1.0;
    G[wire][0] += -1.0;
    G[wire][1] += 1.0;
}

void SineWaveVoltageSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {
    sineWaveParameters->setValue(0);
    rightSideVector[wire] += -1.0 * sineWaveParameters->getValue();
}
