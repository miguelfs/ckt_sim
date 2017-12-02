//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_FILEREADER_H
#define CKT_SIM_FILEREADER_H

#include <string>
using namespace std;

class FileReader {

public:
    explicit FileReader(string);
    string *getTextLines();

private:
    string textLines[];
};


#endif //CKT_SIM_FILEREADER_H
