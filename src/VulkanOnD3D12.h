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

#pragma once

#if WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
#ifndef VK_USE_PLATFORM_WIN32_KHR
#define VK_USE_PLATFORM_WIN32_KHR
#endif // !VK_USE_PLATFORM_WIN32_KHR
#else
#ifndef VK_USE_PLATFORM_UAP_CHB
#define VK_USE_PLATFORM_UAP_CHB
#endif // !VK_USE_PLATFORM_UAP_CHB
#endif // WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
#include <vulkan/vulkan.h>

#include "VulkanOnD3D12Types.h"

inline auto VkResultFromHRESULT(HRESULT hr)
{
    switch (hr)
    {
    case E_OUTOFMEMORY:
        return VK_ERROR_OUT_OF_HOST_MEMORY;
    case DXGI_ERROR_UNSUPPORTED:
        return VK_ERROR_INITIALIZATION_FAILED;
    default:
        return VK_ERROR_INITIALIZATION_FAILED;
    }
}

inline auto VkFormatToD3D12(VkFormat format)
{
    switch (format)
    {
    case VK_FORMAT_UNDEFINED:
        break;
    case VK_FORMAT_R4G4_UNORM_PACK8:
        break;
    case VK_FORMAT_R4G4B4A4_UNORM_PACK16:
        break;
    case VK_FORMAT_B4G4R4A4_UNORM_PACK16:
        return DXGI_FORMAT_B4G4R4A4_UNORM;
        break;
    case VK_FORMAT_R5G6B5_UNORM_PACK16:
        break;
    case VK_FORMAT_B5G6R5_UNORM_PACK16:
        return DXGI_FORMAT_B5G6R5_UNORM;
        break;
    case VK_FORMAT_R5G5B5A1_UNORM_PACK16:
        break;
    case VK_FORMAT_B5G5R5A1_UNORM_PACK16:
        return DXGI_FORMAT_B5G5R5A1_UNORM;
        break;
    case VK_FORMAT_A1R5G5B5_UNORM_PACK16:
        break;
    case VK_FORMAT_R8_UNORM:
        return DXGI_FORMAT_R8_UNORM;
        break;
    case VK_FORMAT_R8_SNORM:
        return DXGI_FORMAT_R8_SNORM;
        break;
    case VK_FORMAT_R8_USCALED:
        break;
    case VK_FORMAT_R8_SSCALED:
        break;
    case VK_FORMAT_R8_UINT:
        return DXGI_FORMAT_R8_UINT;
        break;
    case VK_FORMAT_R8_SINT:
        return DXGI_FORMAT_R8_SINT;
        break;
    case VK_FORMAT_R8_SRGB:
        break;
    case VK_FORMAT_R8G8_UNORM:
        return DXGI_FORMAT_R8G8_UNORM;
        break;
    case VK_FORMAT_R8G8_SNORM:
        return DXGI_FORMAT_R8G8_SNORM;
        break;
    case VK_FORMAT_R8G8_USCALED:
        break;
    case VK_FORMAT_R8G8_SSCALED:
        break;
    case VK_FORMAT_R8G8_UINT:
        return DXGI_FORMAT_R8G8_UINT;
    case VK_FORMAT_R8G8_SINT:
        return DXGI_FORMAT_R8G8_SINT;
    case VK_FORMAT_R8G8_SRGB:
        break;
    case VK_FORMAT_R8G8B8_UNORM:
        break;
    case VK_FORMAT_R8G8B8_SNORM:
        break;
    case VK_FORMAT_R8G8B8_USCALED:
        break;
    case VK_FORMAT_R8G8B8_SSCALED:
        break;
    case VK_FORMAT_R8G8B8_UINT:
        break;
    case VK_FORMAT_R8G8B8_SINT:
        break;
    case VK_FORMAT_R8G8B8_SRGB:
        break;
    case VK_FORMAT_B8G8R8_UNORM:
        break;
    case VK_FORMAT_B8G8R8_SNORM:
        break;
    case VK_FORMAT_B8G8R8_USCALED:
        break;
    case VK_FORMAT_B8G8R8_SSCALED:
        break;
    case VK_FORMAT_B8G8R8_UINT:
        break;
    case VK_FORMAT_B8G8R8_SINT:
        break;
    case VK_FORMAT_B8G8R8_SRGB:
        break;
    case VK_FORMAT_R8G8B8A8_UNORM:
        return DXGI_FORMAT_R8G8B8A8_UNORM;
    case VK_FORMAT_R8G8B8A8_SNORM:
        return DXGI_FORMAT_R8G8B8A8_SNORM;
    case VK_FORMAT_R8G8B8A8_USCALED:
        break;
    case VK_FORMAT_R8G8B8A8_SSCALED:
        break;
    case VK_FORMAT_R8G8B8A8_UINT:
        return DXGI_FORMAT_R8G8B8A8_UINT;
    case VK_FORMAT_R8G8B8A8_SINT:
        return DXGI_FORMAT_R8G8B8A8_SINT;
    case VK_FORMAT_R8G8B8A8_SRGB:
        return DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
    case VK_FORMAT_B8G8R8A8_UNORM:
        return DXGI_FORMAT_B8G8R8A8_UNORM;
    case VK_FORMAT_B8G8R8A8_SNORM:
        break;
    case VK_FORMAT_B8G8R8A8_USCALED:
        break;
    case VK_FORMAT_B8G8R8A8_SSCALED:
        break;
    case VK_FORMAT_B8G8R8A8_UINT:
        break;
    case VK_FORMAT_B8G8R8A8_SINT:
        break;
    case VK_FORMAT_B8G8R8A8_SRGB:
        break;
    case VK_FORMAT_A8B8G8R8_UNORM_PACK32:
        break;
    case VK_FORMAT_A8B8G8R8_SNORM_PACK32:
        break;
    case VK_FORMAT_A8B8G8R8_USCALED_PACK32:
        break;
    case VK_FORMAT_A8B8G8R8_SSCALED_PACK32:
        break;
    case VK_FORMAT_A8B8G8R8_UINT_PACK32:
        break;
    case VK_FORMAT_A8B8G8R8_SINT_PACK32:
        break;
    case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
        break;
    case VK_FORMAT_A2R10G10B10_UNORM_PACK32:
        break;
    case VK_FORMAT_A2R10G10B10_SNORM_PACK32:
        break;
    case VK_FORMAT_A2R10G10B10_USCALED_PACK32:
        break;
    case VK_FORMAT_A2R10G10B10_SSCALED_PACK32:
        break;
    case VK_FORMAT_A2R10G10B10_UINT_PACK32:
        break;
    case VK_FORMAT_A2R10G10B10_SINT_PACK32:
        break;
    case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
        break;
    case VK_FORMAT_A2B10G10R10_SNORM_PACK32:
        break;
    case VK_FORMAT_A2B10G10R10_USCALED_PACK32:
        break;
    case VK_FORMAT_A2B10G10R10_SSCALED_PACK32:
        break;
    case VK_FORMAT_A2B10G10R10_UINT_PACK32:
        break;
    case VK_FORMAT_A2B10G10R10_SINT_PACK32:
        break;
    case VK_FORMAT_R16_UNORM:
        return DXGI_FORMAT_R16_UNORM;
    case VK_FORMAT_R16_SNORM:
        return DXGI_FORMAT_R16_SNORM;
    case VK_FORMAT_R16_USCALED:
        break;
    case VK_FORMAT_R16_SSCALED:
        break;
    case VK_FORMAT_R16_UINT:
        return DXGI_FORMAT_R16_UINT;
    case VK_FORMAT_R16_SINT:
        return DXGI_FORMAT_R16_SINT;
    case VK_FORMAT_R16_SFLOAT:
        return DXGI_FORMAT_R16_FLOAT;
    case VK_FORMAT_R16G16_UNORM:
        return DXGI_FORMAT_R16G16_UNORM;
    case VK_FORMAT_R16G16_SNORM:
        return DXGI_FORMAT_R16G16_SNORM;
    case VK_FORMAT_R16G16_USCALED:
        break;
    case VK_FORMAT_R16G16_SSCALED:
        break;
    case VK_FORMAT_R16G16_UINT:
        return DXGI_FORMAT_R16G16_UINT;
    case VK_FORMAT_R16G16_SINT:
        return DXGI_FORMAT_R16G16_SINT;
    case VK_FORMAT_R16G16_SFLOAT:
        return DXGI_FORMAT_R16G16_FLOAT;
    case VK_FORMAT_R16G16B16_UNORM:
        break;
    case VK_FORMAT_R16G16B16_SNORM:
        break;
    case VK_FORMAT_R16G16B16_USCALED:
        break;
    case VK_FORMAT_R16G16B16_SSCALED:
        break;
    case VK_FORMAT_R16G16B16_UINT:
        break;
    case VK_FORMAT_R16G16B16_SINT:
        break;
    case VK_FORMAT_R16G16B16_SFLOAT:
        break;
    case VK_FORMAT_R16G16B16A16_UNORM:
        return DXGI_FORMAT_R16G16B16A16_UNORM;
    case VK_FORMAT_R16G16B16A16_SNORM:
        return DXGI_FORMAT_R16G16B16A16_SNORM;
    case VK_FORMAT_R16G16B16A16_USCALED:
        break;
    case VK_FORMAT_R16G16B16A16_SSCALED:
        break;
    case VK_FORMAT_R16G16B16A16_UINT:
        return DXGI_FORMAT_R16G16B16A16_UINT;
    case VK_FORMAT_R16G16B16A16_SINT:
        return DXGI_FORMAT_R16G16B16A16_SINT;
    case VK_FORMAT_R16G16B16A16_SFLOAT:
        return DXGI_FORMAT_R16G16B16A16_FLOAT;
    case VK_FORMAT_R32_UINT:
        return DXGI_FORMAT_R32_UINT;
    case VK_FORMAT_R32_SINT:
        return DXGI_FORMAT_R32_SINT;
    case VK_FORMAT_R32_SFLOAT:
        return DXGI_FORMAT_R32_FLOAT;
    case VK_FORMAT_R32G32_UINT:
        return DXGI_FORMAT_R32G32_UINT;
    case VK_FORMAT_R32G32_SINT:
        return DXGI_FORMAT_R32G32_SINT;
    case VK_FORMAT_R32G32_SFLOAT:
        return DXGI_FORMAT_R32G32_FLOAT;
    case VK_FORMAT_R32G32B32_UINT:
        return DXGI_FORMAT_R32G32B32_UINT;
    case VK_FORMAT_R32G32B32_SINT:
        return DXGI_FORMAT_R32G32B32_SINT;
    case VK_FORMAT_R32G32B32_SFLOAT:
        return DXGI_FORMAT_R32G32B32_FLOAT;
    case VK_FORMAT_R32G32B32A32_UINT:
        return DXGI_FORMAT_R32G32B32A32_UINT;
    case VK_FORMAT_R32G32B32A32_SINT:
        return DXGI_FORMAT_R32G32B32A32_SINT;
    case VK_FORMAT_R32G32B32A32_SFLOAT:
        return DXGI_FORMAT_R32G32B32A32_FLOAT;
    case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
        break;
    case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
        break;
    case VK_FORMAT_D16_UNORM:
        return DXGI_FORMAT_D16_UNORM;
    case VK_FORMAT_X8_D24_UNORM_PACK32:
        break;
    case VK_FORMAT_D32_SFLOAT:
        return DXGI_FORMAT_D32_FLOAT;
    case VK_FORMAT_S8_UINT:
        break;
    case VK_FORMAT_D16_UNORM_S8_UINT:
        break;
    case VK_FORMAT_D24_UNORM_S8_UINT:
        return DXGI_FORMAT_D24_UNORM_S8_UINT;
    case VK_FORMAT_D32_SFLOAT_S8_UINT:
        return DXGI_FORMAT_D32_FLOAT_S8X24_UINT;
    case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
        return DXGI_FORMAT_BC1_UNORM;
    case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
        return DXGI_FORMAT_BC1_UNORM_SRGB;
    case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
        return DXGI_FORMAT_BC1_UNORM;
    case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
        return DXGI_FORMAT_BC1_UNORM_SRGB;
    case VK_FORMAT_BC2_UNORM_BLOCK:
        return DXGI_FORMAT_BC2_UNORM;
    case VK_FORMAT_BC2_SRGB_BLOCK:
        return DXGI_FORMAT_BC2_UNORM_SRGB;
    case VK_FORMAT_BC3_UNORM_BLOCK:
        return DXGI_FORMAT_BC3_UNORM;
    case VK_FORMAT_BC3_SRGB_BLOCK:
        return DXGI_FORMAT_BC3_UNORM_SRGB;
    case VK_FORMAT_BC4_UNORM_BLOCK:
        return DXGI_FORMAT_BC4_UNORM;
    case VK_FORMAT_BC4_SNORM_BLOCK:
        return DXGI_FORMAT_BC4_SNORM;
    case VK_FORMAT_BC5_UNORM_BLOCK:
        return DXGI_FORMAT_BC5_UNORM;
    case VK_FORMAT_BC5_SNORM_BLOCK:
        return DXGI_FORMAT_BC5_SNORM;
    case VK_FORMAT_BC6H_UFLOAT_BLOCK:
        return DXGI_FORMAT_BC6H_UF16;
    case VK_FORMAT_BC6H_SFLOAT_BLOCK:
        return DXGI_FORMAT_BC6H_SF16;
    case VK_FORMAT_BC7_UNORM_BLOCK:
        return DXGI_FORMAT_BC7_UNORM;
    case VK_FORMAT_BC7_SRGB_BLOCK:
        return DXGI_FORMAT_BC7_UNORM_SRGB;
    default:
        break;
    }
    return DXGI_FORMAT_UNKNOWN;
}
