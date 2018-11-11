//
// Created by Miguel Sousa on 01/12/17.
//

#ifndef CKT_SIM_COMPONENT_H
#define CKT_SIM_COMPONENT_H

#include <string>
#include "ComponentType.h"

 class Component {
 public:


 private:
     Component_Type type;
 public:
     Component_Type getComponentType() const;
     Component();

 protected:
     int *nodes;
     std::string name;

     void splitRow(int size, std::string row, std::string *arr);
     double getInitialCurrent(std::string initialCurrent);

     Component(Component_Type type);
 };

#endif //CKT_SIM_COMPONENT_H
