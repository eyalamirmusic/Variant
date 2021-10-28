cmake_minimum_required(VERSION 3.17)
project(VariantExamples)

add_executable(PolymorphicExample Polymorphic.cpp)
target_link_libraries(PolymorphicExample PRIVATE ea_variant)