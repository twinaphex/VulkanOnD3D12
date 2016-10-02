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

VkResult VKAPI_CALL VulkanOnD3D12EnumeratePhysicalDevices(
    VkInstance        instance,
    uint32_t*         pPhysicalDeviceCount,
    VkPhysicalDevice* pPhysicalDevices)
{
    ComPtr<IDXGIAdapter1> adapter;
    uint32_t              numAdapters = 0;
    while (instance->factory->EnumAdapters1(numAdapters, &adapter) != DXGI_ERROR_NOT_FOUND)
    {
        auto physicalDevice = new VkPhysicalDevice_T();
        adapter->QueryInterface(IID_PPV_ARGS(&physicalDevice->adapter));
        physicalDevice->adapter->GetDesc2(&physicalDevice->desc);
        physicalDevice->instance = instance;

        if (pPhysicalDevices)
        {
            pPhysicalDevices[numAdapters] = physicalDevice;
        }

        ++numAdapters;
    }

    *pPhysicalDeviceCount = numAdapters;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(
    VkInstance        instance,
    uint32_t*         pPhysicalDeviceCount,
    VkPhysicalDevice* pPhysicalDevices)
{
    return VulkanOnD3D12EnumeratePhysicalDevices(
        instance,
        pPhysicalDeviceCount,
        pPhysicalDevices);
}
}
