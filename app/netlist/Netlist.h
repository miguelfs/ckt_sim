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
    int** incidence_matrix;
public:
    Component *getComponents();

private:
    int quantityOfNodes;
    int quantityOfAuxiliarCurrents;
    int orderOfMatrixG;
    Transient transient;

 //   void setTransientParameters(std::string *text, int i);

    void initializeComponents(std::string *text, int i);

//    void generate_incidence_matrix(std::string *text_lines, int number_of_lines);
//
//    void checkIfAuxiliarEquationIsNeeded(Component component) const;
//
//    void checkIfAuxiliarEquationIsNeeded(Component_Type type) const;
//
//    bool isAuxiliarEquationNeeded(Component_Type type) const;

    bool isAuxiliarEquationNeeded(Component_Type type);
};


#endif //CKT_SIM_NETLIST_H