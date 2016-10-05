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

VkResult VKAPI_CALL VulkanOnD3D12CreateFence(
    VkDevice                     device,
    const VkFenceCreateInfo*     pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkFence*                     pFence)
{
    VkFence fence;
    if (pAllocator)
    {
        fence = reinterpret_cast<VkFence>(pAllocator->pfnAllocation(nullptr, sizeof(VkFence_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));
    }
    else
    {
        fence = new VkFence_T();
    }

    HRESULT hr;
    hr = device->Get()->CreateFence(pCreateInfo->flags, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence->fence));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    *pFence = fence;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkCreateFence(
    VkDevice                     device,
    const VkFenceCreateInfo*     pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkFence*                     pFence)
{
    return VulkanOnD3D12CreateFence(
        device,
        pCreateInfo,
        pAllocator,
        pFence);
}
}
