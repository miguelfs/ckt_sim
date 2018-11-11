//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_CURRENTCONTROLLEDCURRENTSOURCE_H
#define CKT_SIM_CURRENTCONTROLLEDCURRENTSOURCE_H


#include "Component.h"

class CurrentControlledCurrentSource : public Component {

public:
    CurrentControlledCurrentSource(std::string row, int i);
};


#endif //CKT_SIM_CURRENTCONTROLLEDCURRENTSOURCE_H
