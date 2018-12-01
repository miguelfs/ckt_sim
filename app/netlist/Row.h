//
// Created by Miguel Sousa on 01/11/18.
//

#ifndef CKT_SIM_ROW_H
#define CKT_SIM_ROW_H

#include <string>
#include "../components/Component.h"
#include "../components/Resistor.h"

class Row {
public:
    Row(std::string);
    Component *getComponent(double timeStep, int wire);

private:
    std::string stringRow;

    Component *getVoltageSource(std::string row, int wire);

    Component *getCurrentSource(std::string row, int wire);

    void splitRow(int quantityOfArguments, std::string row, std::string *arguments);
};


#endif //CKT_SIM_ROW_H
