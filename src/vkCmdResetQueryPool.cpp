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

void VKAPI_CALL VulkanOnD3D12CmdResetQueryPool(
    VkCommandBuffer commandBuffer,
    VkQueryPool     queryPool,
    uint32_t        firstQuery,
    uint32_t        queryCount)
{
}

extern "C" {
VKAPI_ATTR void VKAPI_CALL vkCmdResetQueryPool(
    VkCommandBuffer commandBuffer,
    VkQueryPool     queryPool,
    uint32_t        firstQuery,
    uint32_t        queryCount)
{
    VulkanOnD3D12CmdResetQueryPool(
        commandBuffer,
        queryPool,
        firstQuery,
        queryCount);
}
}
