//
// Created by Miguel Sousa on 02/12/17.
//

#include "FileReader.h"
#include <fstream>
#include <iostream>


FileReader::FileReader(string fileName) {

    int numberOfLines = getNumberOfLines(fileName);
    textLines = new string[numberOfLines];
    ifstream in(fileName);

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
