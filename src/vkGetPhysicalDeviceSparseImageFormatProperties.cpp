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

void VKAPI_CALL VulkanOnD3D12GetPhysicalDeviceSparseImageFormatProperties(
    VkPhysicalDevice               physicalDevice,
    VkFormat                       format,
    VkImageType                    type,
    VkSampleCountFlagBits          samples,
    VkImageUsageFlags              usage,
    VkImageTiling                  tiling,
    uint32_t*                      pPropertyCount,
    VkSparseImageFormatProperties* pProperties)
{
}

extern "C" {
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties(
    VkPhysicalDevice               physicalDevice,
    VkFormat                       format,
    VkImageType                    type,
    VkSampleCountFlagBits          samples,
    VkImageUsageFlags              usage,
    VkImageTiling                  tiling,
    uint32_t*                      pPropertyCount,
    VkSparseImageFormatProperties* pProperties)
{
    return VulkanOnD3D12GetPhysicalDeviceSparseImageFormatProperties(
        physicalDevice,
        format,
        type,
        samples,
        usage,
        tiling,
        pPropertyCount,
        pProperties);
}
}
