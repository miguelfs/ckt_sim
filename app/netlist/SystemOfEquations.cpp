//
// Created by Miguel Sousa on 16/11/18.
//

#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iostream>
#include "SystemOfEquations.h"

void SystemOfEquations::setOrderOfMatrixG(int orderOfMatrixG) {
    this->orderOfMatrixG = orderOfMatrixG;
}

void SystemOfEquations::initializeGMatrix() {
    G = (double **) malloc(orderOfMatrixG * sizeof(double *));
    for (int i = 0; i < orderOfMatrixG; i++)
        G[i] = (double *) malloc(orderOfMatrixG * sizeof(double));

    for (int i = 0; i < orderOfMatrixG; i++)
        for (int j = 0; j < orderOfMatrixG; j++)
            G[i][j] = 0.0;
}

void SystemOfEquations::buildThatG(int quantityOfComponents, std::vector<Component *> &components) {

    initializeGMatrix();

    for (int i = 0; i < quantityOfComponents; i++)
        components[i]->stampG(G);

    printThatG();
}


void SystemOfEquations::printThatG() {
    std::cout << std::fixed << std::endl;
    for (int i = 0; i < orderOfMatrixG; i++) {
        std::cout << "[ ";
        for (int j = 0; j < orderOfMatrixG; j++) {
            if (G[i][j] > 0 || G[i][j] == 0)
                std::cout << std::setprecision(3) << " " << G[i][j] << "\t\t\t\t";
            else
                std::cout << std::setprecision(3) << G[i][j] << "\t\t\t\t";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}

void SystemOfEquations::isOperatingPointNeeded(bool i) {
    if (i == false)
        operationMethod = initialConditions;
    else
        operationMethod = operatingPoint;
}

void SystemOfEquations::initializeRSVector() {
    RightSideVector = (double *) malloc(orderOfMatrixG * sizeof(double));

    for (int i = 0; i < orderOfMatrixG; i++)
        RightSideVector[i] = 0.0;
}

void SystemOfEquations::buildThatRSVector(int quantityOfComponents, std::vector<Component *> &components) {
    for (int i = 0; i < quantityOfComponents; i++)
        components[i]->stampRightSideVector(RightSideVector, operationMethod);
}

SystemOfEquations::SystemOfEquations() {
    operationMethod = operatingPoint;
}

