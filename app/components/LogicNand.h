//
// Created by Miguel Sousa on 10/11/18.
//

#ifndef CKT_SIM_LOGICNAND_H
#define CKT_SIM_LOGICNAND_H


#include "Component.h"

class LogicNand : public Component{
public:
    LogicNand();

    LogicNand(std::string row);

    LogicNand(std::string basic_string, int quantityOfNodes);
};


#endif //CKT_SIM_LOGICNAND_H
