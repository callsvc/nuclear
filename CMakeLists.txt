cmake_minimum_required(VERSION 3.21)
project(Nuclear)

set(CMAKE_CXX_STANDARD 20)

add_library(nuked STATIC)
add_subdirectory(src)
add_subdirectory(test)

find_package(Boost)
target_link_libraries(nuked PRIVATE ${BOOST_LIBRARIES})

