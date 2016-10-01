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

#include "VulkanOnD3D12Types.h"

#include <wrl.h>

#include <vector>

using namespace Microsoft::WRL;

inline auto VkResultFromHRESULT(HRESULT hr)
{
    switch (hr)
    {
    case E_OUTOFMEMORY:
        return VK_ERROR_OUT_OF_HOST_MEMORY;
    case DXGI_ERROR_UNSUPPORTED:
        return VK_ERROR_INCOMPATIBLE_DRIVER;
    default:
        return VK_ERROR_INITIALIZATION_FAILED;
    }
}
