//
// Created by Miguel Sousa on 02/12/17.
//

#include "CurrentSource.h"
#include "../netlist/OperationMethod.h"

CurrentSource::CurrentSource(std::string row, int i) : Component(currentSource) {

}

void CurrentSource::stampG(double **Gmatrix) {

}

void CurrentSource::stampSolutionVector(double *solutionVector) {

}

void CurrentSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}
