//
// Created by Miguel Sousa on 02/11/18.
//

#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <conio.h>

FileReader::FileReader(string fileName) {

    int numberOfLines = getNumberOfLines(fileName);
    textLines = new string[numberOfLines];
    std::cout << "file name is = " << fileName << "\n";
    ifstream in(fileName);

    if (!in) {
        cerr<< "Could not open netlist " << fileName <<
        "\nCheck if the file you've written here is located in the INPUT folder.\n" <<
        "press ENTER to exit..." << std::endl;
        getch();
        exit(0);
    }

    int i = 0;
    for( std::string line; getline( in, line ); )
    {
        textLines[i] = line;
        i++;
    }
}

int FileReader::getNumberOfLines(string fileName) {

    ifstream in(fileName);
    int numberOfLines= 0;
    for(string line; getline(in, line ); ) {
        numberOfLines++;
    }
    this->numberOfLines = numberOfLines;
    return numberOfLines;
}

string* FileReader::getTextLines() {
    return textLines;
}

int FileReader::getNumberOfNodes() {
    int numberOfNodes = 0;
    try {
        numberOfNodes = std::stoi(textLines[0]);
    }
    catch (std::invalid_argument& error)
    {
        cout << "ERRO AO LER QUANTIDADE DE NÓS DO NETLIST, ARGUMENTO INVALIDO " << endl;
        throw(error);
    }
    return numberOfNodes;
}
