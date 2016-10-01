cmake_minimum_required(VERSION 3.0)

add_definitions("/DUNICODE /D_UNICODE /W4 /YuVulkanOnD3D12.h")

file(GLOB HEADERS *.h)
file(GLOB SOURCES *.cpp)

set_source_files_properties(VulkanOnD3D12.cpp PROPERTIES COMPILE_FLAGS "/YcVulkanOnD3D12.h")

add_library(VulkanOnD3D12 STATIC ${HEADERS} ${SOURCES})
