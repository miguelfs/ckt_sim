//
// Created by Miguel Sousa on 16/11/18.
//

#include <cstdlib>
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
    std::cout << std::endl;
    for (int i = 0; i < orderOfMatrixG; i++) {
        std::cout << "[ ";
        for (int j = 0; j < orderOfMatrixG; j++)
            std::cout << G[i][j] << "\t\t\t\t";
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}

