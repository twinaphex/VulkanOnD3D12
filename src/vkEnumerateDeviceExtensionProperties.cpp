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

VkResult VKAPI_CALL VulkanOnD3D12EnumerateDeviceExtensionProperties(
    VkPhysicalDevice       physicalDevice,
    const char*            pLayerName,
    uint32_t*              pPropertyCount,
    VkExtensionProperties* pProperties)
{
    std::vector<VkExtensionProperties> properties;

    VkExtensionProperties swapchainProperties = {VK_KHR_SWAPCHAIN_EXTENSION_NAME, VK_KHR_SWAPCHAIN_SPEC_VERSION};
    properties.push_back(swapchainProperties);

    VkExtensionProperties csoProperties = {VK_CHB_CSO_SHADER_EXTENSION_NAME, VK_CHB_CSO_SHADER_SPEC_VERSION};
    properties.push_back(csoProperties);

    VkExtensionProperties hlslProperties = {VK_CHB_HLSL_SHADER_EXTENSION_NAME, VK_CHB_HLSL_SHADER_SPEC_VERSION};
    properties.push_back(hlslProperties);

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
VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceExtensionProperties(
    VkPhysicalDevice       physicalDevice,
    const char*            pLayerName,
    uint32_t*              pPropertyCount,
    VkExtensionProperties* pProperties)
{
    return VulkanOnD3D12EnumerateDeviceExtensionProperties(
        physicalDevice,
        pLayerName,
        pPropertyCount,
        pProperties);
}
}
