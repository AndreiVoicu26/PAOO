add_subdirectory(People/Student)
add_subdirectory(People/Teacher)
add_subdirectory(Subject)

add_executable(Project main.cpp)

target_link_libraries(Project PRIVATE StudentLib)
target_link_libraries(Project PRIVATE TeacherLib)
target_link_libraries(Project PRIVATE SubjectLib)


target_include_directories(Project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/People/Student)
target_include_directories(Project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/People/Teacher)
target_include_directories(Project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Subject)