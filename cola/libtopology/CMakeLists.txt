cmake_minimum_required(VERSION 3.16)

project(topology)

add_library(${PROJECT_NAME}
    cola_topology_addon.cpp
    compute_forces.cpp
    orthogonal_topology.cpp
    resize.cpp
    topology_constraints.cpp
    topology_constraints_constructor.cpp
    topology_graph.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

if (ENABLE_TESTS)
#    TODO: other test cases
    add_executable(test_${PROJECT_NAME}_orthogonalOpt tests/orthogonalOpt.cpp)
    target_link_libraries(test_${PROJECT_NAME}_orthogonalOpt ${PROJECT_NAME} avoid cola topology vpsc)
    target_include_directories(test_${PROJECT_NAME}_orthogonalOpt PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)
    # 'output' is added to IMAGE_OUTPUT_PATH inside of tests to keep compatibility with Makefile build
    target_compile_definitions(test_${PROJECT_NAME}_orthogonalOpt PRIVATE -DIMAGE_OUTPUT_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/tests/\" -DTEST_DATA_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/tests/\")

    add_test(NAME test_${PROJECT_NAME}_orthogonalOpt
            COMMAND test_${PROJECT_NAME}_orthogonalOpt)
endif()
