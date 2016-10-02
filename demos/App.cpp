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
