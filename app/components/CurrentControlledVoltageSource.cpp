//
// Created by Miguel Sousa on 02/11/18.
//

#include "CurrentControlledVoltageSource.h"
#include "../netlist/OperationMethod.h"

CurrentControlledVoltageSource::CurrentControlledVoltageSource(std::string row, int i) : Component(currentControlledVoltageSource){

}

void CurrentControlledVoltageSource::stampG(double **Gmatrix, OperationMethod operationMethod) {

}

void CurrentControlledVoltageSource::stampSolutionVector(double *solutionVector) {

}

void CurrentControlledVoltageSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}
