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

VkResult VKAPI_CALL VulkanOnD3D12GetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkPhysicalDevice          physicalDevice,
    VkSurfaceKHR              surface,
    VkSurfaceCapabilitiesKHR* pSurfaceCapabilities)
{
#ifdef VK_USE_PLATFORM_WIN32_KHR
    RECT rect = {};
    GetClientRect(surface->hwnd, &rect);
#endif // VK_USE_PLATFORM_WIN32_KHR

    VkSurfaceCapabilitiesKHR surfaceCapabilities = {};
    surfaceCapabilities.minImageCount            = 2;
    surfaceCapabilities.maxImageCount            = 8;
#ifdef VK_USE_PLATFORM_WIN32_KHR
    surfaceCapabilities.currentExtent.width  = rect.right - rect.left;
    surfaceCapabilities.currentExtent.height = rect.bottom - rect.top;
#endif // VK_USE_PLATFORM_WIN32_KHR
    surfaceCapabilities.minImageExtent.width  = 1;
    surfaceCapabilities.minImageExtent.height = 1;
    surfaceCapabilities.maxImageExtent.width  = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    surfaceCapabilities.maxImageExtent.height = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    surfaceCapabilities.maxImageArrayLayers   = D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION;
    surfaceCapabilities.supportedTransforms   = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR | VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR | VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR | VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR;
    surfaceCapabilities.currentTransform      = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
    surfaceCapabilities.supportedCompositeAlpha;
    surfaceCapabilities.supportedUsageFlags;

    *pSurfaceCapabilities = surfaceCapabilities;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkPhysicalDevice          physicalDevice,
    VkSurfaceKHR              surface,
    VkSurfaceCapabilitiesKHR* pSurfaceCapabilities)
{
    return VulkanOnD3D12GetPhysicalDeviceSurfaceCapabilitiesKHR(
        physicalDevice,
        surface,
        pSurfaceCapabilities);
}
}
