//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_RESISTOR_H
#define CKT_SIM_RESISTOR_H


#include "Component.h"

class Resistor: public Component{
public:
    Resistor(char*, int[]);

    explicit Resistor(std::string row);

    Resistor(char *name, int *nodes, double value);

    double value;
};


#endif //CKT_SIM_RESISTOR_H
