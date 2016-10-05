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

void VKAPI_CALL VulkanOnD3D12GetPhysicalDeviceFormatProperties(
    VkPhysicalDevice    physicalDevice,
    VkFormat            format,
    VkFormatProperties* pFormatProperties)
{
    VkFormatProperties formatProperties = {};

    switch (format)
    {
    case VK_FORMAT_UNDEFINED:
        break;
    case VK_FORMAT_R4G4_UNORM_PACK8:
        break;
    case VK_FORMAT_R4G4B4A4_UNORM_PACK16:
        break;
    case VK_FORMAT_B4G4R4A4_UNORM_PACK16:
        break;
    case VK_FORMAT_R5G6B5_UNORM_PACK16:
        break;
    case VK_FORMAT_B5G6R5_UNORM_PACK16:
        break;
    case VK_FORMAT_R5G5B5A1_UNORM_PACK16:
        break;
    case VK_FORMAT_B5G5R5A1_UNORM_PACK16:
        break;
    case VK_FORMAT_A1R5G5B5_UNORM_PACK16:
        break;
    case VK_FORMAT_R8_UNORM:
        break;
    case VK_FORMAT_R8_SNORM:
        break;
    case VK_FORMAT_R8_USCALED:
        break;
    case VK_FORMAT_R8_SSCALED:
        break;
    case VK_FORMAT_R8_UINT:
        break;
    case VK_FORMAT_R8_SINT:
        break;
    case VK_FORMAT_R8_SRGB:
        break;
    case VK_FORMAT_R8G8_UNORM:
        break;
    case VK_FORMAT_R8G8_SNORM:
        break;
    case VK_FORMAT_R8G8_USCALED:
        break;
    case VK_FORMAT_R8G8_SSCALED:
        break;
    case VK_FORMAT_R8G8_UINT:
        break;
    case VK_FORMAT_R8G8_SINT:
        break;
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
        formatProperties.linearTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.optimalTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.bufferFeatures =
            VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT;
        break;
    case VK_FORMAT_R8G8B8A8_SNORM:
        formatProperties.linearTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.optimalTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.bufferFeatures =
            VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT;
        break;
    case VK_FORMAT_R8G8B8A8_USCALED:
        break;
    case VK_FORMAT_R8G8B8A8_SSCALED:
        break;
    case VK_FORMAT_R8G8B8A8_UINT:
        formatProperties.linearTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.optimalTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.bufferFeatures =
            VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT;
        break;
    case VK_FORMAT_R8G8B8A8_SINT:
        formatProperties.linearTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.optimalTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.bufferFeatures =
            VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT;
        break;
    case VK_FORMAT_R8G8B8A8_SRGB:
        break;
    case VK_FORMAT_B8G8R8A8_UNORM:
        formatProperties.linearTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.optimalTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.bufferFeatures =
            VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT;
        break;
    case VK_FORMAT_B8G8R8A8_SNORM:
        formatProperties.linearTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.optimalTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.bufferFeatures =
            VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT;
        break;
    case VK_FORMAT_B8G8R8A8_USCALED:
        break;
    case VK_FORMAT_B8G8R8A8_SSCALED:
        break;
    case VK_FORMAT_B8G8R8A8_UINT:
        formatProperties.linearTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.optimalTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.bufferFeatures =
            VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT;
        break;
    case VK_FORMAT_B8G8R8A8_SINT:
        formatProperties.linearTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.optimalTilingFeatures =
            VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
        formatProperties.bufferFeatures =
            VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT;
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
        break;
    case VK_FORMAT_R16_SNORM:
        break;
    case VK_FORMAT_R16_USCALED:
        break;
    case VK_FORMAT_R16_SSCALED:
        break;
    case VK_FORMAT_R16_UINT:
        break;
    case VK_FORMAT_R16_SINT:
        break;
    case VK_FORMAT_R16_SFLOAT:
        break;
    case VK_FORMAT_R16G16_UNORM:
        break;
    case VK_FORMAT_R16G16_SNORM:
        break;
    case VK_FORMAT_R16G16_USCALED:
        break;
    case VK_FORMAT_R16G16_SSCALED:
        break;
    case VK_FORMAT_R16G16_UINT:
        break;
    case VK_FORMAT_R16G16_SINT:
        break;
    case VK_FORMAT_R16G16_SFLOAT:
        break;
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
        break;
    case VK_FORMAT_R16G16B16A16_SNORM:
        break;
    case VK_FORMAT_R16G16B16A16_USCALED:
        break;
    case VK_FORMAT_R16G16B16A16_SSCALED:
        break;
    case VK_FORMAT_R16G16B16A16_UINT:
        break;
    case VK_FORMAT_R16G16B16A16_SINT:
        break;
    case VK_FORMAT_R16G16B16A16_SFLOAT:
        break;
    case VK_FORMAT_R32_UINT:
        break;
    case VK_FORMAT_R32_SINT:
        break;
    case VK_FORMAT_R32_SFLOAT:
        break;
    case VK_FORMAT_R32G32_UINT:
        break;
    case VK_FORMAT_R32G32_SINT:
        break;
    case VK_FORMAT_R32G32_SFLOAT:
        break;
    case VK_FORMAT_R32G32B32_UINT:
        break;
    case VK_FORMAT_R32G32B32_SINT:
        break;
    case VK_FORMAT_R32G32B32_SFLOAT:
        break;
    case VK_FORMAT_R32G32B32A32_UINT:
        break;
    case VK_FORMAT_R32G32B32A32_SINT:
        break;
    case VK_FORMAT_R32G32B32A32_SFLOAT:
        break;
    case VK_FORMAT_R64_UINT:
        break;
    case VK_FORMAT_R64_SINT:
        break;
    case VK_FORMAT_R64_SFLOAT:
        break;
    case VK_FORMAT_R64G64_UINT:
        break;
    case VK_FORMAT_R64G64_SINT:
        break;
    case VK_FORMAT_R64G64_SFLOAT:
        break;
    case VK_FORMAT_R64G64B64_UINT:
        break;
    case VK_FORMAT_R64G64B64_SINT:
        break;
    case VK_FORMAT_R64G64B64_SFLOAT:
        break;
    case VK_FORMAT_R64G64B64A64_UINT:
        break;
    case VK_FORMAT_R64G64B64A64_SINT:
        break;
    case VK_FORMAT_R64G64B64A64_SFLOAT:
        break;
    case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
        break;
    case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
        break;
    case VK_FORMAT_D16_UNORM:
        break;
    case VK_FORMAT_X8_D24_UNORM_PACK32:
        break;
    case VK_FORMAT_D32_SFLOAT:
        break;
    case VK_FORMAT_S8_UINT:
        break;
    case VK_FORMAT_D16_UNORM_S8_UINT:
        break;
    case VK_FORMAT_D24_UNORM_S8_UINT:
        break;
    case VK_FORMAT_D32_SFLOAT_S8_UINT:
        break;
    case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
        break;
    case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
        break;
    case VK_FORMAT_BC2_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC2_SRGB_BLOCK:
        break;
    case VK_FORMAT_BC3_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC3_SRGB_BLOCK:
        break;
    case VK_FORMAT_BC4_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC4_SNORM_BLOCK:
        break;
    case VK_FORMAT_BC5_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC5_SNORM_BLOCK:
        break;
    case VK_FORMAT_BC6H_UFLOAT_BLOCK:
        break;
    case VK_FORMAT_BC6H_SFLOAT_BLOCK:
        break;
    case VK_FORMAT_BC7_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC7_SRGB_BLOCK:
        break;
    default:
        break;
    }

    *pFormatProperties = formatProperties;
}

extern "C" {
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties(
    VkPhysicalDevice    physicalDevice,
    VkFormat            format,
    VkFormatProperties* pFormatProperties)
{
    VulkanOnD3D12GetPhysicalDeviceFormatProperties(
        physicalDevice,
        format,
        pFormatProperties);
}
}
