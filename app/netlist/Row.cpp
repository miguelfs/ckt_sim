//
// Created by Miguel Sousa on 01/12/17.
//

#include "Row.h"
#include "../components/Resistor.h"
#include "../components/Inductor.h"
#include "../components/Capacitor.h"
#include "../components/VoltageControlledVoltageSource.h"
#include "../components/VoltageControlledCurrentSource.h"
#include "../components/CurrentControlledCurrentSource.h"
#include "../components/CurrentControlledVoltageSource.h"
#include "../components/CurrentSource.h"
#include "../components/VoltageSource.h"
#include "../components/AmpOp.h"

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
            return new VoltageControlledVoltageSource(stringRow, 6);
        case voltageControlledCurrentSource:
            return new VoltageControlledCurrentSource(stringRow, 6);
        case currentControlledCurrentSource:
            return new CurrentControlledCurrentSource(stringRow, 6);
        case currentControlledVoltageSource :
            return new CurrentControlledVoltageSource(stringRow, 6);
        case currentSource :
            return new CurrentSource(stringRow, 4);
        case voltageSource :
            return new VoltageSource(stringRow, 4);
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
