//
// Created by Miguel Sousa on 02/11/18.
//

#include <sstream>
#include <vector>
#include "Transient.h"

Transient::Transient(std::string row, int quantityOfArguments) {
    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->finalTime = strtod(arguments[1].c_str(), nullptr);
    this->timeStep = strtod(arguments[2].c_str(), nullptr);
    this->stepsByTablePoint = stoi(arguments[4]);
    setInitialConfiguration(arguments[5]);
}

void Transient::splitRow(int quantityOfArguments, std::string row, std::string *arguments) {
    std::istringstream iss(row);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());

    for (int i = 0; i < quantityOfArguments; i++) {
        arguments[i] = results[i];
    }
}

void Transient::setInitialConfiguration(std::string argument) {
    if (argument == "UIC")
        initialConfig = initialConditions;
    else { initialConfig = operationPoint; }
}

Transient::Transient() {}

double Transient::getTimeStep() {
    return timeStep;
}

double Transient::getFinalTime() const {
    return finalTime;
}
