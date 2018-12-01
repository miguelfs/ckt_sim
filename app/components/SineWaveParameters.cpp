//
// Created by Miguel Sousa on 01/12/18.
//

#include "SineWaveParameters.h"

void SineWaveParameters::setValue(double time) {

    double amplitude;
    double sineValue;

    amplitude = this->amplitude * exp((-1 * this->damping) * (time - this->delay));
    sineValue = sin(2 * M_PI * this->frequency * (time - this->delay) + ((M_PI / 180) * this->phase));
    this->value = this->dcOffset + (amplitude * sineValue);
    /**
     * Desliga a fonte caso o numero de ciclos tenha sido
     * concluido
     */
    if (time <= this->delay) {
        sineValue = sin((M_PI / 180) * this->phase);
        this->value = this->dcOffset + (this->amplitude * sineValue);
    }
    if (time > (1 / this->frequency * this->cycles) + this->delay) {
        amplitude = this->amplitude * exp((-1 * this->damping) * (1 / this->frequency * this->cycles));
        sineValue = sin(2 * M_PI * this->cycles + ((M_PI / 180) * this->phase));
        this->value = this->dcOffset + (amplitude * sineValue);
    }
}

SineWaveParameters::SineWaveParameters(double dcOffset, double amplitude, double frequency, double delay,
                                       double damping, double phase, double cycles) : dcOffset(dcOffset),
                                                                                      amplitude(
                                                                                              amplitude),
                                                                                      frequency(
                                                                                              frequency),
                                                                                      delay(delay),
                                                                                      damping(damping),
                                                                                      phase(phase),
                                                                                      cycles(cycles) {}

double SineWaveParameters::getValue() {
    return value;
}
