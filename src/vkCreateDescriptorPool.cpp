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

VkResult VKAPI_CALL VulkanOnD3D12CreateDescriptorPool(
    VkDevice                          device,
    const VkDescriptorPoolCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*      pAllocator,
    VkDescriptorPool*                 pDescriptorPool)
{
    VkDescriptorPool descriptorPool;
    if (pAllocator)
    {
        descriptorPool = reinterpret_cast<VkDescriptorPool>(pAllocator->pfnAllocation(nullptr, sizeof(VkDescriptorPool_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));
    }
    else
    {
        descriptorPool = new VkDescriptorPool_T();
    }

    *pDescriptorPool = descriptorPool;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorPool(
    VkDevice                          device,
    const VkDescriptorPoolCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*      pAllocator,
    VkDescriptorPool*                 pDescriptorPool)
{
    return VulkanOnD3D12CreateDescriptorPool(
        device,
        pCreateInfo,
        pAllocator,
        pDescriptorPool);
}
}
