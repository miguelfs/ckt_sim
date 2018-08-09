//
// Created by Miguel Sousa on 01/12/17.
//

#ifndef CKT_SIM_COMPONENT_H
#define CKT_SIM_COMPONENT_H

#include <string>
#include "ComponentType.h"
#include <string>

 class Component {
 public:

 private:
     Component_Type type;

 protected:
     int *nodes;
     char *name;

     void splitRow(int size, std::string row, std::string *arr);
 };

#endif //CKT_SIM_COMPONENT_H
