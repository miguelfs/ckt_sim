//
// Created by Miguel Sousa on 02/12/17.
//

#include "CurrentControlledVoltageSource.h"
#include "../netlist/OperationMethod.h"

CurrentControlledVoltageSource::CurrentControlledVoltageSource(std::string row, int i) : Component(currentControlledVoltageSource){

}

void CurrentControlledVoltageSource::stampG(double **Gmatrix) {

}

void CurrentControlledVoltageSource::stampSolutionVector(double *solutionVector) {

}

void CurrentControlledVoltageSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

}
