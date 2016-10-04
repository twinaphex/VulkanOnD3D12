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

VkResult VKAPI_CALL VulkanOnD3D12AllocateCommandBuffers(
    VkDevice                           device,
    const VkCommandBufferAllocateInfo* pAllocateInfo,
    VkCommandBuffer*                   pCommandBuffers)
{
    std::vector<VkCommandBuffer> commandBuffers;
    for (uint32_t i = 0; i < pAllocateInfo->commandBufferCount; ++i)
    {
        pCommandBuffers[i] = new VkCommandBuffer_T();

        HRESULT hr;
        hr = device->device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, pAllocateInfo->commandPool->Get(), nullptr, IID_PPV_ARGS(&pCommandBuffers[i]->list));
        if (FAILED(hr))
        {
            return VkResultFromHRESULT(hr);
        }
    }

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkAllocateCommandBuffers(
    VkDevice                           device,
    const VkCommandBufferAllocateInfo* pAllocateInfo,
    VkCommandBuffer*                   pCommandBuffers)
{
    return VulkanOnD3D12AllocateCommandBuffers(
        device,
        pAllocateInfo,
        pCommandBuffers);
}
}
