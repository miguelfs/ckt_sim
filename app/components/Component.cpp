//
// Created by Miguel Sousa on 01/12/17.
//

#include <sstream>
#include <vector>
#include "Component.h"

using namespace std;



void Component::splitRow(int size, string row, std::string * arr) {

    int i = 0;
    stringstream ssin(row);
    while (ssin.good() && i < size){
        ssin >> arr[i];
        ++i;
    }
}
