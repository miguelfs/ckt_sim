//
// Created by Miguel Sousa on 01/12/18.
//

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "FileWriter.h"
#include "../components/Component.h"

using namespace std;


void FileWriter::writeRow(std::string row) {
    fstream file;

    // If file does not exist, Create new file
    if (!fileExists(fileName)) {
        file.open(this->fileName, std::fstream::in | std::fstream::out | std::fstream::app);
        file << this->headerRow << "\n";
        file << row << "\n";
        file.close();
    } else {    // use existing file
        file.open(this->fileName, std::fstream::in | std::fstream::out | std::fstream::app);
        file << row << "\n";
        file.close();
    }
}

FileWriter::FileWriter(string fileName) {
    std::stringstream ss;
    std::string substring = fileName.substr(0, fileName.find_last_of('.'));
    std::cout << "arquivin = 2" << substring << std::endl;

    ss << substring  << "_cktsim" << ".tab";
    this->fileName = ss.str();
    std::cout << "arquivin 3 = " << this->fileName<< std::endl;

    if (remove(this->fileName.c_str()) != 0)
        cout << "Error deleting file\n";
    else
        cout << "File successfully deleted\n";
}

bool FileWriter::is_empty(std::ifstream &pFile) {
    return pFile.peek() == std::ifstream::traits_type::eof();
}

bool FileWriter::fileExists(std::string name) {
    ifstream f(name.c_str());
    return f.good();
}

void FileWriter::setHeaderRow(std::vector<Component *> components, int quantityOfComponents, int quantityOfNodes,
                              int quantityOfCurrents) {
    std::stringstream ss;
    ss << "t ";
    for (int i = 1; i < quantityOfNodes + 1; i++) {
        ss << i << " ";
    }
    for (int i = 0; i < quantityOfComponents; i++) {
        if (isOneCurrentNeeded(components[i]->getComponentType()))
            ss << "j" << components[i]->getName() << " ";

        if (areTwoCurrentsNeeded(components[i]->getComponentType()))
            ss << "jx" << components[i]->getName() << " " << "jy" << components[i]->getName() << " ";
    }
    this->headerRow = ss.str();
}

bool FileWriter::isOneCurrentNeeded(Component_Type type) {
    return type == inductor || type == ampOp || type == voltageSource || type == voltageControlledVoltageSource ||
           type == currentControlledCurrentSource || type == currentControlledVoltageSource;
}

bool FileWriter::areTwoCurrentsNeeded(Component_Type type) {
    return type == currentControlledVoltageSource;
}

const string &FileWriter::getFileName() const {
    return fileName;
}

