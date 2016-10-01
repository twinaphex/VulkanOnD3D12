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

#include "VulkanOnD3D12Types.h"

#include <wrl.h>

#include <vector>

using namespace Microsoft::WRL;

inline auto VkResultFromHRESULT(HRESULT hr)
{
    switch (hr)
    {
    case E_OUTOFMEMORY:
        return VK_ERROR_OUT_OF_HOST_MEMORY;
    case DXGI_ERROR_UNSUPPORTED:
        return VK_ERROR_INITIALIZATION_FAILED;
    default:
        return VK_ERROR_INITIALIZATION_FAILED;
    }
}

#ifdef __cplusplus
extern "C" {
#endif

#ifdef VK_USE_PLATFORM_UAP_CHB
#define VK_CHB_uap_surface 1
#include <windows.h>

#define VK_CHB_UAP_SURFACE_SPEC_VERSION 1
#define VK_CHB_UAP_SURFACE_EXTENSION_NAME "VK_CHB_uap_surface"

typedef VkFlags VkUAPSurfaceCreateFlagsCHB;

typedef struct VkUAPSurfaceCreateInfoCHB
{
    VkStructureType            sType;
    const void*                pNext;
    VkUAPSurfaceCreateFlagsCHB flags;
    IUnknown*                  window;
} VkUAPSurfaceCreateInfoCHB;

typedef VkResult(VKAPI_PTR* PFN_vkCreateUAPSurfaceCHB)(VkInstance instance, const VkUAPSurfaceCreateInfoCHB* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceUAPPresentationSupportCHB)(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateUAPSurfaceCHB(
    VkInstance                       instance,
    const VkUAPSurfaceCreateInfoCHB* pCreateInfo,
    const VkAllocationCallbacks*     pAllocator,
    VkSurfaceKHR*                    pSurface);

VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceUAPPresentationSupportCHB(
    VkPhysicalDevice physicalDevice,
    uint32_t         queueFamilyIndex);
#endif
#endif // VK_USE_PLATFORM_UAP_CHB

#ifdef __cplusplus
}
#endif
