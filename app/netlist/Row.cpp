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
#include "../components/LinearResistorByParts.h"
#include "../components/Key.h"

Row::Row(std::string row) {
    this->stringRow = row;
}

Component * Row::getComponent() {

    switch (stringRow.at(0)) {
        case resistor:
            return new Resistor(stringRow);
        case inductor:
            return new Inductor(stringRow);
        case capacitor :
            return new Capacitor(stringRow);
        case voltageControlledVoltageSource:
            return new VoltageControlledVoltageSource(stringRow);
        case voltageControlledCurrentSource:
            return new VoltageControlledCurrentSource(stringRow);
        case currentControlledCurrentSource:
            return new CurrentControlledCurrentSource(stringRow);
        case currentControlledVoltageSource :
            return new CurrentControlledVoltageSource(stringRow);
        case currentSource :
            return new CurrentSource(stringRow);
        case voltageSource :
            return new VoltageSource(stringRow);
        case ampOp :
            return new AmpOp(stringRow);
        case linearResistorByParts:
            return new LinearResistorByParts(stringRow);
        case key:
            return new Key(stringRow);
        default: {
            throw std::invalid_argument( "Received invalid component:\n\n" + stringRow +
                                                 "\nPlease be sure your component belongs to ComponentType.h" );
        }


    }



}
