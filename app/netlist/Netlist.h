//
// Created by Miguel Sousa on 01/12/17.
//

#ifndef CKT_SIM_NETLIST_H
#define CKT_SIM_NETLIST_H

#include <string>
#include <vector>
#include "../components/Component.h"
#include "Transient.h"

class Netlist {
public:

    explicit Netlist(std::string);

    void buildThatG();

private:
    std::vector<Component> components;
    double** GMatrix;
    double* solutionsVector;
    double* rightSideVector;

public:
    Component *getComponents();
    void initializeGMatrix();

private:
    int quantityOfComponents;
    int quantityOfNodes;
    int quantityOfAuxiliarCurrents;
    int orderOfMatrixG;
    Transient transient;

 //   void setTransientParameters(std::string *text, int i);

    void initializeComponents(std::string *text, int i, double timeStep);

//    void generate_incidence_matrix(std::string *text_lines, int number_of_lines);
//
//    void checkIfAuxiliarEquationIsNeeded(Component component) const;
//
//    void checkIfAuxiliarEquationIsNeeded(Component_Type type) const;
//
//    bool isAuxiliarEquationNeeded(Component_Type type) const;

    bool isAuxiliarEquationNeeded(Component_Type type);

    void setTransient(const std::string *text, int numberOfLines);

    void printThatG();
};


#endif //CKT_SIM_NETLIST_H