//
// Created by Miguel Sousa on 02/11/18.
//

#include "VoltageControlledCurrentSource.h"
#include "../netlist/OperationMethod.h"

VoltageControlledCurrentSource::VoltageControlledCurrentSource(std::string row, int i) :Component(voltageControlledCurrentSource) {

}

void VoltageControlledCurrentSource::stampG(double **Gmatrix, OperationMethod operationMethod) {

}

void VoltageControlledCurrentSource::stampSolutionVector(double *solutionVector) {

}

void VoltageControlledCurrentSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}
