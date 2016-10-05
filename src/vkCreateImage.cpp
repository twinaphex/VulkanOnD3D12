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

VkResult VKAPI_CALL VulkanOnD3D12CreateImage(
    VkDevice                     device,
    const VkImageCreateInfo*     pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkImage*                     pImage)
{
    VkImage image;
    if (pAllocator)
    {
        image = reinterpret_cast<VkImage>(pAllocator->pfnAllocation(nullptr, sizeof(VkImage_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));
    }
    else
    {
        image = new VkImage_T();
    }

    D3D12_CLEAR_VALUE     clear = {};
    D3D12_RESOURCE_STATES state = D3D12_RESOURCE_STATE_COPY_DEST;
    D3D12_RESOURCE_FLAGS  flags = D3D12_RESOURCE_FLAG_NONE;
    if (pCreateInfo->usage & VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT)
    {
        clear = CD3DX12_CLEAR_VALUE(VkFormatToD3D12(pCreateInfo->format), 1.0f, 0);
        flags |= D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;
        flags |= D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE;
    }

    D3D12_RESOURCE_DESC desc = {};
    switch (pCreateInfo->imageType)
    {
    case VK_IMAGE_TYPE_1D:
        desc = CD3DX12_RESOURCE_DESC::Tex1D(
            VkFormatToD3D12(pCreateInfo->format),
            pCreateInfo->extent.width,
            pCreateInfo->arrayLayers,
            pCreateInfo->mipLevels,
            flags);
        break;
    case VK_IMAGE_TYPE_2D:
        desc = CD3DX12_RESOURCE_DESC::Tex2D(
            VkFormatToD3D12(pCreateInfo->format),
            pCreateInfo->extent.width,
            pCreateInfo->extent.height,
            pCreateInfo->arrayLayers,
            pCreateInfo->mipLevels,
            pCreateInfo->samples,
            0,
            flags);
        break;
    case VK_IMAGE_TYPE_3D:
        desc = CD3DX12_RESOURCE_DESC::Tex3D(
            VkFormatToD3D12(pCreateInfo->format),
            pCreateInfo->extent.width,
            pCreateInfo->extent.height,
            pCreateInfo->extent.depth,
            pCreateInfo->mipLevels,
            flags);
        break;
    }

    HRESULT hr;
    hr = device->device->CreateCommittedResource(
        &CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT),
        D3D12_HEAP_FLAG_NONE,
        &desc,
        state,
        (flags & D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET) || (flags & D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL) ? &clear : nullptr,
        IID_PPV_ARGS(&image->texture));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    *pImage = image;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkCreateImage(
    VkDevice                     device,
    const VkImageCreateInfo*     pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkImage*                     pImage)
{
    return VulkanOnD3D12CreateImage(
        device,
        pCreateInfo,
        pAllocator,
        pImage);
}
}
