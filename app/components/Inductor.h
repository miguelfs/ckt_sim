//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_INDUCTOR_H
#define CKT_SIM_INDUCTOR_H


#include "Component.h"

class Inductor : public Component{

public:
    Inductor(std::string row, int i);

private:
    double inductance;
    int nodes[2];
    double initialCurrent;
};


#endif //CKT_SIM_INDUCTOR_H
