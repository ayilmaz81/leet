cmake_minimum_required(VERSION 3.0.0)
project(leet VERSION 0.1.0)

enable_testing()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")

add_subdirectory (tests)
add_subdirectory (src)

include(CPack)
