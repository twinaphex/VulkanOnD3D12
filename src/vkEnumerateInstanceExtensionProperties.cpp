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

VkResult VKAPI_CALL VulkanOnD3D12EnumerateInstanceExtensionProperties(
    const char*            pLayerName,
    uint32_t*              pPropertyCount,
    VkExtensionProperties* pProperties)
{
    std::vector<VkExtensionProperties> properties;

    VkExtensionProperties win32Properties = {VK_KHR_WIN32_SURFACE_EXTENSION_NAME, VK_KHR_WIN32_SURFACE_SPEC_VERSION};
    properties.push_back(win32Properties);

    VkExtensionProperties surfaceProperties = {VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_SURFACE_SPEC_VERSION};
    properties.push_back(surfaceProperties);

    if (pProperties)
    {
        for (auto i = 0; i < properties.size(); ++i)
        {
            pProperties[i] = properties[i];
        }
    }

    *pPropertyCount = static_cast<uint32_t>(properties.size());

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(
    const char*            pLayerName,
    uint32_t*              pPropertyCount,
    VkExtensionProperties* pProperties)
{
    return VulkanOnD3D12EnumerateInstanceExtensionProperties(
        pLayerName,
        pPropertyCount,
        pProperties);
}
}
