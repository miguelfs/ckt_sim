//
// Created by Miguel Sousa on 16/11/18.
//

#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iostream>
#include <Eigen/Dense>
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
 //   printThatG();
}

void SystemOfEquations::buildThatG(int quantityOfComponents, std::vector<Component *> &components,
                                   OperationMethod operationMethod) {
    for (int i = 0; i < quantityOfComponents; i++)
        components[i]->stampG(G, operationMethod);
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

void SystemOfEquations::buildThatRSVector(int quantityOfComponents, std::vector<Component *> &components, double time) {
    for (int i = 0; i < quantityOfComponents; i++)
        components[i]->stampRightSideVector(RHSVector, operationMethod, time);
}

SystemOfEquations::SystemOfEquations() {
    SystemOfEquations::operationMethod = operatingPoint;
}

void SystemOfEquations::solveSystem() {
    this->solve();
}

double *SystemOfEquations::getSolutionVector() {
    return SolutionVector;
}

int SystemOfEquations::getOrderOfMatrixG() const {
    return orderOfMatrixG;
}

void SystemOfEquations::clearThatG() {
    for (int i = 0; i < orderOfMatrixG; i++) {
        for (int j = 0; j < orderOfMatrixG; j++) {
            G[i][j] = 0.0;
        }
    }
}

OperationMethod SystemOfEquations::getOperationMethod() {
    std::cout << "pegar metodo de operacao\n";
    return operationMethod;
}

void SystemOfEquations::solve() {
    Eigen::MatrixXd g(orderOfMatrixG - 1, orderOfMatrixG - 1);
    Eigen::VectorXd rhsVector(orderOfMatrixG - 1);

    for (int row = 1; row < orderOfMatrixG; row++) {
    rhsVector(row - 1) = RHSVector[row];
    for (int column = 1; column < orderOfMatrixG; column++)
        g(row - 1, column - 1) = G[row][column];
    }
 //   Eigen::IOFormat CleanFmt(4, 0, ", ", "\n", "[", "]");

 //   std::cout << "G MATRIX: \n" << g.format(CleanFmt) << "\n\n";
//    std::cout <<"RHS VECTOR: \n" << rhsVector.format(CleanFmt) << "\n\n";

    Eigen::VectorXd solutionVector = g.colPivHouseholderQr().solve(rhsVector);
 //   std::cout << "SOLUTION VECTOR: \n" <<solutionVector.format(CleanFmt) << "\n\n";

    SolutionVector[0] = 0;
    for (int row = 1; row < orderOfMatrixG; row++)
        SolutionVector[row] = solutionVector(row - 1);
}

void SystemOfEquations::setOperationMethod(OperationMethod operationMethod) {
    SystemOfEquations::operationMethod = operationMethod;
}





