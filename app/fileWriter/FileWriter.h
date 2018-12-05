//
// Created by Miguel Sousa on 01/12/18.
//

#ifndef CKT_SIM_FILEWRITER_H
#define CKT_SIM_FILEWRITER_H


#include "../components/ComponentType.h"
#include "../components/Component.h"

class FileWriter {
public:
    FileWriter(std::string fileName);

    void writeRow(std::string row);

    void setHeaderRow(std::vector<Component *> components, int quantityOfComponents, int quantityOfNodes,
                      int quantityOfCurrents);

private:

    std::string fileName;
public:
    const std::string &getFileName() const;

private:

    bool is_empty(std::ifstream &pFile);

    bool fileExists(std::string name);

    bool isOneCurrentNeeded(Component_Type type);

    bool areTwoCurrentsNeeded(Component_Type type);

    std::string headerRow;
};


#endif //CKT_SIM_FILEWRITER_H
