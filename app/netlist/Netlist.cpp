//
// Created by Miguel Sousa on 01/12/17.
//

#include "Netlist.h"
#include "../fileReader/FileReader.h"
#include "Row.h"
#include <iostream>

Netlist::Netlist(std::string fileName)  {

    FileReader *fileReader = new FileReader(std::move(fileName));
    string *text = fileReader->getTextLines();
    int numberOfLines = fileReader->numberOfLines;
    initializeComponents(text, numberOfLines);
}

void Netlist::initializeComponents(std::string *text, int numberOfLines) const {
    int j = 0;
    for (int i = 1; i < numberOfLines - 1; i++){
        Row row(text[i]);
        components[j] = *row.getComponent();
        j++;
    }
}


void Netlist::initializeTransient(std::string *text, int numberOfLines) {
    if(text[numberOfLines - 1].at(0) == '.'){
        transient = * new Transient(text[sizeof(text) - 1]);
    }
}


Component *Netlist::getComponents() {
    return components;
}

void Netlist::generate_incidence_matrix(std::string *text_lines, int number_of_lines) {

}

