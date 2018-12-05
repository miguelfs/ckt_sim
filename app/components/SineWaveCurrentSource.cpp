//
// Created by Miguel Sousa on 01/12/18.
//

#include "SineWaveCurrentSource.h"
#include "SineWaveParameters.h"

SineWaveCurrentSource::SineWaveCurrentSource(std::string row, int quantityOfArguments) : Component(currentSource) {
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
    this->current = 0;
}

void SineWaveCurrentSource::stampG(double **G, OperationMethod operationMethod) {
}

void
SineWaveCurrentSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) {
    sineWaveParameters->setValue(0);
    this->current = sineWaveParameters->getValue();

    rightSideVector[nodes[0]] += -1.0 * current;
    rightSideVector[nodes[1]] += current;
}
