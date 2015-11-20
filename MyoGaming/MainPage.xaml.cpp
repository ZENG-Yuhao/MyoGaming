//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "timer_var.h"
#include "GamePage.xaml.h"
#include "gamepage_var.h"
#include <iostream>
#include <fstream>
#include "score.h"

using namespace MyoGaming;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Storage;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
	WelcomeAnimation();
}

void MainPage::WelcomeAnimation() {
	timer = ref new Windows::UI::Xaml::DispatcherTimer();

	ts.Duration = 7000000;	 //0.7 sec

	timer->Interval = ts;
	timer->Start();
	registrationtoken = timer->Tick += ref new EventHandler<Object^>(this, &MainPage::OnTick);
}
void MainPage::OnTick(Object^ sender, Object^ e) {

	timerCounter++;
	if (timerCounter >= 3) timerCounter = 0;

	switch (timerCounter)
	{
	case 1:
		ExitStoryboard->Begin();
		break;
	case 2:
		EnterStoryboard->Begin();
		break;
	}

}

Windows::Storage::StorageFile^ MainPage::GetCustomFileAsync(Platform::String^ fileName)
{
	using Windows::Storage::StorageFile;
	using Windows::Storage::StorageFolder;

	auto localFolder = Windows::Storage::ApplicationData::Current->LocalFolder;
	auto localTask = concurrency::create_task(localFolder->GetFileAsync(fileName));
	StorageFile^ retVal = nullptr;
	localTask.then([&](StorageFile^ t) {
		retVal = t;
	}).then([](concurrency::task<void> t)
	{
		try
		{
			t.get();
			//OutputDebugString(L"Found\n");
		}
		catch (Platform::COMException^ e)
		{
			//OutputDebugString(e->Message->Data());
		}
	}).wait();
	return retVal;
}

// Write data to a file

void MainPage::WriteTimestamp()
{
	StorageFolder^ localFolder = ApplicationData::Current->LocalFolder;
	
	Concurrency::task<StorageFile^> fileOperation(localFolder->CreateFileAsync("dataFile.txt", CreationCollisionOption::ReplaceExisting));
	fileOperation.then([this](StorageFile^ sampleFile)
	{
		sampleFile->OpenAsync(FileAccessMode::ReadWrite);
		return FileIO::WriteTextAsync(sampleFile, "hello world");
	}).then([this](Concurrency::task<void> previousOperation) {
		try {
			previousOperation.get();
		}
		catch (Platform::Exception^) {
			// Timestamp not written
		}
	});

}





void MyoGaming::MainPage::lnk_start_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	timer_var_clear();
	//WriteTimestamp();
	//StorageFile^ fileVar;
	//if ((fileVar = GetCustomFileAsync("somefile.txt")) == nullptr)
	//{
	//	String^ path = Windows::ApplicationModel::Package::Current->InstalledLocation->Path + "\\Assets";
	//	concurrency::create_task(Windows::Storage::StorageFolder::GetFolderFromPathAsync(path)).then([](StorageFolder^ folder) {
	//		return (folder->GetFileAsync("somefile.txt"));
	//	}).then([](StorageFile^ file) {
	//		return (file->CopyAsync(Windows::Storage::ApplicationData::Current->LocalFolder));
	//	}).then([&](StorageFile^ file) {
	//		fileVar = file;
	//		OutputDebugString(file->DisplayName->Data());
	//	});


	//}
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(GamePage::typeid));
}
