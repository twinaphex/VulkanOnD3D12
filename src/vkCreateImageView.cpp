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

VkResult VKAPI_CALL VulkanOnD3D12CreateImageView(
    VkDevice                     device,
    const VkImageViewCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkImageView*                 pView)
{
    VkImageView view;
    if (pAllocator)
    {
        view = reinterpret_cast<VkImageView>(pAllocator->pfnAllocation(nullptr, sizeof(VkImageView_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));
    }
    else
    {
        view = new VkImageView_T();
    }

    DXGI_FORMAT format = VkFormatToD3D12(pCreateInfo->format);

    if (pCreateInfo->image->texture->GetDesc().Flags & D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET)
    {
        view->handle = CD3DX12_CPU_DESCRIPTOR_HANDLE(device->rtvHeap->GetCPUDescriptorHandleForHeapStart());

        D3D12_RENDER_TARGET_VIEW_DESC desc = {};
        desc.Format                        = format;
        switch (pCreateInfo->viewType)
        {
        case VK_IMAGE_VIEW_TYPE_1D:
            desc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE1D;
            break;
        case VK_IMAGE_VIEW_TYPE_2D:
            desc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;
            break;
        case VK_IMAGE_VIEW_TYPE_3D:
            desc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE3D;
            break;
        case VK_IMAGE_VIEW_TYPE_1D_ARRAY:
            desc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE1DARRAY;
            break;
        case VK_IMAGE_VIEW_TYPE_2D_ARRAY:
            desc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2DARRAY;
            break;
        default:
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        device->device->CreateRenderTargetView(pCreateInfo->image->Get(), &desc, view->handle);
        view->handle.Offset(device->device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV));
    }

    if (pCreateInfo->image->Get()->GetDesc().Flags & D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL)
    {
        view->handle = CD3DX12_CPU_DESCRIPTOR_HANDLE(device->dsvHeap->GetCPUDescriptorHandleForHeapStart());

        D3D12_DEPTH_STENCIL_VIEW_DESC desc = {};
        desc.Format                        = format;
        switch (pCreateInfo->viewType)
        {
        case VK_IMAGE_VIEW_TYPE_1D:
            desc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE1D;
            break;
        case VK_IMAGE_VIEW_TYPE_2D:
            desc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
            break;
        case VK_IMAGE_VIEW_TYPE_1D_ARRAY:
            desc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE1DARRAY;
            break;
        case VK_IMAGE_VIEW_TYPE_2D_ARRAY:
            desc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2DARRAY;
            break;
        default:
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        device->device->CreateDepthStencilView(pCreateInfo->image->Get(), &desc, view->handle);
        view->handle.Offset(device->device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_DSV));
    }

    *pView = view;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkCreateImageView(
    VkDevice                     device,
    const VkImageViewCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkImageView*                 pView)
{
    return VulkanOnD3D12CreateImageView(
        device,
        pCreateInfo,
        pAllocator,
        pView);
}
}
