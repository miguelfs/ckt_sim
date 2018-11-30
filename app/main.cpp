
#include <sstream>
#include "netlist/Netlist.h"

int main() {

    Netlist netlist = Netlist("/Users/miguel/Developer/CLionProjects/ckt_sim/arquivo.txt");
    netlist.doOperatingPointIfNeeded();
    netlist.buildThatG();
    netlist.buildThatRSVector();
    netlist.solveSystem();

    return 0;
}