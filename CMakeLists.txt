cmake_minimum_required(VERSION 3.20)

# create `compile_commands.json` for clangd and autocompletion
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall)

project(main)

add_executable(${PROJECT_NAME} main.cpp)

# Search in our custom directory
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};thirdparty/bin)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost REQUIRED COMPONENTS log)

target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} 
    Boost::log
)
