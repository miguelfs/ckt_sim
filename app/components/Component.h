//
// Created by Miguel Sousa on 01/12/17.
//

#ifndef CKT_SIM_COMPONENT_H
#define CKT_SIM_COMPONENT_H

#include <string>
#include "ComponentType.h"
#include "../netlist/OperationMethod.h"

class Component {
 public:


     virtual void stampG(double** G);

    virtual void stampRightSideVector(double *rightSideVector, OperationMethod operationMethod);

 private:
     Component_Type type;
 public:
     Component_Type getComponentType() const;
     Component();

     virtual bool doesHaveInitialCondition();
 protected:
     int *nodes;
     std::string name;

     void splitRow(int size, std::string row, std::string *arr);

     double getInitialCondition(std::string initialCondition);


     virtual void stampSolutionVector(double* solutionVector) ;

     Component(Component_Type type);

     void GstampFor2x2Component(double **G, double stamp[2][2], int *nodes);

 };

#endif //CKT_SIM_COMPONENT_H
