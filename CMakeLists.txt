cmake_minimum_required(VERSION 3.9)

project(premier-cours
        VERSION 0.1
        DESCRIPTION "Programme du premier cours du club info"
        LANGUAGES CXX)


if(MSVC)
    add_compile_options(/W4 /W14640 /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic)
endif()


if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin/${CMAKE_BUILD_TYPE})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)


add_subdirectory(src)