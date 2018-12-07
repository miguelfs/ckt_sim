//
// Created by Miguel Sousa on 02/11/18.
//

#include <iostream>
#include "VoltageControlledVoltageSource.h"
#include "../netlist/OperationMethod.h"

VoltageControlledVoltageSource::VoltageControlledVoltageSource(std::string row, int quantityOfArguments, int wire)
        : Component(voltageControlledVoltageSource) {

    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    nodes[2] = stoi(arguments[3]);
    nodes[3] = stoi(arguments[4]);
    this->wire = wire;

    this->gain = strtod(arguments[5].c_str(), nullptr);

    std::cout << "name = " << name << ",  nodeA = " << nodes[0] << ", nodeB = " << nodes[1] << ", wire = " << wire <<
              ", GAIN = " << gain << std::endl;
}

void VoltageControlledVoltageSource::stampG(double **Gmatrix, OperationMethod operationMethod) {

    Gmatrix[nodes[0]][wire] += 1.0;
    Gmatrix[nodes[1]][wire] += -1.0;
    Gmatrix[wire][nodes[0]] += -1.0;
    Gmatrix[wire][nodes[1]] += 1.0;
    Gmatrix[wire][nodes[2]] += gain;
    Gmatrix[wire][nodes[3]] += gain;

}

void VoltageControlledVoltageSource::stampSolutionVector(double *solutionVector) {

}

void VoltageControlledVoltageSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) {

}

 std::string VoltageControlledVoltageSource::getName(){
    return name;
}
