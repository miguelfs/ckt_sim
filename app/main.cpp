
#include <sstream>
#include "netlist/Netlist.h"

int main() {

    Netlist netlist = Netlist("/Users/miguel/Developer/CLionProjects/ckt_sim/arquivo.txt");
    netlist.buildThatG();
  //  netlist.getComponents();

    return 0;
}