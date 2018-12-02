
#include <sstream>
#include <iostream>
#include "netlist/Netlist.h"
#include "fileReader/FileReader.h"

int main() {

    FileReader *fileReader = new FileReader("/Users/miguel/Developer/CLionProjects/ckt_sim/inputName.txt");

    string *text = fileReader->getTextLines();
    const string filepath = "/Users/miguel/Developer/CLionProjects/ckt_sim/input/" + text[0];

    Netlist netlist = Netlist(filepath);
    netlist.doOperatingPointIfNeeded();

    for (double t = 0; t < netlist.getFinalTime();) {
        netlist.buildThatG();
        netlist.buildThatRHSVector();
        std::cout << "time to discover\n";

        netlist.solveSystem();

        netlist.writeSolutionOnFile(t);
        netlist.updateReactiveValues();

        netlist.clearThatG();
        netlist.clearThatRHSVector();
        netlist.clearThatSolutionVector();

        t += netlist.getTimeStep();
    }
    return 0;
}