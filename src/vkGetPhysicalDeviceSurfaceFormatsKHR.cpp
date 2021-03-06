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

VkResult VKAPI_CALL VulkanOnD3D12GetPhysicalDeviceSurfaceFormatsKHR(
    VkPhysicalDevice    physicalDevice,
    VkSurfaceKHR        surface,
    uint32_t*           pSurfaceFormatCount,
    VkSurfaceFormatKHR* pSurfaceFormats)
{
    if (pSurfaceFormats)
    {
        // https://msdn.microsoft.com/en-us/library/windows/desktop/hh404528(v=vs.85).aspx
        pSurfaceFormats[0].format = VK_FORMAT_B8G8R8A8_UNORM;
        pSurfaceFormats[1].format = VK_FORMAT_B8G8R8A8_SRGB;
        pSurfaceFormats[2].format = VK_FORMAT_R8G8B8A8_UNORM;
        pSurfaceFormats[3].format = VK_FORMAT_R8G8B8A8_SRGB;
        pSurfaceFormats[4].format = VK_FORMAT_R16G16B16A16_SFLOAT;
    }

    *pSurfaceFormatCount = 5;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormatsKHR(
    VkPhysicalDevice    physicalDevice,
    VkSurfaceKHR        surface,
    uint32_t*           pSurfaceFormatCount,
    VkSurfaceFormatKHR* pSurfaceFormats)
{
    return VulkanOnD3D12GetPhysicalDeviceSurfaceFormatsKHR(
        physicalDevice,
        surface,
        pSurfaceFormatCount,
        pSurfaceFormats);
}
}
