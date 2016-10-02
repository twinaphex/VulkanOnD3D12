// Copyright 2016 Chabloom LC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <Windows.h>

#if WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
#ifndef VK_USE_PLATFORM_WIN32_KHR
#define VK_USE_PLATFORM_WIN32_KHR
#endif // !VK_USE_PLATFORM_WIN32_KHR
#else
#ifndef VK_USE_PLATFORM_UAP_CHB
#define VK_USE_PLATFORM_UAP_CHB
#endif // !VK_USE_PLATFORM_UAP_CHB
#endif // WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
#include <vulkan/vulkan.h>

#include "d3dx12.h"
#include <dxgi1_5.h>
#include <wrl.h>

#include <vector>

using namespace Microsoft::WRL;

struct VkInstance_T
{
    IDXGIFactory5* factory;
};

struct VkPhysicalDevice_T
{
    IDXGIAdapter3*     adapter;
    DXGI_ADAPTER_DESC2 desc;
    VkInstance         instance;
};

struct VkDevice_T
{
    ID3D12Device1*               device;
    ComPtr<ID3D12DescriptorHeap> rtvHeap;
    ComPtr<ID3D12DescriptorHeap> dsvHeap;
    std::vector<VkQueue>         queues;
    VkPhysicalDevice             physicalDevice;
};

struct VkQueue_T
{
    ID3D12CommandQueue* queue;
};

struct VkSemaphore_T
{
};

struct VkCommandBuffer_T
{
    ID3D12CommandList* list;
};

struct VkFence_T
{
};

struct VkDeviceMemory_T
{
};

struct VkBuffer_T
{
};

struct VkImage_T
{
    ID3D12Resource* texture;
};

struct VkEvent_T
{
};

struct VkQueryPool_T
{
};

struct VkBufferView_T
{
};

struct VkImageView_T
{
    CD3DX12_CPU_DESCRIPTOR_HANDLE handle;
};

struct VkShaderModule_T
{
};

struct VkPipelineCache_T
{
};

struct VkPipelineLayout_T
{
};

struct VkRenderPass_T
{
};

struct VkPipeline_T
{
};

struct VkDescriptorSetLayout_T
{
};

struct VkSampler_T
{
};

struct VkDescriptorPool_T
{
};

struct VkDescriptorSet_T
{
};

struct VkFramebuffer_T
{
};

struct VkCommandPool_T
{
    ID3D12CommandAllocator* allocator;
};

struct VkSurfaceKHR_T
{
#ifdef VK_USE_PLATFORM_WIN32_KHR
    HWND hwnd;
#else
    IUnknown* window;
#endif // VK_USE_PLATFORM_WIN32_KHR
};

struct VkSwapchainKHR_T
{
    IDXGISwapChain4*      swapChain;
    DXGI_SWAP_CHAIN_DESC1 desc;
};

struct VkDisplayKHR_T
{
};

struct VkDisplayModeKHR_T
{
};

struct VkDebugReportCallbackEXT_T
{
};
