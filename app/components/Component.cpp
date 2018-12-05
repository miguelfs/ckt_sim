//
// Created by Miguel Sousa on 01/11/18.
//

#include <sstream>
#include <vector>
#include <iostream>
#include <iterator>
#include "Component.h"
#include "../netlist/OperationMethod.h"

using namespace std;



void Component::splitRow(int quantityOfArguments, string row, std::string* arguments) {


    std::istringstream iss(row);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());

    for (int i = 0; i < results.size(); i++){
            arguments[i] = results[i];
    }
}

double Component::getInitialCondition(std::string initialCondition) {
    if (getComponentType() != capacitor && getComponentType() != inductor)
        return 0;
    if (initialCondition.length() > 0)
        return strtod(initialCondition.erase(0, 3).c_str(), nullptr);
    return 0;
}

//function overwritten in capacitor and inductor
bool Component::doesHaveInitialCondition() {
    return false;
}


void Component::GstampFor2x2Component(double **G, double stamp[2][2], int *nodes){

    G[nodes[0]][nodes[0]] += stamp[0][0];
    G[nodes[0]][nodes[1]] += stamp[0][1];
    G[nodes[1]][nodes[0]] += stamp[1][0];
    G[nodes[1]][nodes[1]] += stamp[1][1];
}

Component_Type Component::getComponentType() const {
    return type;
}

Component::Component(Component_Type type) {
    this->type = type;
}

Component::Component() {
}


void Component::stampSolutionVector(double *solutionVector) {

}

void Component::stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time) {

}

void Component::stampG(double **G, OperationMethod operationMethod) {
}

double Component::parse(string word) {
    return strtod(word.c_str(), nullptr);
}

void Component::setValue(double *SolutionVector) {
}

const string &Component::getName() const {
    return name;
}



