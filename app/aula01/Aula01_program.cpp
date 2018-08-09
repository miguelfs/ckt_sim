//
// Created by Miguel on 08/08/2018.
//

#include "Aula01_program.h"
#include "../previous_work/fileReader/FileReader.h"
#include <fstream>
#include <iostream>
#include <stdio.h>

Aula01_program::Aula01_program(string netlist_filename) {


    FileReader *fileReader = new FileReader(std::move(netlist_filename));
    std::cout << fileReader->getTextLines()[2] << std::endl;
    }
