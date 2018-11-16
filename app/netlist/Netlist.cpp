//
// Created by Miguel Sousa on 01/12/17.
//

#include "Netlist.h"
#include "../fileReader/FileReader.h"
#include "Row.h"
#include <iostream>

Netlist::Netlist(std::string fileName) : quantityOfAuxiliarCurrents(0), quantityOfComponents(0) {
    FileReader *fileReader = new FileReader(std::move(fileName));
    string *text = fileReader->getTextLines();
    int numberOfLines = fileReader->numberOfLines;

    quantityOfNodes = fileReader->getNumberOfNodes();

    setTransient(text, numberOfLines);
    initializeComponents(text, numberOfLines, 0);

    orderOfMatrixG = quantityOfNodes + quantityOfAuxiliarCurrents;
    //quantity of auxiliar currents is set in initializeComponents method
    initializeGMatrix();
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
        Component component = * row.getComponent(timeStep, quantityOfNodes + quantityOfAuxiliarCurrents + 1);
        components.push_back(component);
        quantityOfComponents++;
        if (isAuxiliarEquationNeeded(components[j].getComponentType())) {
            quantityOfAuxiliarCurrents++;
        } //auxiliar current equation for ampOps, inductors and voltage source
        j++;
    }
}

bool Netlist::isAuxiliarEquationNeeded(Component_Type type) {
    return type == inductor || type == ampOp || type == voltageSource || type == voltageControlledVoltageSource ||
           type == currentControlledCurrentSource || type == currentControlledVoltageSource;
}

void Netlist::initializeGMatrix() {
    GMatrix = (double **) malloc(orderOfMatrixG * sizeof(double *));
    for (int i = 0; i < orderOfMatrixG; i++)
        GMatrix[i] = (double *) malloc(orderOfMatrixG * sizeof(double));


    for (int i = 0; i < orderOfMatrixG; i++)
        for (int j = 0; j < orderOfMatrixG; j++)
            GMatrix[i][j] = 0.0;

  //  printThatG();
}


void ::Netlist::buildThatG() {
    for (int i = 0; i < quantityOfComponents; i++)
        components[i].stampG(GMatrix);

    printThatG();
}

void ::Netlist::printThatG() {
    for (int i = 0; i < orderOfMatrixG; i++) {
        std::cout << "[ ";
        for (int j = 0; j < orderOfMatrixG; j++)
            std::cout << GMatrix[i][j] << " ";
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}


//void Netlist::generate_incidence_matrix(std::string *text_lines, int number_of_lines) {
//
//}
