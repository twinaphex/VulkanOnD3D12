cmake_minimum_required(VERSION 3.0)

add_definitions(-D_USE_MATH_DEFINES -D_CRT_SECURE_NO_WARNINGS)

include_directories(../src)

if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)

add_definitions("/DVK_USE_PLATFORM_WIN32_KHR")

add_executable(VulkanOnD3D12-cube WIN32 cube.c)
target_link_libraries(VulkanOnD3D12-cube VulkanOnD3D12 d3d12 dxgi)
add_executable(VulkanOnD3D12-tri WIN32 tri.c)
target_link_libraries(VulkanOnD3D12-tri VulkanOnD3D12 d3d12 dxgi)
add_executable(VulkanOnD3D12-vulkaninfo vulkaninfo.c)
target_link_libraries(VulkanOnD3D12-vulkaninfo VulkanOnD3D12 d3d12 dxgi)

else()

add_definitions("/ZW")

add_executable(VulkanOnD3D12-uapexample WIN32 App.h App.cpp)
target_link_libraries(VulkanOnD3D12-uapexample VulkanOnD3D12 d3d12 dxgi)

endif()
