//
// Created by Miguel Sousa on 02/11/18.
//

#include "VoltageControlledVoltageSource.h"
#include "../netlist/OperationMethod.h"

VoltageControlledVoltageSource::VoltageControlledVoltageSource(std::string row, int i) : Component(voltageControlledVoltageSource) {

}

void VoltageControlledVoltageSource::stampG(double **Gmatrix, OperationMethod operationMethod) {

}

void VoltageControlledVoltageSource::stampSolutionVector(double *solutionVector) {

}

void VoltageControlledVoltageSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}
