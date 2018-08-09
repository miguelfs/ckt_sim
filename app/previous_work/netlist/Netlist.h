//
// Created by Miguel Sousa on 01/12/17.
//

#ifndef CKT_SIM_NETLIST_H
#define CKT_SIM_NETLIST_H

#include <string>
#include "../components/Component.h"
#include "Transient.h"

class Netlist {
public:

    explicit Netlist(std::string);

private:
    Component* components;
public:
    Component *getComponents();

private:
    int numberOfNodes;
    Transient transient;

    void initializeTransient(std::string *text, int i);

    void initializeComponents(std::string *text, int i) const;
};


#endif //CKT_SIM_NETLIST_H