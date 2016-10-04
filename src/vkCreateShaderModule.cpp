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

VkResult VKAPI_CALL VulkanOnD3D12CreateShaderModule(
    VkDevice                        device,
    const VkShaderModuleCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*    pAllocator,
    VkShaderModule*                 pShaderModule)
{
    VkShaderModule shaderModule;
    if (pAllocator)
    {
        shaderModule = reinterpret_cast<VkShaderModule>(pAllocator->pfnAllocation(nullptr, sizeof(VkShaderModule_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));
    }
    else
    {
        shaderModule = new VkShaderModule_T();
    }

    D3D12_SHADER_BYTECODE data = {};

    std::string type(reinterpret_cast<const char*>(pCreateInfo->pCode));
    type.resize(4);

    if (type == "DXBC")
    {
        data.pShaderBytecode = pCreateInfo->pCode;
        data.BytecodeLength  = pCreateInfo->codeSize;
    }
    else
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    shaderModule->data = data;

    *pShaderModule = shaderModule;

    return VK_SUCCESS;
}

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL vkCreateShaderModule(
    VkDevice                        device,
    const VkShaderModuleCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*    pAllocator,
    VkShaderModule*                 pShaderModule)
{
    return VulkanOnD3D12CreateShaderModule(
        device,
        pCreateInfo,
        pAllocator,
        pShaderModule);
}
}
