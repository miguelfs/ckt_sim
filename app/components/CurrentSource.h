//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_CURRENTSOURCE_H
#define CKT_SIM_CURRENTSOURCE_H


#include "Component.h"

class CurrentSource : public Component{

public:
    CurrentSource(std::string row, int i);
};


#endif //CKT_SIM_CURRENTSOURCE_H
