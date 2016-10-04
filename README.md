# VulkanOnD3D12

VulkanOnD3D12 aims to make the Vulkan API available to platforms where only a
D3D12 driver is available, such as Windows UAP.

## Usage

An example using the VK_CHB_uap_surface extension to create a VkSurface for a
Windows::UI::Core::CoreWindow.

```
void App::SetWindow(CoreWindow^ window)
{
    VkUAPSurfaceCreateInfoCHB surfaceCreateInfo = {};
    surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_UAP_SURFACE_CREATE_INFO_CHB;
    surfaceCreateInfo.pNext = nullptr;
    surfaceCreateInfo.flags = 0;
    surfaceCreateInfo.window = reinterpret_cast<IUnknown*>(window);

    VkResult res;
    res = vkCreateUAPSurfaceCHB(instance, &surfaceCreateInfo, nullptr, &surface);
    if (res != VK_SUCCESS)
    {
        // Handle error here
    }
}
```
