cmake_minimum_required(VERSION 3.9)
project(ckt_sim)

set(CMAKE_CXX_STANDARD 11)
include_directories(../ckt_sim/eigen)
#set(Eigen3_DIR "C:\\Eigendir\\Eigen")
#include_directories(${EIGEN_DIR})
#find_package (Eigen3 3.3 REQUIRED NO_MODULE)


add_executable(ckt_sim main.cpp app/components/Component.cpp app/components/Component.h app/components/ComponentType.h app/netlist/Row.cpp app/netlist/Row.h app/netlist/Netlist.cpp app/netlist/Netlist.h app/components/SourceType.h app/fileReader/FileReader.cpp app/fileReader/FileReader.h app/components/Resistor.cpp app/components/Resistor.h app/components/Inductor.cpp app/components/Inductor.h app/components/Capacitor.cpp app/components/Capacitor.h app/components/VoltageControlledVoltageSource.cpp app/components/VoltageControlledVoltageSource.h app/components/VoltageControlledCurrentSource.cpp app/components/VoltageControlledCurrentSource.h app/components/CurrentControlledCurrentSource.cpp app/components/CurrentControlledCurrentSource.h app/components/CurrentControlledVoltageSource.cpp app/components/CurrentControlledVoltageSource.h app/components/DCCurrentSource.cpp app/components/DCCurrentSource.h app/components/DCVoltageSource.cpp app/components/DCVoltageSource.h app/components/AmpOp.cpp app/components/AmpOp.h app/netlist/Transient.cpp app/netlist/Transient.h app/netlist/SystemOfEquations.cpp app/netlist/SystemOfEquations.h app/netlist/OperationMethod.h app/netlist/GaussDecomposition.cpp app/netlist/GaussDecomposition.h app/components/SineWaveVoltageSource.cpp app/components/SineWaveVoltageSource.h app/components/SineWaveCurrentSource.cpp app/components/SineWaveCurrentSource.h app/components/PulseVoltageSource.cpp app/components/PulseVoltageSource.h app/components/PulseCurrentSource.cpp app/components/PulseCurrentSource.h app/components/PulseParameters.cpp app/components/PulseParameters.h app/components/SineWaveParameters.cpp app/components/SineWaveParameters.h app/fileWriter/FileWriter.cpp app/fileWriter/FileWriter.h)
#target_link_libraries(ckt_sim ${EIGEN_DIR})
