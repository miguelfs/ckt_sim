
#include <sstream>
#include <iostream>
#include "app/netlist/Netlist.h"
#include "app/fileReader/FileReader.h"

int main() {

    FileReader *fileReader = new FileReader("../inputName.txt");

    std::string *text = fileReader->getTextLines();
    std::string filepath = "../input/" + string(text[0]);

    Netlist netlist = Netlist(filepath);

    netlist.buildFirstIteraction();

    for (double t = netlist.getTimeStep(); t <= netlist.getFinalTime();) {
        netlist.buildThatG(transientResponse);
        netlist.buildThatRHSVector(t, initialConditions);

        netlist.solveSystem();

        netlist.writeSolutionOnFile(t);
        netlist.updateReactiveValues();

        netlist.clearThatG();
        netlist.clearThatRHSVector();
        netlist.clearThatSolutionVector();

        t += netlist.getTimeStep();
    }
    cout << '\n' << "transientResponse table located on " << netlist.getWrittenFileName();
    cout << '\n' << "Press ENTER once to close...";
    getchar();
    return 0;
}