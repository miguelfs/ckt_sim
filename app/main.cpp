
#include <sstream>
#include <iostream>
#include "netlist/Netlist.h"

int main() {

    Netlist netlist = Netlist("/Users/miguel/Developer/CLionProjects/ckt_sim/arquivo.txt");
    netlist.doOperatingPointIfNeeded();

    for (double t = 0; t < netlist.getFinalTime();) {
        netlist.buildThatG();
        netlist.buildThatRHSVector();
        std::cout << "time to discover\n";
        //netlist.printGandRHS();

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