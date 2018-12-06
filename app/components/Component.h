//
// Created by Miguel Sousa on 01/11/18.
//

#ifndef CKT_SIM_COMPONENT_H
#define CKT_SIM_COMPONENT_H
#define infinitesimalTimeStep 0.0000000001000001
#define infiniteReactance 1000000000000000
#define infinitesimalReactance 0.000000000000001
#include <string>
#include "ComponentType.h"
#include "../netlist/OperationMethod.h"

class Component {
 public:


    virtual void stampG(double **G, OperationMethod operationMethod);

    virtual void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod, double time);

 private:
     Component_Type type;
 public:
     Component_Type getComponentType() const;
     Component();

     virtual bool doesHaveInitialCondition();

    virtual void setValue(double *SolutionVector);

    const std::string &getName() const;

protected:
     int nodes[2];
     std::string name;

     void splitRow(int size, std::string row, std::string *arr);

     double getInitialCondition(std::string initialCondition);

     virtual void stampSolutionVector(double* solutionVector) ;

     Component(Component_Type type);

     void GstampFor2x2Component(double **G, double stamp[2][2], int *nodes);

public:


    double parse(std::string word);
};

#endif //CKT_SIM_COMPONENT_H
