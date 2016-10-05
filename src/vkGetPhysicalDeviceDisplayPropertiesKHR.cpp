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

VkResult VKAPI_CALL VulkanOnD3D12GetPhysicalDeviceDisplayPropertiesKHR(
    VkPhysicalDevice        physicalDevice,
    uint32_t*               pPropertyCount,
    VkDisplayPropertiesKHR* pProperties)
{
    ComPtr<IDXGIOutput> output;
    uint32_t            numOutputs = 0;
    while (physicalDevice->adapter->EnumOutputs(numOutputs, &output) != DXGI_ERROR_NOT_FOUND)
    {
        auto display = new VkDisplayKHR_T();

        HRESULT hr;
        hr = output.As(&display->output);
        if (FAILED(hr))
        {
            return VkResultFromHRESULT(hr);
        }

        DXGI_OUTPUT_DESC desc = {};
        hr                    = display->Get()->GetDesc(&desc);
        if (FAILED(hr))
        {
            return VkResultFromHRESULT(hr);
        }

        char name[32];
        wcstombs_s(nullptr, name, desc.DeviceName, 32);

        VkDisplayPropertiesKHR properties    = {};
        properties.display                   = display;
        properties.displayName               = name;
        properties.physicalDimensions.width  = 0;
        properties.physicalDimensions.height = 0;
        properties.physicalResolution.width  = desc.DesktopCoordinates.right - desc.DesktopCoordinates.left;
        properties.physicalResolution.height = desc.DesktopCoordinates.bottom - desc.DesktopCoordinates.top;
        properties.supportedTransforms       = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR | VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR | VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR | VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR;
        properties.planeReorderPossible;
        properties.persistentContent;

        if (pProperties)
        {
            pProperties[numOutputs] = properties;
        }

        ++numOutputs;
    }

    *pPropertyCount = numOutputs;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPropertiesKHR(
    VkPhysicalDevice        physicalDevice,
    uint32_t*               pPropertyCount,
    VkDisplayPropertiesKHR* pProperties)
{
    return VulkanOnD3D12GetPhysicalDeviceDisplayPropertiesKHR(
        physicalDevice,
        pPropertyCount,
        pProperties);
}
}
