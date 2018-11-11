//
// Created by Miguel Sousa on 02/12/17.
//

#include <sstream>
#include <vector>
#include "Resistor.h"


Resistor::Resistor(std::string row, int quantityOfArguments) : Component(resistor) {

    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, row, arguments);
    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    resistance = atof(arguments[3].c_str());
}
