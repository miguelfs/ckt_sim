//
// Created by Miguel Sousa on 02/11/18.
//

#include "Capacitor.h"
#include "../netlist/OperationMethod.h"
#include <iostream>

Capacitor::Capacitor(std::string row, int quantityOfArguments, double timeStep) : Component(capacitor) {
    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    capacitance = strtod(arguments[3].c_str(), nullptr);
    voltage = getInitialCondition(arguments[4]);
    this->timeStep = timeStep;

    std::cout << "name = " << name << ",  nodeA = " << nodes[0] << ", nodeB = " << nodes[1] <<
              ", C = " << capacitance << "F, I(0) = " << voltage << std::endl;
}

//quando newton-raphson, matriz G muda POIS nao linear.
void Capacitor::stampG(double **G, OperationMethod operationMethod) {
    try {
        isEqualsZero(timeStep);
    } catch (char *errorToPrint) {
        std::cout << errorToPrint;
    }

    double conductance = capacitance / timeStep;

    if (operationMethod == operatingPoint) {
        conductance = 1.0 / infiniteReactance;
    }

    if (operationMethod == initialConditions)
        conductance = capacitance / infinitesimalTimeStep;

    double stamp[2][2];
    stamp[0][0] = conductance ;
    stamp[0][1] = -1 * conductance;
    stamp[1][0] = -1 * conductance;
    stamp[1][1] = conductance;

    GstampFor2x2Component(G, stamp, nodes);
}


void Capacitor::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) {

    double voltageByIntegration = capacitance * voltage / timeStep;
    double stamp[2];
    stamp[0] = capacitance * voltage / timeStep;
    stamp[1] = -1.0 * capacitance * voltage / timeStep;

      if (operationMethod == initialConditions) {
          stamp[0] = capacitance * voltage / infinitesimalTimeStep;
          stamp[1] = -1.0 * capacitance * voltage / infinitesimalTimeStep;
     }

     if (operationMethod == operatingPoint ) {
         stamp[0] = 1.0 / infinitesimalReactance;
         stamp[1] = -1.0 / infinitesimalReactance;
     }


    rightSideVector[nodes[0]] += stamp[0];
    rightSideVector[nodes[1]] += stamp[1];
}

void Capacitor::stampSolutionVector(double *solutionVector) {

}

void Capacitor::isEqualsZero(double number) {
    if (number == 0)
        throw ("timeStep equals zero, divide by timeStep not allowed");

}

bool Capacitor::doesHaveInitialCondition() {
    return voltage != 0;
}

void Capacitor::setValue(double *SolutionVector) {
    voltage = SolutionVector[nodes[0]] - SolutionVector[nodes[1]];
}
