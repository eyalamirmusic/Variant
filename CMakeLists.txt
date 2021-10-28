cmake_minimum_required(VERSION 3.17)
project(Variant)
set(CMAKE_CXX_STANDARD 17)

add_library(ea_variant INTERFACE)
set(SourceDir ea_variant/Source)
target_sources(ea_variant INTERFACE
        ${SourceDir}/Variant.h
        ${SourceDir}/Rollbear.h)

target_include_directories(ea_variant INTERFACE ${CMAKE_CURRENT_LIST_DIR})

option(EA_Variant_Examples "Variant Examples" OFF)

if (EA_Variant_Examples)
    add_subdirectory(Examples)
endif()