cmake_minimum_required(VERSION 3.2)

project(TESTchain)

add_library(Block src/Block.h src/Block.cpp)
add_library(Blockchain src/Blockchain.h src/Blockchain.cpp)

add_executable(TC src/main.cpp)

find_package(OpenSSL 3.0.2)
target_link_libraries(Block PRIVATE OpenSSL::SSL)
target_link_libraries(TC PRIVATE Blockchain)
target_link_libraries(Blockchain PRIVATE Block)
