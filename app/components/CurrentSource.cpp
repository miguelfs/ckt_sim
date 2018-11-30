//
// Created by Miguel Sousa on 02/11/18.
//

#include "CurrentSource.h"
#include "../netlist/OperationMethod.h"

CurrentSource::CurrentSource(std::string row, int i) : Component(currentSource) {

}

void CurrentSource::stampG(double **Gmatrix, OperationMethod operationMethod) {

}

void CurrentSource::stampSolutionVector(double *solutionVector) {

}

void CurrentSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}
