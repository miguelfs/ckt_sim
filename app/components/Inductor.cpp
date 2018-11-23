//
// Created by Miguel Sousa on 02/12/17.
//

#include "Inductor.h"
#include "../netlist/OperationMethod.h"
#include <iostream>

Inductor::Inductor(std::string row, int quantityOfArguments, double timeStep, int wire) : Component(inductor){
    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    this->wire = wire;
    inductance = strtod(arguments[3].c_str(), nullptr);
    initialCurrent = getInitialCondition(arguments[4]);
    this->timeStep = timeStep;

    std::cout << "name = " << name << ",  nodeA = " << nodes[0] << ", nodeB = " << nodes[1] << ", wire = " << wire <<
              ", L = " << inductance << "H, I(0) = " << initialCurrent << ", timeStep = " << this->timeStep
              << std::endl;
}

void Inductor::stampG(double **G) {
    try {
        isEqualsZero(timeStep);
    } catch (char *errorToPrint) {
        std::cout << errorToPrint;
    }

    double conductance =  timeStep/inductance;

    double stamp[3][3];
    stamp[0][0] = 0.0;
    stamp[0][1] = 0.0;
    stamp[0][2] = 1.0;
    stamp[1][0] = 0.0;
    stamp[1][1] = 0.0;
    stamp[1][2] = -1.0;
    stamp[2][0] = -1.0;
    stamp[2][1] = 1.0;
    stamp[2][2] = conductance;

    G[nodes[0]][nodes[0]] += stamp[0][0];
    G[nodes[0]][nodes[1]] += stamp[0][1];
    G[nodes[0]][wire] += stamp[0][2];
    G[nodes[1]][nodes[0]] += stamp[1][0];
    G[nodes[1]][nodes[1]] += stamp[1][1];
    G[nodes[1]][wire] += stamp[1][2];
    G[wire][nodes[0]] += stamp[2][0];
    G[wire][nodes[1]] += stamp[2][1];
    G[wire][wire] += stamp[2][2];
}

void Inductor::stampSolutionVector(double *solutionVector) {

}

void Inductor::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}

void Inductor::isEqualsZero(double number) {
    if (number == 0)
        throw ("timeStep equals zero, divide by timeStep not allowed");

}

bool Inductor::doesHaveInitialCondition() {
    return initialCurrent != 0;
}
