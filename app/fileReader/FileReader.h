//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_FILEREADER_H
#define CKT_SIM_FILEREADER_H

#include <string>
#include <fstream>

using namespace std;

class FileReader {

public:

     FileReader(string);

    int getNumberOfNodes();

    string *getTextLines();

    int numberOfLines;
private:
    string* textLines;

    int getNumberOfLines(ifstream);

    int getNumberOfLines(string fileName);

};


#endif //CKT_SIM_FILEREADER_H
