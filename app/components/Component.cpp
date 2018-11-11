//
// Created by Miguel Sousa on 01/12/17.
//

#include <sstream>
#include <vector>
#include "Component.h"

using namespace std;



void Component::splitRow(int quantityOfArguments, string row, std::string* arguments) {


    std::istringstream iss(row);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());

    for (int i = 0; i < quantityOfArguments; i++){
        arguments[i] = results [i];
    }



}

double Component::getInitialCurrent(std::string initialCurrent){
    if (initialCurrent.length() > 0)
        return  strtod(initialCurrent.erase(0, 3).c_str(), nullptr);
    return 0;
}

Component_Type Component::getComponentType() const {
    return type;
}

Component::Component(Component_Type type) {
    this->type = type;
}

Component::Component() {
}

