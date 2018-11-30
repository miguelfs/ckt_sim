//
// Created by Miguel Sousa on 02/11/18.
//

#include "CurrentControlledCurrentSource.h"
#include "../netlist/OperationMethod.h"

CurrentControlledCurrentSource::CurrentControlledCurrentSource(std::string row, int i) : Component(currentControlledCurrentSource){

}

void CurrentControlledCurrentSource::stampG(double **Gmatrix, OperationMethod operationMethod) {

}

void CurrentControlledCurrentSource::stampSolutionVector(double *solutionVector) {

}

void CurrentControlledCurrentSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}
