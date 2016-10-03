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

void VKAPI_CALL VulkanOnD3D12GetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                  physicalDevice,
    VkPhysicalDeviceMemoryProperties* pMemoryProperties)
{
    DXGI_QUERY_VIDEO_MEMORY_INFO localInfo = {};
    physicalDevice->adapter->QueryVideoMemoryInfo(physicalDevice->index, DXGI_MEMORY_SEGMENT_GROUP_LOCAL, &localInfo);

    DXGI_QUERY_VIDEO_MEMORY_INFO nonLocalInfo = {};
    physicalDevice->adapter->QueryVideoMemoryInfo(physicalDevice->index, DXGI_MEMORY_SEGMENT_GROUP_NON_LOCAL, &nonLocalInfo);

    VkPhysicalDeviceMemoryProperties memoryProperties = {};
    memoryProperties.memoryTypeCount                  = 2;
    memoryProperties.memoryTypes[0].propertyFlags     = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
    memoryProperties.memoryTypes[0].heapIndex         = 0;
    memoryProperties.memoryTypes[1].propertyFlags     = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
    memoryProperties.memoryTypes[1].heapIndex         = 1;
    memoryProperties.memoryHeapCount                  = 2;
    memoryProperties.memoryHeaps[0].size              = localInfo.Budget;
    memoryProperties.memoryHeaps[0].flags             = VK_MEMORY_HEAP_DEVICE_LOCAL_BIT;
    memoryProperties.memoryHeaps[1].size              = nonLocalInfo.Budget;
    memoryProperties.memoryHeaps[1].flags             = 0;

    *pMemoryProperties = memoryProperties;
}

extern "C" {
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                  physicalDevice,
    VkPhysicalDeviceMemoryProperties* pMemoryProperties)
{
    VulkanOnD3D12GetPhysicalDeviceMemoryProperties(
        physicalDevice,
        pMemoryProperties);
}
}
