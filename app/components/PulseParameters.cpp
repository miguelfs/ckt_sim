//
// Created by Miguel Sousa on 01/12/18.
//

#include "PulseParameters.h"

void PulseParameters::setValue(double time) {
    /**
     * Modela casos em que o tempo de subida e descida
     * sao iguais a 0 para evitar problemas na plotagem
     * do grafico
     */
    if (riseTime == 0) {
        riseTime = timeStep;
    }
    if (fallTime == 0) {
        fallTime = timeStep;
    }

    /**
     * Regiao em que a fonte se encontra dentro do periodo
     */
    double iPeriod = fmod((time - delay), period);

    if (time <= delay) {
        value = amplitude1;
    } else if (time > ((period * cycles) + delay)) {
        value = amplitude1;
    } else if (iPeriod < riseTime) {
        double deltaAmp = amplitude2 - amplitude1;
        double dPdts = iPeriod / riseTime;
        value = ((deltaAmp * dPdts) + amplitude1);
    } else if (iPeriod >= riseTime && (iPeriod <= (riseTime + pulseWidth))) {
        value = amplitude2;
    } else if ((iPeriod > (riseTime + pulseWidth)) && (iPeriod < (fallTime + riseTime + pulseWidth))) {
        double deltaAmp = amplitude1 - amplitude2;
        double dPdts = ((iPeriod - riseTime - pulseWidth) / fallTime);
        value = (deltaAmp * dPdts) + amplitude2;
    } else {
        value = amplitude1;
    }
}

PulseParameters::PulseParameters(double amplitude1, double amplitude2, double delay, double riseTime, double fallTime,
                                 double pulseWidth, double period, double cycles, double timeStep) : amplitude1(
        amplitude1), amplitude2(amplitude2), delay(delay), riseTime(riseTime), fallTime(fallTime), pulseWidth(
        pulseWidth), period(period), cycles(cycles), timeStep(timeStep), value(0) {}

double PulseParameters::getValue() {
    return value;
}
