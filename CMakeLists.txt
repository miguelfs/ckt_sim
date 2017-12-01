cmake_minimum_required(VERSION 3.9)
project(ckt_sim)

set(CMAKE_CXX_STANDARD 11)

add_executable(ckt_sim app/main.cpp app/components/Component.cpp app/components/Component.h app/circuit/Circuit.cpp app/circuit/Circuit.h app/components/ComponentType.h app/netlist/RowType.h app/netlist/Row.cpp app/netlist/Row.h app/netlist/Netlist.cpp app/netlist/Netlist.h)