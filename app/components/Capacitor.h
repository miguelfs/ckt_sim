//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_CAPACITOR_H
#define CKT_SIM_CAPACITOR_H


#include "Component.h"

class Capacitor : public Component{

public:
    Capacitor(std::string row);
private:
    double value;
};


#endif //CKT_SIM_CAPACITOR_H
