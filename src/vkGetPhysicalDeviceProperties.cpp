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

void VKAPI_CALL VulkanOnD3D12GetPhysicalDeviceProperties(
    VkPhysicalDevice            physicalDevice,
    VkPhysicalDeviceProperties* pProperties)
{
    VkPhysicalDeviceLimits limits                          = {};
    limits.maxImageDimension1D                             = D3D12_REQ_TEXTURE1D_U_DIMENSION;
    limits.maxImageDimension2D                             = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    limits.maxImageDimension3D                             = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
    limits.maxImageDimensionCube                           = D3D12_REQ_TEXTURECUBE_DIMENSION;
    limits.maxImageArrayLayers                             = D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION;
    limits.maxTexelBufferElements                          = 0;
    limits.maxUniformBufferRange                           = 0;
    limits.maxStorageBufferRange                           = 0;
    limits.maxPushConstantsSize                            = 0;
    limits.maxMemoryAllocationCount                        = 0;
    limits.maxSamplerAllocationCount                       = 0;
    limits.bufferImageGranularity                          = 0;
    limits.sparseAddressSpaceSize                          = 0;
    limits.maxBoundDescriptorSets                          = 0;
    limits.maxPerStageDescriptorSamplers                   = 0;
    limits.maxPerStageDescriptorUniformBuffers             = 0;
    limits.maxPerStageDescriptorStorageBuffers             = 0;
    limits.maxPerStageDescriptorSampledImages              = 0;
    limits.maxPerStageDescriptorStorageImages              = 0;
    limits.maxPerStageDescriptorInputAttachments           = 0;
    limits.maxPerStageResources                            = 0;
    limits.maxDescriptorSetSamplers                        = 0;
    limits.maxDescriptorSetUniformBuffers                  = 0;
    limits.maxDescriptorSetUniformBuffersDynamic           = 0;
    limits.maxDescriptorSetStorageBuffers                  = 0;
    limits.maxDescriptorSetStorageBuffersDynamic           = 0;
    limits.maxDescriptorSetSampledImages                   = 0;
    limits.maxDescriptorSetStorageImages                   = 0;
    limits.maxDescriptorSetInputAttachments                = 0;
    limits.maxVertexInputAttributes                        = 0;
    limits.maxVertexInputBindings                          = 0;
    limits.maxVertexInputAttributeOffset                   = 0;
    limits.maxVertexInputBindingStride                     = 0;
    limits.maxVertexOutputComponents                       = 0;
    limits.maxTessellationGenerationLevel                  = 0;
    limits.maxTessellationPatchSize                        = 0;
    limits.maxTessellationControlPerVertexInputComponents  = 0;
    limits.maxTessellationControlPerVertexOutputComponents = 0;
    limits.maxTessellationControlPerPatchOutputComponents  = 0;
    limits.maxTessellationControlTotalOutputComponents     = 0;
    limits.maxTessellationEvaluationInputComponents        = 0;
    limits.maxTessellationEvaluationOutputComponents       = 0;
    limits.maxGeometryShaderInvocations                    = 0;
    limits.maxGeometryInputComponents                      = 0;
    limits.maxGeometryOutputComponents                     = 0;
    limits.maxGeometryOutputVertices                       = 0;
    limits.maxGeometryTotalOutputComponents                = 0;
    limits.maxFragmentInputComponents                      = 0;
    limits.maxFragmentOutputAttachments                    = 0;
    limits.maxFragmentDualSrcAttachments                   = 0;
    limits.maxFragmentCombinedOutputResources              = 0;
    limits.maxComputeSharedMemorySize                      = 0;
    limits.maxComputeWorkGroupCount[0]                     = 0;
    limits.maxComputeWorkGroupCount[1]                     = 0;
    limits.maxComputeWorkGroupCount[2]                     = 0;
    limits.maxComputeWorkGroupInvocations                  = D3D12_CS_THREAD_GROUP_MAX_THREADS_PER_GROUP;
    limits.maxComputeWorkGroupSize[0]                      = D3D12_CS_THREAD_GROUP_MAX_X;
    limits.maxComputeWorkGroupSize[1]                      = D3D12_CS_THREAD_GROUP_MAX_Y;
    limits.maxComputeWorkGroupSize[2]                      = D3D12_CS_THREAD_GROUP_MAX_Z;
    limits.subPixelPrecisionBits                           = D3D12_SUBPIXEL_FRACTIONAL_BIT_COUNT;
    limits.subTexelPrecisionBits                           = D3D12_SUBTEXEL_FRACTIONAL_BIT_COUNT;
    limits.mipmapPrecisionBits                             = 0;
    limits.maxDrawIndexedIndexValue                        = 0;
    limits.maxDrawIndirectCount                            = 0;
    limits.maxSamplerLodBias                               = 0;
    limits.maxSamplerAnisotropy                            = 0;
    limits.maxViewports                                    = D3D12_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE;
    limits.maxViewportDimensions[0]                        = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    limits.maxViewportDimensions[1]                        = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    limits.viewportBoundsRange[0]                          = D3D12_VIEWPORT_BOUNDS_MIN;
    limits.viewportBoundsRange[1]                          = D3D12_VIEWPORT_BOUNDS_MAX;
    limits.viewportSubPixelBits                            = 0;
    limits.minMemoryMapAlignment                           = 0;
    limits.minTexelBufferOffsetAlignment                   = 0;
    limits.minUniformBufferOffsetAlignment                 = 0;
    limits.minStorageBufferOffsetAlignment                 = 0;
    limits.minTexelOffset                                  = D3D12_COMMONSHADER_TEXEL_OFFSET_MAX_NEGATIVE;
    limits.maxTexelOffset                                  = D3D12_COMMONSHADER_TEXEL_OFFSET_MAX_POSITIVE;
    limits.minTexelGatherOffset                            = 0;
    limits.maxTexelGatherOffset                            = 0;
    limits.minInterpolationOffset                          = 0;
    limits.maxInterpolationOffset                          = 0;
    limits.subPixelInterpolationOffsetBits                 = 0;
    limits.maxFramebufferWidth                             = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    limits.maxFramebufferHeight                            = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    limits.maxFramebufferLayers                            = D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION;
    limits.framebufferColorSampleCounts                    = D3D12_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT;
    limits.framebufferDepthSampleCounts                    = D3D12_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT;
    limits.framebufferStencilSampleCounts                  = D3D12_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT;
    limits.framebufferNoAttachmentsSampleCounts            = D3D12_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT;
    limits.maxColorAttachments                             = 0;
    limits.sampledImageColorSampleCounts                   = D3D12_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT;
    limits.sampledImageIntegerSampleCounts                 = D3D12_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT;
    limits.sampledImageDepthSampleCounts                   = D3D12_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT;
    limits.sampledImageStencilSampleCounts                 = D3D12_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT;
    limits.storageImageSampleCounts                        = D3D12_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT;
    limits.maxSampleMaskWords                              = 0;
    limits.timestampComputeAndGraphics                     = 0;
    limits.timestampPeriod                                 = 0;
    limits.maxClipDistances                                = D3D12_CLIP_OR_CULL_DISTANCE_COUNT;
    limits.maxCullDistances                                = D3D12_CLIP_OR_CULL_DISTANCE_COUNT;
    limits.maxCombinedClipAndCullDistances                 = D3D12_CLIP_OR_CULL_DISTANCE_COUNT;
    limits.discreteQueuePriorities                         = 0;
    limits.pointSizeRange[0]                               = 0;
    limits.pointSizeRange[1]                               = 0;
    limits.lineWidthRange[0]                               = 0;
    limits.lineWidthRange[1]                               = 0;
    limits.pointSizeGranularity                            = 0;
    limits.lineWidthGranularity                            = 0;
    limits.strictLines                                     = 0;
    limits.standardSampleLocations                         = 0;
    limits.optimalBufferCopyOffsetAlignment                = 0;
    limits.optimalBufferCopyRowPitchAlignment              = 0;
    limits.nonCoherentAtomSize                             = 0;

    VkPhysicalDeviceSparseProperties sparseProperties         = {};
    sparseProperties.residencyStandard2DBlockShape            = 0;
    sparseProperties.residencyStandard2DMultisampleBlockShape = 0;
    sparseProperties.residencyStandard3DBlockShape            = 0;
    sparseProperties.residencyAlignedMipSize                  = 0;
    sparseProperties.residencyNonResidentStrict               = 0;

    VkPhysicalDeviceProperties properties = {};
    properties.apiVersion                 = VK_MAKE_VERSION(VK_VERSION_MAJOR(VK_API_VERSION_1_0), VK_VERSION_MINOR(VK_API_VERSION_1_0), VK_VERSION_PATCH(VK_HEADER_VERSION));
    properties.driverVersion              = physicalDevice->desc.Revision;
    properties.vendorID                   = physicalDevice->desc.VendorId;
    properties.deviceID                   = physicalDevice->desc.DeviceId;
    properties.deviceType                 = VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;
    properties.limits                     = limits;
    properties.sparseProperties           = sparseProperties;

    snprintf(reinterpret_cast<char*>(&properties.pipelineCacheUUID), VK_UUID_SIZE, "chb-%i", physicalDevice->desc.AdapterLuid.LowPart);
    wcstombs_s(nullptr, properties.deviceName, physicalDevice->desc.Description, 256);

    *pProperties = properties;
}

extern "C" {
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties(
    VkPhysicalDevice            physicalDevice,
    VkPhysicalDeviceProperties* pProperties)
{
    VulkanOnD3D12GetPhysicalDeviceProperties(
        physicalDevice,
        pProperties);
}
}
