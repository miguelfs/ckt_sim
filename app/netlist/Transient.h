//
// Created by Miguel Sousa on 02/11/18.
//

#ifndef CKT_SIM_TRANSIENT_H
#define CKT_SIM_TRANSIENT_H


#include <string>

class Transient {

    enum initialConfiguration {
        initialConditions,
        operationPoint
    };

private:
    double finalTime;
    double timeStep;

private:
    int stepsByTablePoint;
    initialConfiguration initialConfig;

    void splitRow(int quantityOfArguments, std::string row, std::string *arguments);

    void setInitialConfiguration(std::string argument);

public:

    Transient(std::string row, int quantityOfArguments);

    Transient();

    double getTimeStep();


};


#endif //CKT_SIM_TRANSIENT_H
