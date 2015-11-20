﻿#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------


namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Media {
                namespace Animation {
                    ref class Storyboard;
                }
            }
        }
    }
}
namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class HyperlinkButton;
                ref class TextBlock;
                ref class Image;
            }
        }
    }
}

namespace MyoGaming
{
    [::Windows::Foundation::Metadata::WebHostHidden]
    partial ref class MainPage : public ::Windows::UI::Xaml::Controls::Page, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector,
        public ::Windows::UI::Xaml::Markup::IComponentConnector2
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
        virtual ::Windows::UI::Xaml::Markup::IComponentConnector^ GetBindingConnector(int connectionId, ::Platform::Object^ target);
    
    private:
        bool _contentLoaded;
    
        private: ::Windows::UI::Xaml::Media::Animation::Storyboard^ EnterStoryboard;
        private: ::Windows::UI::Xaml::Media::Animation::Storyboard^ ExitStoryboard;
        private: ::Windows::UI::Xaml::Controls::HyperlinkButton^ lnk_start;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ tst;
        private: ::Windows::UI::Xaml::Controls::Image^ img_screen;
        private: ::Windows::UI::Xaml::Controls::Image^ img_logo;
    };
}

