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

VKAPI_ATTR void VKAPI_CALL VulkanOnD3D12CmdResolveImage(
    VkCommandBuffer       commandBuffer,
    VkImage               srcImage,
    VkImageLayout         srcImageLayout,
    VkImage               dstImage,
    VkImageLayout         dstImageLayout,
    uint32_t              regionCount,
    const VkImageResolve* pRegions)
{
}

extern "C" {
VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage(
    VkCommandBuffer       commandBuffer,
    VkImage               srcImage,
    VkImageLayout         srcImageLayout,
    VkImage               dstImage,
    VkImageLayout         dstImageLayout,
    uint32_t              regionCount,
    const VkImageResolve* pRegions)
{
    VulkanOnD3D12CmdResolveImage(
        commandBuffer,
        srcImage,
        srcImageLayout,
        dstImage,
        dstImageLayout,
        regionCount,
        pRegions);
}
}
