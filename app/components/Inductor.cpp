//
// Created by Miguel Sousa on 02/12/17.
//

#include "Inductor.h"
#include <iostream>

Inductor::Inductor(std::string row, int quantityOfArguments) : Component(inductor){
    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, std::move(row), arguments); //std::move to avoid unnecessary copies, only copy once

    this->name = arguments[0];
    nodes[0] = stoi(arguments[1]);
    nodes[1] = stoi(arguments[2]);
    inductance = strtod(arguments[3].c_str(), nullptr);
    initialCurrent = getInitialCurrent(arguments[4]);

//    std::cout << name << " " << nodes[0] << nodes[1] << " " << inductance << " " << initialCurrent << std::endl;
}
