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
    linearResistorByParts = 'N',
    idealTransformer = 'K',
    key = '$'
};
#endif //CKT_SIM_COMPONENTTYPE_H
