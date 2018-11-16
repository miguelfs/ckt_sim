//
// Created by Miguel Sousa on 02/12/17.
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
    double stepTime;

private:
    int stepsByTablePoint;
    initialConfiguration initialConfig;

    void splitRow(int quantityOfArguments, std::string row, std::string *arguments);

    void setInitialConfiguration(std::string argument);

public:

    Transient(std::string row, int quantityOfArguments);

    Transient();

    double getStepTime();


};


#endif //CKT_SIM_TRANSIENT_H
