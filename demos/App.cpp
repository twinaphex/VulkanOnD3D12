#include "App.h"

using namespace Windows;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::Foundation;
using namespace Windows::UI;
using namespace Windows::UI::Core;

namespace UAPExample
{
    App::App()
    {
    }

    void App::Initialize(CoreApplicationView ^ applicationView)
    {
        applicationView->Activated +=
            ref new TypedEventHandler<CoreApplicationView ^, IActivatedEventArgs ^>(this, &App::OnActivated);

        VkResult res;

        VkInstanceCreateInfo instanceCreateInfo = {};
        res                                     = vkCreateInstance(&instanceCreateInfo, nullptr, &instance_);
        if (res != VK_SUCCESS)
        {
            throw std::runtime_error("vkCreateInstance failed");
        }

        uint32_t                      numPhysicalDevices;
        std::vector<VkPhysicalDevice> physicalDevices;
        res = vkEnumeratePhysicalDevices(instance_, &numPhysicalDevices, nullptr);
        if (res != VK_SUCCESS)
        {
            throw std::runtime_error("vkEnumeratePhysicalDevices failed");
        }
        physicalDevices.resize(numPhysicalDevices);
        res = vkEnumeratePhysicalDevices(instance_, &numPhysicalDevices, physicalDevices.data());
        if (res != VK_SUCCESS)
        {
            throw std::runtime_error("vkEnumeratePhysicalDevices failed");
        }

        auto physicalDevice = physicalDevices[0];

        uint32_t                             queueCount;
        std::vector<VkQueueFamilyProperties> queueProperties;
        vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueCount, nullptr);
        queueProperties.resize(queueCount);
        vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueCount, queueProperties.data());

        uint32_t queueIndex = 0;
        for (uint32_t i = 0; i < queueProperties.size(); ++i)
        {
            if (queueProperties[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
            {
                queueIndex = i;
                break;
            }
        }

        float queuePriorities[] = {1.0f};

        VkDeviceQueueCreateInfo queueCreateInfo = {};
        queueCreateInfo.sType                   = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.pNext                   = nullptr;
        queueCreateInfo.flags                   = 0;
        queueCreateInfo.queueFamilyIndex        = queueIndex;
        queueCreateInfo.queueCount              = 1;
        queueCreateInfo.pQueuePriorities        = queuePriorities;

        VkDeviceCreateInfo deviceCreateInfo      = {};
        deviceCreateInfo.sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        deviceCreateInfo.pNext                   = nullptr;
        deviceCreateInfo.flags                   = 0;
        deviceCreateInfo.queueCreateInfoCount    = 1;
        deviceCreateInfo.pQueueCreateInfos       = &queueCreateInfo;
        deviceCreateInfo.enabledLayerCount       = 0;
        deviceCreateInfo.ppEnabledLayerNames     = nullptr;
        deviceCreateInfo.enabledExtensionCount   = 0;
        deviceCreateInfo.ppEnabledExtensionNames = nullptr;
        deviceCreateInfo.pEnabledFeatures        = nullptr;

        res = vkCreateDevice(physicalDevice, &deviceCreateInfo, nullptr, &device_);
        if (res != VK_SUCCESS)
        {
            throw std::runtime_error("vkCreateDevice failed");
        }
    }

    void App::SetWindow(CoreWindow ^ window)
    {
        VkResult res;

        VkUAPSurfaceCreateInfoCHB surfaceCreateInfo = {};
        surfaceCreateInfo.sType                     = VK_STRUCTURE_TYPE_UAP_SURFACE_CREATE_INFO_CHB;
        surfaceCreateInfo.window                    = reinterpret_cast<IUnknown*>(window);

        res = vkCreateUAPSurfaceCHB(instance_, &surfaceCreateInfo, nullptr, &surface_);
        if (res != VK_SUCCESS)
        {
            throw std::runtime_error("vkCreateUAPSurfaceCHB failed");
        }

        VkSwapchainCreateInfoKHR swapchainCreateInfo = {};
        swapchainCreateInfo.sType                    = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        swapchainCreateInfo.pNext                    = nullptr;
        swapchainCreateInfo.flags                    = 0;
        swapchainCreateInfo.surface                  = surface_;
        swapchainCreateInfo.minImageCount            = 2;
        swapchainCreateInfo.imageFormat              = VK_FORMAT_B8G8R8A8_UNORM;
        swapchainCreateInfo.imageColorSpace          = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
        swapchainCreateInfo.imageExtent.width        = window->Bounds.Width;
        swapchainCreateInfo.imageExtent.height       = window->Bounds.Height;
        swapchainCreateInfo.imageArrayLayers         = 1;
        swapchainCreateInfo.imageUsage               = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        swapchainCreateInfo.imageSharingMode         = VK_SHARING_MODE_EXCLUSIVE;
        swapchainCreateInfo.queueFamilyIndexCount    = 0;
        swapchainCreateInfo.pQueueFamilyIndices      = nullptr;
        swapchainCreateInfo.preTransform             = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
        swapchainCreateInfo.compositeAlpha           = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        swapchainCreateInfo.presentMode              = VK_PRESENT_MODE_FIFO_KHR;
        swapchainCreateInfo.clipped                  = VK_TRUE;
        swapchainCreateInfo.oldSwapchain             = swapchain_;

        res = vkCreateSwapchainKHR(device_, &swapchainCreateInfo, nullptr, &swapchain_);
        if (res != VK_SUCCESS)
        {
            throw std::runtime_error("vkCreateSwapchainKHR failed");
        }

        uint32_t imageCount;
        res = vkGetSwapchainImagesKHR(device_, swapchain_, &imageCount, nullptr);
        if (res != VK_SUCCESS)
        {
            throw std::runtime_error("vkGetSwapchainImagesKHR failed");
        }
        swapchanImages_.resize(imageCount);
        res = vkGetSwapchainImagesKHR(device_, swapchain_, &imageCount, swapchanImages_.data());
        if (res != VK_SUCCESS)
        {
            throw std::runtime_error("vkGetSwapchainImagesKHR failed");
        }
    }

    void App::Load(Platform::String ^ entryPoint)
    {
    }

    void App::Run()
    {
        while (true)
        {
            CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
        }
    }

    void App::Uninitialize()
    {
    }

    void App::OnActivated(CoreApplicationView ^ sender, IActivatedEventArgs ^ args)
    {
        CoreWindow::GetForCurrentThread()->Activate();
    }

    Windows::ApplicationModel::Core::IFrameworkView ^ AppSource::CreateView()
    {
        return ref new App();
    }
}

[Platform::MTAThread] int main(Platform::Array<Platform::String ^> ^)
{
    auto appSource = ref new UAPExample::AppSource();
    Windows::ApplicationModel::Core::CoreApplication::Run(appSource);
    return 0;
}
