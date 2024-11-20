cmake_minimum_required(VERSION 3.28)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)

FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX20_STANDARD_COMPILE_OPTION, "-std:c++latest")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


add_executable(
    unit_tests
    "src/CircularQueue.cpp"
    "tests/unit_tests.cpp"
)

target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)