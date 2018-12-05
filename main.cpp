
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

    for (double t = 0; t < netlist.getFinalTime();) {
        netlist.buildThatG();
        netlist.buildThatRHSVector(t);

        netlist.solveSystem();

        netlist.writeSolutionOnFile(t);
        netlist.updateReactiveValues();

        netlist.clearThatG();
        netlist.clearThatRHSVector();
        netlist.clearThatSolutionVector();

        t += netlist.getTimeStep();
    }
    cout << '\n' << "transient table located on " << netlist.getWrittenFileName();
    cout << '\n' << "Press ENTER twice to close...";
    getchar();
    return 0;
}