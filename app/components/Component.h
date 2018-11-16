//
// Created by Miguel Sousa on 01/12/17.
//

#ifndef CKT_SIM_COMPONENT_H
#define CKT_SIM_COMPONENT_H

#include <string>
#include "ComponentType.h"

 class Component {
 public:


     //se G[a][b], a linha, b coluna
     virtual void stampG(double** G);

  //   virtual void stampGtest(int order, double G[][order]);

 private:
     Component_Type type;
 public:
     Component_Type getComponentType() const;
     Component();

 protected:
     int *nodes;
     std::string name;

     void splitRow(int size, std::string row, std::string *arr);
     double getInitialCurrent(std::string initialCurrent);

     //conductanceMatrix * unknownValues = RightHandSideMatrix

     virtual void stampSolutionVector(double* solutionVector) ;

     virtual void stampRightSideVector(double* rightSideVector);

     Component(Component_Type type);

     void GstampFor2x2Component(double **G, double stamp[2][2], int *nodes);
 };

#endif //CKT_SIM_COMPONENT_H
