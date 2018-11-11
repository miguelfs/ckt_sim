//
// Created by Miguel Sousa on 10/11/18.
//

#ifndef CKT_SIM_LOGICOR_H
#define CKT_SIM_LOGICOR_H


#include "Component.h"

class LogicOr : public Component{
public:
    LogicOr();

    LogicOr(std::string row);

    LogicOr(std::string row, int quantityOfNodes);
};


#endif //CKT_SIM_LOGICOR_H
