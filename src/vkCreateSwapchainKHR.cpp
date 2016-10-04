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

#include "VulkanOnD3D12.h"

VkResult VKAPI_CALL VulkanOnD3D12CreateSwapchainKHR(
    VkDevice                        device,
    const VkSwapchainCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*    pAllocator,
    VkSwapchainKHR*                 pSwapchain)
{
    VkSwapchainKHR swapchain;
    if (pAllocator)
    {
        swapchain = reinterpret_cast<VkSwapchainKHR>(pAllocator->pfnAllocation(nullptr, sizeof(VkSwapchainKHR_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));
    }
    else
    {
        swapchain = new VkSwapchainKHR_T();
    }

    DXGI_SWAP_EFFECT swapEffect;
    if (pCreateInfo->clipped)
    {
        swapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    }
    else
    {
        swapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
    }

    DXGI_SWAP_CHAIN_DESC1 desc = {};
    desc.Width                 = pCreateInfo->imageExtent.width;
    desc.Height                = pCreateInfo->imageExtent.height;
    desc.Stereo                = false;
    desc.SampleDesc.Count      = 1;
    desc.SampleDesc.Quality    = 0;
    desc.BufferUsage           = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    desc.BufferCount           = pCreateInfo->minImageCount;
    desc.Scaling;
    desc.SwapEffect = swapEffect;
    desc.AlphaMode;
    desc.Flags;

    if (pCreateInfo->imageFormat == VK_FORMAT_R16G16B16A16_SFLOAT)
    {
        desc.Format = DXGI_FORMAT_R16G16B16A16_FLOAT;
    }
    else if (pCreateInfo->imageFormat == VK_FORMAT_R8G8B8A8_UNORM || pCreateInfo->imageFormat == VK_FORMAT_R8G8B8A8_SRGB)
    {
        desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    }
    else
    {
        desc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    }

    HRESULT                 hr;
    ComPtr<IDXGISwapChain1> swapChain;
    auto                    queue = device->queues[0]->Get();
#ifdef VK_USE_PLATFORM_WIN32_KHR
    hr = device->physicalDevice->instance->factory->CreateSwapChainForHwnd(queue, pCreateInfo->surface->hwnd, &desc, nullptr, nullptr, &swapChain);
#else
    hr = device->physicalDevice->instance->factory->CreateSwapChainForCoreWindow(queue, pCreateInfo->surface->window, &desc, nullptr, &swapChain);
#endif // VK_USE_PLATFORM_WIN32_KHR
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    hr = swapChain->QueryInterface(IID_PPV_ARGS(&swapchain->swapChain));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    swapchain->desc = desc;

    D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
    rtvHeapDesc.Type                       = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rtvHeapDesc.NumDescriptors             = pCreateInfo->minImageCount;

    hr = device->device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&device->rtvHeap));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc = {};
    dsvHeapDesc.Type                       = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
    dsvHeapDesc.NumDescriptors             = 1;

    hr = device->device->CreateDescriptorHeap(&dsvHeapDesc, IID_PPV_ARGS(&device->dsvHeap));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    *pSwapchain = swapchain;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSwapchainKHR(
    VkDevice                        device,
    const VkSwapchainCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*    pAllocator,
    VkSwapchainKHR*                 pSwapchain)
{
    return VulkanOnD3D12CreateSwapchainKHR(
        device,
        pCreateInfo,
        pAllocator,
        pSwapchain);
}
}
