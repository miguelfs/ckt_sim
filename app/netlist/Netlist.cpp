//
// Created by Miguel Sousa on 01/11/18.
//

#include "Netlist.h"
#include "../fileReader/FileReader.h"
#include "Row.h"
#include <iostream>

Netlist::Netlist(std::string fileName) : quantityOfAuxiliarCurrents(0), quantityOfComponents(0), systemOfEquations() {
    FileReader *fileReader = new FileReader(std::move(fileName));
    string *text = fileReader->getTextLines();
    int numberOfLines = fileReader->numberOfLines;

    quantityOfNodes = fileReader->getNumberOfNodes();

    setTransient(text, numberOfLines);
    initializeComponents(text, numberOfLines, this->transient.getTimeStep());

    systemOfEquations.setOrderOfMatrixG(quantityOfNodes + quantityOfAuxiliarCurrents + 1);
    systemOfEquations.initializeGMatrix();
    systemOfEquations.initializeSolutionsVector();
    systemOfEquations.initializeRSVector();
}

void Netlist::setTransient(const string *text, int numberOfLines) {
    if (text[numberOfLines - 1].compare(".TRAN")) {
        transient = Transient(text[numberOfLines - 1], 6);
    }
}

void Netlist::initializeComponents(std::string *text, int numberOfLines, double timeStep) {
   // components.resize(static_cast<unsigned long>(numberOfLines - 1));
    int j = 0;
    for (int i = 1; i < numberOfLines - 1; i++) {
        Row row(text[i]);
        Component *component = row.getComponent(timeStep, quantityOfNodes + quantityOfAuxiliarCurrents + 1);
        components.push_back(component);
        quantityOfComponents++;

        if (isAuxiliarEquationNeeded(components[j]->getComponentType()))
            quantityOfAuxiliarCurrents++;

        if (components[j]->doesHaveInitialCondition())
            systemOfEquations.isOperatingPointNeeded(false);

        j++;
    }
}

bool Netlist::isAuxiliarEquationNeeded(Component_Type type) {
    return type == inductor || type == ampOp || type == voltageSource || type == voltageControlledVoltageSource ||
           type == currentControlledCurrentSource || type == currentControlledVoltageSource;
}

void ::Netlist::buildThatG() {
    systemOfEquations.buildThatG(quantityOfComponents, components);
}

void Netlist::buildThatRSVector() {
    systemOfEquations.buildThatRSVector(quantityOfComponents, components);
}

void Netlist::doOperatingPointIfNeeded() {

}

void Netlist::solveSystem() {
    systemOfEquations.solveSystem();
}
