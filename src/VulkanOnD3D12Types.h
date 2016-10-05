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

#include "d3dx12.h"
#include <dxgi1_5.h>
#include <wrl.h>

#include <vector>

using namespace Microsoft::WRL;

struct VkInstance_T
{
    ComPtr<IDXGIFactory5> factory;

    auto Get() const
    {
        return factory.Get();
    }
};

struct VkPhysicalDevice_T
{
    ComPtr<IDXGIAdapter3> adapter;
    DXGI_ADAPTER_DESC2    desc;
    uint32_t              index;
    VkInstance            instance;

    auto Get() const
    {
        return adapter.Get();
    }
};

struct VkDevice_T
{
    ComPtr<ID3D12Device1>        device;
    ComPtr<ID3D12DescriptorHeap> rtvHeap;
    ComPtr<ID3D12DescriptorHeap> dsvHeap;
    std::vector<VkQueue>         queues;
    VkPhysicalDevice             physicalDevice;

    auto Get() const
    {
        return device.Get();
    }
};

struct VkQueue_T
{
    ComPtr<ID3D12CommandQueue> queue;

    auto Get() const
    {
        return queue.Get();
    }
};

struct VkSemaphore_T
{
};

struct VkCommandBuffer_T
{
    ComPtr<ID3D12CommandList> list;

    auto Get() const
    {
        return list.Get();
    }
};

struct VkFence_T
{
    ComPtr<ID3D12Fence> fence;

    auto Get() const
    {
        return fence.Get();
    }
};

struct VkDeviceMemory_T
{
};

struct VkBuffer_T
{
};

struct VkImage_T
{
    ComPtr<ID3D12Resource> texture;

    auto Get() const
    {
        return texture.Get();
    }
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

    auto Get() const
    {
        return handle;
    }
};

struct VkShaderModule_T
{
    D3D12_SHADER_BYTECODE data;

    auto Get() const
    {
        return data;
    }
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
    ComPtr<ID3D12CommandAllocator> allocator;

    auto Get() const
    {
        return allocator.Get();
    }
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
    ComPtr<IDXGISwapChain4> swapChain;
    DXGI_SWAP_CHAIN_DESC1   desc;

    auto Get() const
    {
        return swapChain.Get();
    }
};

struct VkDisplayKHR_T
{
    ComPtr<IDXGIOutput5> output;

    auto Get() const
    {
        return output.Get();
    }
};

struct VkDisplayModeKHR_T
{
};

struct VkDebugReportCallbackEXT_T
{
};
