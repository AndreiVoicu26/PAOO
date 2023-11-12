add_library(PersonLib Person.cpp Person.hpp)

target_include_directories(PersonLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})