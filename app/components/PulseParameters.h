//
// Created by Miguel Sousa on 01/12/18.
//

#ifndef CKT_SIM_PULSEPARAMETERS_H
#define CKT_SIM_PULSEPARAMETERS_H

#include <math.h>


class PulseParameters {
public:
    PulseParameters(double amplitude1, double amplitude2, double delay, double riseTime, double fallTime,
                    double pulseWidth, double period, double cycles, double timeStep);

    void setValue(double time);

    double getValue();

private:
    double amplitude1, amplitude2, delay, riseTime, fallTime, pulseWidth, period, cycles, timeStep, value;
};


#endif //CKT_SIM_PULSEPARAMETERS_H
