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

VkResult VKAPI_CALL VulkanOnD3D12CreateCommandPool(
    VkDevice                       device,
    const VkCommandPoolCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*   pAllocator,
    VkCommandPool*                 pCommandPool)
{
    VkCommandPool commandPool;
    if (pAllocator)
    {
        commandPool = reinterpret_cast<VkCommandPool>(pAllocator->pfnAllocation(nullptr, sizeof(VkCommandPool_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));
    }
    else
    {
        commandPool = new VkCommandPool_T();
    }

    HRESULT hr;
    hr = device->device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&commandPool->allocator));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    *pCommandPool = commandPool;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCommandPool(
    VkDevice                       device,
    const VkCommandPoolCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*   pAllocator,
    VkCommandPool*                 pCommandPool)
{
    return VulkanOnD3D12CreateCommandPool(
        device,
        pCreateInfo,
        pAllocator,
        pCommandPool);
}
}
