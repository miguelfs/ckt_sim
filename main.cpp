
#include <sstream>
#include <iostream>
#include "app/netlist/Netlist.h"
#include "app/fileReader/FileReader.h"

//I'm using both OS, folder paths changes depending on OS
enum DevOS{
    macOS,
    windowsOS
};

//When giving the program to Moreirão, it's easier for him to manipule all the files in the same folder
enum PathForExeProgram{
    projectRootFolder,
    buildRelaseOrDebugFolder
};

int main() {
    DevOS myOS = windowsOS;
    PathForExeProgram pathForExe = buildRelaseOrDebugFolder;

    std::string filename;
    cout << "\nWelcome to ckt_sim: circuit simulator. Developed by Miguel de Sousa and Pedro Gil, 2018."<< endl;
    cout << "\nPlease enter the netlist file name, case-sensitive.  Ex: tanqueLC.net, blumlein.net, etc..." << endl;
  //  cout << "The file must be located INSIDE input/ folder.\n" << endl;
    cout << "The file must be located in the SAME directory as this .exe\n" << endl;
    cin >> filename;

    std::string filepath = filename;
    if (myOS == macOS || (myOS == windowsOS && pathForExe == projectRootFolder))
        filepath = filename;
    if (myOS == windowsOS && pathForExe == buildRelaseOrDebugFolder)
        filepath = "../" + filename;

    Netlist netlist = Netlist(filepath);

    netlist.buildFirstIteraction();
    std::cout << "resolvendo sistema..." << std::endl;
    int counter = 0;
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
        counter++;
        if ((counter % 1000) == 0)
            cout<<"instante t = " << t << "..." << endl;
    }
    cout << '\n' << "transientResponse table located on " << netlist.getWrittenFileName();
    cout << '\n' << "Press ENTER once to close...";
    getchar();
    getchar();

    return 0;
}