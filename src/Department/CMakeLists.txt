add_library(DepartmentLib Department.cpp Department.hpp)

target_include_directories(DepartmentLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})