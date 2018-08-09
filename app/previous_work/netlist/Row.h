//
// Created by Miguel Sousa on 01/12/17.
//

#ifndef CKT_SIM_ROW_H
#define CKT_SIM_ROW_H

#include <string>
#include "../components/Component.h"
#include "../components/Resistor.h"

class Row {
public:
    Row(std::string);
    Component * getComponent();

private:
    std::string stringRow;
};


#endif //CKT_SIM_ROW_H
