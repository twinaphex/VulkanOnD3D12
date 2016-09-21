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

VkResult VKAPI_CALL VulkanOnD3D12CreateInstance(
    const VkInstanceCreateInfo*  pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkInstance*                  pInstance)
{
    VkInstance instance;
    if (pAllocator)
    {
        instance = reinterpret_cast<VkInstance>(pAllocator->pfnAllocation(nullptr, sizeof(VkInstance_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE));
    }
    else
    {
        instance = new VkInstance_T();
    }

    HRESULT hr;
    hr = CreateDXGIFactory2(0, IID_PPV_ARGS(&instance->factory));
    if (FAILED(hr))
    {
    }

    *pInstance = instance;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(
    const VkInstanceCreateInfo*  pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkInstance*                  pInstance)
{
    return VulkanOnD3D12CreateInstance(
        pCreateInfo,
        pAllocator,
        pInstance);
}
}
