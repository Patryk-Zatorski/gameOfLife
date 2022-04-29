cmake_minimum_required(VERSION 3.12)
project(ChangeMyName CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

add_library(gameOfLife_core src/gameboard.cpp src/AlwaysNextTurn.cpp src/UserCommand.cpp) 
target_include_directories(gameOfLife_core PUBLIC include)

# Put Your .cpp files in line below
add_executable(gameOfLife src/main.cpp)
target_link_libraries(gameOfLife gameOfLife_core)

# If You want to write some tests...
option(USE_GTEST "Download compile and provide gtest/gmock" OFF)



if(USE_GTEST)
        include(FetchContent)
        FetchContent_Declare(
                googletest
                GIT_REPOSITORY https://github.com/google/googletest.git
                GIT_TAG main
        )

        FetchContent_MakeAvailable(googletest)

        add_executable(sample_test src/testZero.cpp src/sampleTests.cpp)
        target_include_directories(sample_test PUBLIC include)
        target_link_libraries(sample_test gmock_main gtest gmock)

        add_custom_target(run_tests
                        COMMAND sample_test
                        DEPENDS sample_test)

        enable_testing()
        add_test(tests sample_test)
endif(USE_GTEST)
