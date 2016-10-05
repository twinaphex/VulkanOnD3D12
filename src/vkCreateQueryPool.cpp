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

VkResult VKAPI_CALL VulkanOnD3D12CreateQueryPool(
    VkDevice                     device,
    const VkQueryPoolCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkQueryPool*                 pQueryPool)
{
    VkQueryPool queryPool;
    if (pAllocator)
    {
        queryPool = reinterpret_cast<VkQueryPool>(pAllocator->pfnAllocation(nullptr, sizeof(VkQueryPool_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));
    }
    else
    {
        queryPool = new VkQueryPool_T();
    }

    *pQueryPool = queryPool;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkCreateQueryPool(
    VkDevice                     device,
    const VkQueryPoolCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkQueryPool*                 pQueryPool)
{
    return VulkanOnD3D12CreateQueryPool(
        device,
        pCreateInfo,
        pAllocator,
        pQueryPool);
}
}
