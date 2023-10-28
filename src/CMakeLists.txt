add_subdirectory(Student)
add_subdirectory(Subject)

add_executable(Project main.cpp)

target_link_libraries(Project PRIVATE StudentLib)
target_link_libraries(Project PRIVATE SubjectLib)

target_include_directories(Project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Student)
target_include_directories(Project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Subject)