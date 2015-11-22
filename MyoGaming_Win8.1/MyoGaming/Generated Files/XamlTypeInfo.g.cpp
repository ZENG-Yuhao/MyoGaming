﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "pch.h"
#include "XamlTypeInfo.g.h"

#include "FilerwPage.xaml.h"
#include "GamePage.xaml.h"
#include "GuidePage.xaml.h"
#include "App.xaml.h"
#include "MainPage.xaml.h"
#include "RecordPage.xaml.h"
#include "WelcomePage.xaml.h"

#include "FilerwPage.g.hpp"
#include "GamePage.g.hpp"
#include "GuidePage.g.hpp"
#include "App.g.hpp"
#include "MainPage.g.hpp"
#include "RecordPage.g.hpp"
#include "WelcomePage.g.hpp"

::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::OtherProviders::get()
{
    if(_otherProviders == nullptr)
    {
        _otherProviders = ref new ::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>();
    }
    return _otherProviders;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CheckOtherMetadataProvidersForName(::Platform::String^ typeName)
{
    ::Windows::UI::Xaml::Markup::IXamlType^ foundXamlType = nullptr;
    for (unsigned int i = 0; i < OtherProviders->Size; i++)
    {
        auto xamlType = OtherProviders->GetAt(i)->GetXamlType(typeName);
        if(xamlType != nullptr)
        {
            if(xamlType->IsConstructible)    // not Constructible means it might be a Return Type Stub
            {
                return xamlType;
            }
            foundXamlType = xamlType;
        }
    }
    return foundXamlType;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CheckOtherMetadataProvidersForType(::Windows::UI::Xaml::Interop::TypeName t)
{
    ::Windows::UI::Xaml::Markup::IXamlType^ foundXamlType = nullptr;
    for (unsigned int i = 0; i < OtherProviders->Size; i++)
    {
        auto xamlType = OtherProviders->GetAt(i)->GetXamlType(t);
        if(xamlType != nullptr)
        {
            if(xamlType->IsConstructible)    // not Constructible means it might be a Return Type Stub
            {
                return xamlType;
            }
            foundXamlType = xamlType;
        }
    }
    return foundXamlType;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CreateXamlType(::Platform::String^ typeName)
{
    if (typeName == L"Windows.UI.Xaml.Controls.Page")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"Windows.UI.Xaml.Controls.UserControl")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"String")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"Object")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"MyoGaming.FilerwPage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::MyoGaming::FilerwPage(); 
            };
        userType->AddMemberName(L"FileContent");
        userType->AddMemberName(L"FileRec");
        userType->SetIsLocalType();
        return userType;
    }

    if (typeName == L"Windows.Storage.StorageFile")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Object"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Metadata;
        userType->SetIsReturnTypeStub();
        return userType;
    }

    if (typeName == L"MyoGaming.GamePage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::MyoGaming::GamePage(); 
            };
        userType->SetIsLocalType();
        return userType;
    }

    if (typeName == L"MyoGaming.GuidePage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::MyoGaming::GuidePage(); 
            };
        userType->SetIsLocalType();
        return userType;
    }

    if (typeName == L"MyoGaming.MainPage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::MyoGaming::MainPage(); 
            };
        userType->SetIsLocalType();
        return userType;
    }

    if (typeName == L"MyoGaming.RecordPage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::MyoGaming::RecordPage(); 
            };
        userType->SetIsLocalType();
        return userType;
    }

    if (typeName == L"MyoGaming.WelcomePage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::MyoGaming::WelcomePage(); 
            };
        userType->SetIsLocalType();
        return userType;
    }

    return nullptr;
}

::Windows::UI::Xaml::Markup::IXamlMember^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CreateXamlMember(::Platform::String^ longMemberName)
{
    if (longMemberName == L"MyoGaming.FilerwPage.FileContent")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"FileContent", L"String");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::MyoGaming::FilerwPage^)instance;
                return that->FileContent;
            };

        xamlMember->Setter =
            [](Object^ instance, Object^ value) -> void
            {
                auto that = (::MyoGaming::FilerwPage^)instance;
                that->FileContent = (::Platform::String^)value;
            };
        return xamlMember;
    }

    if (longMemberName == L"MyoGaming.FilerwPage.FileRec")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"FileRec", L"Windows.Storage.StorageFile");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::MyoGaming::FilerwPage^)instance;
                return that->FileRec;
            };

        xamlMember->Setter =
            [](Object^ instance, Object^ value) -> void
            {
                auto that = (::MyoGaming::FilerwPage^)instance;
                that->FileRec = (::Windows::Storage::StorageFile^)value;
            };
        return xamlMember;
    }

    return nullptr;
}

