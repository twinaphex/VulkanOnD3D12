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

#ifdef VK_USE_PLATFORM_UAP_CHB

VkResult VKAPI_CALL VulkanOnD3D12CreateUAPSurfaceCHB(
    VkInstance                       instance,
    const VkUAPSurfaceCreateInfoCHB* pCreateInfo,
    const VkAllocationCallbacks*     pAllocator,
    VkSurfaceKHR*                    pSurface)
{
    VkSurfaceKHR surface;
    if (pAllocator)
    {
        surface = reinterpret_cast<VkSurfaceKHR>(pAllocator->pfnAllocation(nullptr, sizeof(VkDevice_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));
    }
    else
    {
        surface = new VkSurfaceKHR_T();
    }

    surface->window = pCreateInfo->window;

    *pSurface = surface;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkCreateUAPSurfaceCHB(
    VkInstance                       instance,
    const VkUAPSurfaceCreateInfoCHB* pCreateInfo,
    const VkAllocationCallbacks*     pAllocator,
    VkSurfaceKHR*                    pSurface)
{
    return VulkanOnD3D12CreateUAPSurfaceCHB(
        instance,
        pCreateInfo,
        pAllocator,
        pSurface);
}
}

#endif // VK_USE_PLATFORM_UAP_CHB
