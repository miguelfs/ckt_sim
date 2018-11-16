//
// Created by Miguel Sousa on 02/12/17.
//

#include "Capacitor.h"
#include <iostream>

//TODO: ANALISE DE PONTO DE OPERACAO, 10 ELEVADO A 9 = MUITO GRANDE, 10 A MENOS 9 = MUITO PEQUENO
Capacitor::Capacitor(std::string row, int quantityOfArguments, double timeStep) : Component(capacitor) {
    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    capacitance = strtod(arguments[3].c_str(), nullptr);
    initialCurrent = getInitialCurrent(arguments[4]);
    this->timeStep = timeStep;

    std::cout << "name = " << name << ",  nodeA = " << nodes[0] << ", nodeB = " << nodes[1] <<
              ", C = " << capacitance << "F, I(0) = " << initialCurrent << std::endl;
}

void Capacitor::stampG(double **G){
    try {
        isEqualsZero(timeStep);
    } catch (char *errorToPrint) {
        std::cout << errorToPrint;
    }

    double conductance = capacitance / timeStep;

    double stamp[2][2];
    stamp[0][0] = conductance ;
    stamp[0][1] = -1 * conductance;
    stamp[1][0] = -1 * conductance;
    stamp[1][1] = conductance;

    GstampFor2x2Component(G, stamp, nodes);
}


void Capacitor::stampRightSideVector(double *rightSideVector) {

}

void Capacitor::stampSolutionVector(double *solutionVector) {

}

void Capacitor::isEqualsZero(double number) {
    if (number == 0)
        throw ("timeStep equals zero, divide by timeStep not allowed");

}
