//
// Created by Miguel Sousa on 02/11/18.
//

#include "AmpOp.h"
#include "../netlist/OperationMethod.h"

AmpOp::AmpOp(std::string row, int quantityOfArguments, int wire) : Component(ampOp) {

    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    nodes[2] = stoi(arguments[3]);
    nodes[3] = stoi(arguments[4]);
    this->wire = wire;
}

void AmpOp::stampG(double **G, OperationMethod operationMethod) {
//modelo baseado no amp op ideal
    G[nodes[0]][wire] += 1.0;
    G[nodes[1]][wire] += -1.0;
    G[wire][nodes[2]] += 1.0;
    G[wire][nodes[3]] += -1.0;
}

void AmpOp::stampSolutionVector(double *solutionVector) {

}

void AmpOp::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) {

}
