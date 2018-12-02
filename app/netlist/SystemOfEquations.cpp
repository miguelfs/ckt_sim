//
// Created by Miguel Sousa on 16/11/18.
//

#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iostream>
#include "SystemOfEquations.h"
#include "GaussDecomposition.h"

void SystemOfEquations::setOrderOfMatrixG(int orderOfMatrixG) {
    this->orderOfMatrixG = orderOfMatrixG;
}

void SystemOfEquations::initializeGMatrix() {
    G = (double **) malloc(orderOfMatrixG * sizeof(double *));
    for (int i = 0; i < orderOfMatrixG; i++)
        G[i] = (double *) malloc(orderOfMatrixG * sizeof(double));

    clearThatG();
}

void SystemOfEquations::buildThatG(int quantityOfComponents, std::vector<Component *> &components) {
    for (int i = 0; i < quantityOfComponents; i++)
        components[i]->stampG(G, transient);
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

void SystemOfEquations::printThatRHS() {
    std::cout << std::fixed << std::endl;
    for (int i = 0; i < orderOfMatrixG; i++) {
        std::cout << "[ ";
        if (RHSVector[i] > 0 || RHSVector[i] == 0)
            std::cout << std::setprecision(3) << " " << RHSVector[i] << "\t";
        else
            std::cout << std::setprecision(3) << RHSVector[i] << "\t";
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}

void SystemOfEquations::isOperatingPointNeeded(bool i) {
    if (!i)
        operationMethod = initialConditions;
    else
        operationMethod = operatingPoint;
}

void SystemOfEquations::initializeRSVector() {
    RHSVector = (double *) malloc(orderOfMatrixG * sizeof(double));

    clearThatRHSVector();
}

void SystemOfEquations::clearThatRHSVector() {
    for (int i = 0; i < orderOfMatrixG; i++)
        RHSVector[i] = 0.0;
}

void SystemOfEquations::clearThatSolutionVector() {
    for (int i = 0; i < orderOfMatrixG; i++)
        SolutionVector[i] = 0.0;
}

void SystemOfEquations::initializeSolutionsVector() {
    SolutionVector = (double *) malloc(orderOfMatrixG * sizeof(double));

    clearThatSolutionVector();
}

void SystemOfEquations::buildThatRSVector(int quantityOfComponents, std::vector<Component *> &components) {
    for (int i = 0; i < quantityOfComponents; i++)
        components[i]->stampRightSideVector(RHSVector, operationMethod);
}

SystemOfEquations::SystemOfEquations() {
    operationMethod = operatingPoint;
}

void SystemOfEquations::solveSystem() {

    printThatG();
    printThatRHS();


    GaussDecomposition gaussDecomposition = *new GaussDecomposition();
    gaussDecomposition.solve(G, RHSVector, orderOfMatrixG);

    std::cout << "solution is: \n";
    printThatRHS();

    SolutionVector[0] = 0;
    for (int row = 1; row < orderOfMatrixG; row++) {
        SolutionVector[row] = RHSVector[row];
    }
}

void SystemOfEquations::eliminateGroundVariables(double **G, double *RHSVector, int dimension) {
    for (int row = 0; row < dimension; row++)
        for (int column = 1; column < dimension; column++)
            G[row][column - 1] = G[row][column];

    for (int column = 0; column < dimension - 1; column++)
        for (int row = 1; row < dimension; row++)
            G[row - 1][column] = G[row][column];

    for (int row = 1; row < dimension; row++)
        RHSVector[row - 1] = RHSVector[row - 1];
}

double *SystemOfEquations::getSolutionVector() {
    return SolutionVector;
}

int SystemOfEquations::getOrderOfMatrixG() const {
    return orderOfMatrixG;
}

void SystemOfEquations::clearThatG() {
    for (int i = 0; i < orderOfMatrixG; i++)
        for (int j = 0; j < orderOfMatrixG; j++)
            G[i][j] = 0.0;
}
