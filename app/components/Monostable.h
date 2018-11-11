//
// Created by Miguel Sousa on 10/11/18.
//

#ifndef CKT_SIM_MONOSTABLE_H
#define CKT_SIM_MONOSTABLE_H


#include "Component.h"

class Monostable : public Component{
public:
    Monostable();

    Monostable(std::string row);

    Monostable(std::string row, int quantityOfArguments);
};


#endif //CKT_SIM_MONOSTABLE_H
