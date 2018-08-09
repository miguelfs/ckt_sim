//
// Created by Miguel Sousa on 01/12/17.
//

#include "Netlist.h"
#include "Row.h"
#include "../fileReader/FileReader.h"

Netlist::Netlist(std::string fileName)  {

    FileReader *fileReader = new FileReader(std::move(fileName));
    string *text = fileReader->getTextLines();
    int numberOfLines = fileReader->numberOfLines;
    this->numberOfNodes = (int) text[0].at(0);
    initializeComponents(text, numberOfLines);
    initializeTransient(text, numberOfLines);
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

