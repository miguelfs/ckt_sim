//
// Created by Miguel Sousa on 01/11/18.
//

#ifndef CKT_SIM_NETLIST_H
#define CKT_SIM_NETLIST_H

#include <string>
#include <vector>
#include "../components/Component.h"
#include "Transient.h"
#include "SystemOfEquations.h"
#include "../fileWriter/FileWriter.h"

class Netlist {
public:

    explicit Netlist(std::string);

    void buildThatG(OperationMethod operationMethod);

    void buildThatRHSVector(double time, OperationMethod operationMethod);

    void solveSystem();

    void updateReactiveValues();

    double getFinalTime();

    double getTimeStep();

    void writeSolutionOnFile(double time);

    void clearThatG();

    void clearThatRHSVector();

    void clearThatSolutionVector();

    std::string getWrittenFileName();

    void buildFirstIteraction();

private:
    std::vector<Component *> components;
    double** GMatrix;
    double* rightSideVector;
    SystemOfEquations systemOfEquations;
    int quantityOfComponents;
    int quantityOfNodes;
    int quantityOfAuxiliarCurrents;
    Transient transient;

    void initializeComponents(std::string *text, int i, double timeStep);

    bool isAuxiliarEquationNeeded(Component_Type type);

    void setTransient(const std::string *text, int numberOfLines);

    FileWriter *fileWriter;
};


#endif //CKT_SIM_NETLIST_H