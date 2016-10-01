#pragma once

#include <VulkanOnD3D12.h>

namespace UAPExample
{
    ref class App sealed : public Windows::ApplicationModel::Core::IFrameworkView
    {
    public:
        App();

        virtual void Initialize(Windows::ApplicationModel::Core::CoreApplicationView ^ applicationView);
        virtual void SetWindow(Windows::UI::Core::CoreWindow ^ window);
        virtual void Load(Platform::String ^ entryPoint);
        virtual void Run();
        virtual void Uninitialize();

    private:
        void OnActivated(Windows::ApplicationModel::Core::CoreApplicationView ^ sender, Windows::ApplicationModel::Activation::IActivatedEventArgs ^ args);

        VkInstance   instance_;
        VkDevice     device_;
        VkSurfaceKHR surface_;
    };

    ref class AppSource sealed : public Windows::ApplicationModel::Core::IFrameworkViewSource
    {
    public:
        virtual Windows::ApplicationModel::Core::IFrameworkView ^ CreateView();
    };
}
