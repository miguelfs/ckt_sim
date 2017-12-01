//
// Created by Miguel Sousa on 01/12/17.
//

#ifndef CKT_SIM_COMPONENTTYPE_H
#define CKT_SIM_COMPONENTTYPE_H
enum Component_Type {
    Resistor = 'R',
    Inductor = 'L',
    Capacitor = 'G',
    VoltageControlledVoltageSource = 'E',
    VoltageControlledCurrentSource = 'F',
    CurrentControlledCurrentSource = 'G',
    CurrentControlledVoltageSource = 'H',
    CurrentSource = 'I',
    VoltageSource = 'V',
    AmpOp = 'O',
    LinearResistorByParts = 'N',
    IdealTransformer = 'K',
    Key = '$'
};
#endif //CKT_SIM_COMPONENTTYPE_H
