//
// Created by Miguel Sousa on 02/11/18.
//

#include "DCCurrentSource.h"
#include "../netlist/OperationMethod.h"
#include "SineWaveParameters.h"

DCCurrentSource::DCCurrentSource(std::string row, int quantityOfArguments) : Component(currentSource) {
      std::string arguments[quantityOfArguments];
      splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

      this->name = arguments[0];
      nodes[0] = stoi(arguments[1]);
      nodes[1] = stoi(arguments[2]);
      this->current = 0;
}

void DCCurrentSource::stampG(double **Gmatrix, OperationMethod operationMethod) {

}

void DCCurrentSource::stampSolutionVector(double *solutionVector) {

}

void DCCurrentSource::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod) {

      rightSideVector[nodes[0]] += -1.0 * current;
      rightSideVector[nodes[1]] += current;
}
