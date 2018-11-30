//
// Created by Miguel Sousa on 02/11/18.
//

#include "Capacitor.h"
#include "../netlist/OperationMethod.h"
#include <iostream>

//TODO: ANALISE DE PONTO DE OPERACAO, 10 ELEVADO A 9 = MUITO GRANDE, 10 A MENOS 9 = MUITO PEQUENO
Capacitor::Capacitor(std::string row, int quantityOfArguments, double timeStep) : Component(capacitor) {
    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    capacitance = strtod(arguments[3].c_str(), nullptr);
    initialVoltage = getInitialCondition(arguments[4]);
    this->timeStep = timeStep;

    std::cout << "name = " << name << ",  nodeA = " << nodes[0] << ", nodeB = " << nodes[1] <<
              ", C = " << capacitance << "F, I(0) = " << initialVoltage << std::endl;
}

//quando newton-raphson, matriz G muda POIS nao linear.
void Capacitor::stampG(double **G, OperationMethod operationMethod) {
    try {
        isEqualsZero(timeStep);
    } catch (char *errorToPrint) {
        std::cout << errorToPrint;
    }

    double conductance = capacitance / timeStep;
    if (operationMethod == operatingPoint)
        conductance = 0.000000000000001;

    double stamp[2][2];
    stamp[0][0] = conductance ;
    stamp[0][1] = -1 * conductance;
    stamp[1][0] = -1 * conductance;
    stamp[1][1] = conductance;

    GstampFor2x2Component(G, stamp, nodes);
}


void Capacitor::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {
    double stamp[2];
    stamp[0] = 0.0;
    stamp[1] = 0.0;
    if (operationMethod == initialConditions) {
        stamp[0] = capacitance * initialVoltage / timeStep;
        stamp[1] = -1.0 * capacitance * initialVoltage / timeStep;
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
    return initialVoltage != 0;
}
