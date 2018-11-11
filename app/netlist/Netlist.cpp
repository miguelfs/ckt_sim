//
// Created by Miguel Sousa on 01/12/17.
//

#include "Netlist.h"
#include "../fileReader/FileReader.h"
#include "Row.h"
#include <iostream>

Netlist::Netlist(std::string fileName)  {
    quantityOfAuxiliarCurrents = 0;
    FileReader *fileReader = new FileReader(std::move(fileName));
    string *text = fileReader->getTextLines();
    int numberOfLines = fileReader->numberOfLines;
    initializeComponents(text, numberOfLines);
    quantityOfNodes = fileReader->getNumberOfNodes();
    orderOfMatrixG = quantityOfNodes + quantityOfAuxiliarCurrents;

    if(text[numberOfLines - 1].compare(".TRAN")){
        transient = Transient(text[numberOfLines - 1], 6);
    }
}

void Netlist::initializeComponents(std::string *text, int numberOfLines) {
    components = new Component[numberOfLines - 1];
    int j = 0;
    for (int i = 1; i < numberOfLines - 1; i++){
        Row row(text[i]);
        components[j] = *row.getComponent();

        if (isAuxiliarEquationNeeded(components[j].getComponentType())){
            quantityOfAuxiliarCurrents++;
        } //auxiliar current equation for ampOps, inductors and voltage source
        j++;
    }
}

Component *Netlist::getComponents() {
    return components;
}

bool Netlist::isAuxiliarEquationNeeded(Component_Type type)  {
    return type == inductor || type == ampOp || type == voltageSource || type == voltageControlledVoltageSource ||
            type == currentControlledCurrentSource || type == currentControlledVoltageSource;
}


//void Netlist::generate_incidence_matrix(std::string *text_lines, int number_of_lines) {
//
//}
