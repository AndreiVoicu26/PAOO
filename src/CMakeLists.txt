add_subdirectory(Student)
add_subdirectory(Teacher)
add_subdirectory(Subject)
add_subdirectory(Department)

add_executable(Project main.cpp)

target_link_libraries(Project PRIVATE StudentLib)
target_link_libraries(Project PRIVATE TeacherLib)
target_link_libraries(Project PRIVATE SubjectLib)
target_link_libraries(Project PRIVATE DepartmentLib)

target_include_directories(Project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Student)
target_include_directories(Project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Teacher)
target_include_directories(Project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Subject)
target_include_directories(Project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Department)