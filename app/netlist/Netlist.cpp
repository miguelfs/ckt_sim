//
// Created by Miguel Sousa on 01/11/18.
//

#include "Netlist.h"
#include "../fileReader/FileReader.h"
#include "../fileWriter/FileWriter.h"
#include "Row.h"
#include <iostream>
#include <sstream>

Netlist::Netlist(std::string fileName) : quantityOfAuxiliarCurrents(0), quantityOfComponents(0), systemOfEquations() {
    std::cout << "NOME DO ARQUIVO EH " << fileName << "!!!\n";

    FileReader *fileReader = new FileReader(fileName);

    string *text = fileReader->getTextLines();
    int numberOfLines = fileReader->numberOfLines;

    quantityOfNodes = fileReader->getNumberOfNodes();

    setTransient(text, numberOfLines);
    initializeComponents(text, numberOfLines, this->transient.getTimeStep());

    systemOfEquations.setOrderOfMatrixG(quantityOfNodes + quantityOfAuxiliarCurrents + 1);
    systemOfEquations.initializeGMatrix();
    systemOfEquations.initializeSolutionsVector();
    systemOfEquations.initializeRSVector();

    this->fileWriter = new FileWriter(fileName);
    this->fileWriter->setHeaderRow(components, quantityOfComponents, quantityOfNodes,
                                   quantityOfAuxiliarCurrents);

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
        std::cout << "linha " << i << " = " << text[i] << "\n";
        Row row(text[i]);
        Component *component = row.getComponent(timeStep, quantityOfNodes + quantityOfAuxiliarCurrents + 1);
        components.push_back(component);
        quantityOfComponents++;

        if (isAuxiliarEquationNeeded(components[j]->getComponentType()))
            quantityOfAuxiliarCurrents++;

        if (components[j]->getComponentType() == currentControlledVoltageSource)
            quantityOfAuxiliarCurrents++;

        if (components[j]->doesHaveInitialCondition())
            systemOfEquations.setOperationMethod(initialConditions);
        else
            systemOfEquations.setOperationMethod(operatingPoint);

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

void Netlist::buildThatRHSVector(double time) {
    systemOfEquations.buildThatRSVector(quantityOfComponents, components, time);
}

void Netlist::doOperatingPointIfNeeded() {

}

void Netlist::solveSystem() {
    systemOfEquations.solveSystem();
}

void Netlist::updateReactiveValues() {
    for (int index = 0; index < quantityOfComponents; index++) {
        if (components[index]->getComponentType() == inductor ||
            components[index]->getComponentType() == capacitor) {
            components[index]->setValue(systemOfEquations.getSolutionVector());
        }
    }
}

double Netlist::getFinalTime() {
    return transient.getFinalTime();
}

double Netlist::getTimeStep() {
    return transient.getTimeStep();
}

void Netlist::writeSolutionOnFile(double time) {
    std::stringstream ss;
    ss << time << " ";
    for (int i = 1; i < systemOfEquations.getOrderOfMatrixG(); i++) {
        ss << systemOfEquations.getSolutionVector()[i] << " ";
    }
    fileWriter->writeRow(ss.str());
}

void Netlist::clearThatG() {
    systemOfEquations.clearThatG();

}

void Netlist::clearThatRHSVector() {
    systemOfEquations.clearThatRHSVector();
}

void Netlist::clearThatSolutionVector() {
    systemOfEquations.clearThatSolutionVector();
}

void Netlist::printGandRHS() {
    systemOfEquations.printThatG();
    systemOfEquations.printThatRHS();
}

std::string Netlist::getWrittenFileName() {
    return fileWriter->getFileName();
}

void Netlist::writeInitialConditionsIfNeeded() {
 //   if (systemOfEquations.getOperationMethod() == initialConditions
}

OperationMethod  Netlist::getOperationMethod(){
    return systemOfEquations.getOperationMethod();
}

void Netlist::buildFirstIteraction() {
    if (systemOfEquations.getOperationMethod() == initialConditions)

}

void Netlist::solveAndWrite(double t) {
    buildThatG(transient);
    buildThatRHSVector(t);

    solveSystem();

    writeSolutionOnFile(t);
    updateReactiveValues();

    clearThatG();
    clearThatRHSVector();
    clearThatSolutionVector();
}
