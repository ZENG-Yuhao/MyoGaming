//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace MyoGaming
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

		void WelcomeAnimation();    // this function defined an animation of welcome logo.

		void OnTick(Object ^ sender, Object ^ e);

		Windows::Storage::StorageFile ^ GetCustomFileAsync(Platform::String ^ fileName);

		void WriteTimestamp();

	private:
		void img_screen_Loading(Windows::UI::Xaml::FrameworkElement^ sender, Platform::Object^ args);
		void img_screen_Unloaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void img_screen_PointerPressed(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void img_screen_PointerReleased(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void btn_in_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void btn_out_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void img_screen_PointerPressed_1(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void img_screen_PointerReleased_1(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void lnk_start_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
