//
// Created by Miguel Sousa on 01/12/17.
//

#ifndef CKT_SIM_COMPONENTTYPE_H
#define CKT_SIM_COMPONENTTYPE_H
enum Component_Type {
    resistor = 'R',
    inductor = 'L',
    capacitor = 'C',
    voltageControlledVoltageSource = 'E',
    voltageControlledCurrentSource = 'F',
    currentControlledCurrentSource = 'G',
    currentControlledVoltageSource = 'H',
    currentSource = 'I',
    voltageSource = 'V',
    ampOp = 'O',
    logicAnd = ')',
    logicNand = '(',
    logicOr = '}',
    logicNor = '{',
    flipFlop = '%',
    monostable = '@',
    reset = '!'
};
// commentary in the netlist starts with *, but since its not a component, it will not be described in this enum
#endif //CKT_SIM_COMPONENTTYPE_H
