//
// Created by Miguel Sousa on 02/12/17.
//

#ifndef CKT_SIM_SOURCETYPE_H
#define CKT_SIM_SOURCETYPE_H

#include <string>
using namespace std;

enum SourceType {
    DC,
    Sinusoidal,
    Pulse
};

static const char * SourceTypeValue[] = { "DC", "SIN", "PULSE" };

#endif //CKT_SIM_SOURCETYPE_H