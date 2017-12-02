//
// Created by Miguel Sousa on 02/12/17.
//

#include "FileReader.h"
#include <fstream>
#include <iostream>

FileReader::FileReader(string fileName) {

    ifstream is(fileName);
    string str;
    int i = 0;
    while(getline(is, str))
    {
        cout<<str<<endl;
        textLines[i] = str;
    }
}

string* FileReader::getTextLines() {
    return textLines;
}
