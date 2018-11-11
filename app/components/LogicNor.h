//
// Created by Miguel Sousa on 10/11/18.
//

#ifndef CKT_SIM_LOGICNOR_H
#define CKT_SIM_LOGICNOR_H


#include "Component.h"

class LogicNor: public Component {
public:
    LogicNor();

    LogicNor(std::string row);

    LogicNor(std::string row, int quantityOfArguments);
};


#endif //CKT_SIM_LOGICNOR_H
