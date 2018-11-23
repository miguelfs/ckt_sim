//
// Created by Miguel Sousa on 02/12/17.
//

#include "VoltageControlledCurrentSource.h"
#include "../netlist/OperationMethod.h"

VoltageControlledCurrentSource::VoltageControlledCurrentSource(std::string row, int i) :Component(voltageControlledCurrentSource) {

}

void VoltageControlledCurrentSource::stampG(double **Gmatrix) {

}

void VoltageControlledCurrentSource::stampSolutionVector(double *solutionVector) {

}

void VoltageControlledCurrentSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}
