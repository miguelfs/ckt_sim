//
// Created by Miguel Sousa on 10/11/18.
//

#ifndef CKT_SIM_RESET_H
#define CKT_SIM_RESET_H


#include "Component.h"

class Reset : public Component{
public:
    Reset();

    Reset(std::string row);

    Reset(std::string row, int quantityOfArguments);
};


#endif //CKT_SIM_RESET_H
