//
// Created by Miguel Sousa on 01/12/17.
//

#ifndef CKT_SIM_COMPONENT_H
#define CKT_SIM_COMPONENT_H

#include "ComponentType.h"

class Component {
public:
    Component(Component_Type);

private:
    Component_Type type;
    char* name;
    int nodes[];

};


#endif //CKT_SIM_COMPONENT_H
