//
// Created by Miguel Sousa on 01/11/18.
//

#include <sstream>
#include <vector>
#include <stdexcept>
#include <iterator>
#include "Row.h"
#include "../components/Resistor.h"
#include "../components/Inductor.h"
#include "../components/Capacitor.h"
#include "../components/VoltageControlledVoltageSource.h"
#include "../components/VoltageControlledCurrentSource.h"
#include "../components/CurrentControlledCurrentSource.h"
#include "../components/CurrentControlledVoltageSource.h"
#include "../components/DCCurrentSource.h"
#include "../components/DCVoltageSource.h"
#include "../components/AmpOp.h"
#include "../components/SourceType.h"
#include "../components/PulseVoltageSource.h"
#include "../components/SineWaveCurrentSource.h"
#include "../components/SineWaveVoltageSource.h"
#include "../components/PulseCurrentSource.h"


Row::Row(std::string row) {
    this->stringRow = row;
}

Component * Row::getComponent(double timeStep, int wire) {

    switch (stringRow.at(0)) {
        case resistor:
            return new Resistor(stringRow, 4);
        case inductor:
            return new Inductor(stringRow, 5, timeStep, wire);
        case capacitor :
            return new Capacitor(stringRow, 5, timeStep);
        case voltageControlledVoltageSource:
            return new VoltageControlledVoltageSource(stringRow, 6, wire);
        case voltageControlledCurrentSource:
            return new VoltageControlledCurrentSource(stringRow, 6);
        case currentControlledCurrentSource:
            return new CurrentControlledCurrentSource(stringRow, 6, wire);
        case currentControlledVoltageSource :
            return new CurrentControlledVoltageSource(stringRow, 6, wire, wire + 1);
        case currentSource :
            return getCurrentSource(stringRow, wire);
            //   return new DCCurrentSource(stringRow, 4);
        case voltageSource :
            return getVoltageSource(stringRow, wire);
            //   return new DCVoltageSource(stringRow, 4, wire);
        case ampOp :
            return new AmpOp(stringRow, 5, wire);
//        case logicAnd:
//            return new LogicAnd(stringRow, 5);
//        case logicNand:
//            return new LogicNand(stringRow, 5);
//        case logicOr:
//            return new LogicOr(stringRow, 5);
//        case logicNor:
//            return new LogicNor(stringRow, 5);
//        case flipFlop:
//            return new FlipFlop(stringRow, 7);
//        case monostable:
//            return new Monostable(stringRow, 6);
//        case reset:
//            return new Reset(stringRow, 4);

        default: {
            throw std::invalid_argument( "Received invalid component:\n\n" + stringRow +
                                                 "\nPlease be sure your component belongs to ComponentType.h" );
        }


    }
}

Component *Row::getVoltageSource(std::string row, int wire) {
    int quantityOfArguments = 4;
    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, row, arguments);
    switch (arguments[3].at(0)) {
        case Pulse :
            return new PulseVoltageSource(row, 3 + 9, wire, 0);
        case dcSource :
            return new DCVoltageSource(row, 5, wire);
        case Sinusoidal :
            return new SineWaveVoltageSource(row, 3 + 8, wire);
        default: {
            throw std::invalid_argument("Received invalid voltage source :\n\n at row " +stringRow +
                                        "\nPlease be sure your component belongs to ComponentType.h");
        }
    }

}

Component *Row::getCurrentSource(std::string row, int wire) {
    int quantityOfArguments = 4;
    std::string arguments[quantityOfArguments];
    splitRow(quantityOfArguments, row, arguments);
    switch (arguments[3].at(0)) {
        case Pulse :
            return new PulseCurrentSource(row, 12, 0);
        case dcSource :
            return new DCCurrentSource(row, 5);
        case Sinusoidal :
            return new SineWaveCurrentSource(row, 11);
        default: {
            throw std::invalid_argument("Received invalid current source :\n\n" + stringRow +
                                        "\nPlease be sure your component belongs to ComponentType.h");
        }
    }
}

void Row::splitRow(int quantityOfArguments, string row, std::string *arguments) {


    std::istringstream iss(row);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());

    for (int i = 0; i < quantityOfArguments; i++) {
        arguments[i] = results[i];
    }
}
