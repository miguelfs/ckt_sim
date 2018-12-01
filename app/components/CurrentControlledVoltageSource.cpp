//
// Created by Miguel Sousa on 02/11/18.
//

#include "CurrentControlledVoltageSource.h"
#include "../netlist/OperationMethod.h"

CurrentControlledVoltageSource::CurrentControlledVoltageSource(std::string row, int quantityOfArguments, int wireX,
                                                               int wireY)
        : Component(currentControlledVoltageSource) {

    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    nodes[2] = stoi(arguments[3]);
    nodes[3] = stoi(arguments[4]);
    this->wireX = wireX;
    this->wireY = wireY;
    this->gain = strtod(arguments[5].c_str(), nullptr);

}

void CurrentControlledVoltageSource::stampG(double **Gmatrix, OperationMethod operationMethod) {
    Gmatrix[nodes[0]][wireY] += 1.0;
    Gmatrix[nodes[1]][wireY] += -1.0;
    Gmatrix[nodes[2]][wireX] += 1.0;
    Gmatrix[nodes[3]][wireX] += -1.0;

    Gmatrix[wireX][nodes[2]] += -1.0;
    Gmatrix[wireX][nodes[3]] += 1.0;

    Gmatrix[wireY][nodes[0]] += -1.0;
    Gmatrix[wireY][nodes[1]] += 1.0;


    Gmatrix[wireY][wireX] += gain;
}

void CurrentControlledVoltageSource::stampSolutionVector(double *solutionVector) {

}

void CurrentControlledVoltageSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}
