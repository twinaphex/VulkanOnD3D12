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

VkResult VKAPI_CALL VulkanOnD3D12CreateDevice(
    VkPhysicalDevice             physicalDevice,
    const VkDeviceCreateInfo*    pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDevice*                    pDevice)
{
    VkDevice device;
    if (pAllocator)
    {
        device = reinterpret_cast<VkDevice>(pAllocator->pfnAllocation(nullptr, sizeof(VkDevice_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));
    }
    else
    {
        device = new VkDevice_T();
    }

    HRESULT hr;
    hr = D3D12CreateDevice(physicalDevice->adapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device->device));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    *pDevice = device;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDevice(
    VkPhysicalDevice             physicalDevice,
    const VkDeviceCreateInfo*    pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDevice*                    pDevice)
{
    return VulkanOnD3D12CreateDevice(
        physicalDevice,
        pCreateInfo,
        pAllocator,
        pDevice);
}
}
