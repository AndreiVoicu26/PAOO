add_library(StudentLib Student.cpp Student.hpp)

target_include_directories(StudentLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})