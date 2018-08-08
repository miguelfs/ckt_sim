//
// Created by Miguel Sousa on 02/12/17.
//

#include <sstream>
#include <vector>
#include "Resistor.h"

Resistor::Resistor(char * name, int nodes[], double value) {
    this->nodes = nodes;
    this->name = name;
    this->value = value;
}

Resistor::Resistor(std::string row) {
    std::string arguments[4];
    splitRow(4, std::move(row), arguments);
//    name = const_cast<char *>(arguments[1].c_str());
    int array[2] = {atoi(arguments[1].c_str()), atoi(arguments[2].c_str())};
 //   Resistor(const_cast<char *>(arguments[0].c_str()), array, atof(arguments[3].c_str()));
    name = const_cast<char *>(arguments[0].c_str());
    nodes = array;
    value = atof(arguments[3].c_str());
}