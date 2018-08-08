#include <iostream>
#include "netlist/Netlist.h"

int main() {

    Netlist netlist = Netlist("/Users/miguel/Developer/CLionProjects/ckt_sim/arquivo.txt");
    netlist.getComponents();


    std::cout << "Hello, World!" << std::endl;
    return 0;
}