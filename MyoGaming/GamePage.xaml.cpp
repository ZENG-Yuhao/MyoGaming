//
// GamePage.xaml.cpp
// Implementation of the GamePage class
//

#include "pch.h"
#include "GamePage.xaml.h"
#include "gamepage_var.h"

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

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

GamePage::GamePage()
{
	InitializeComponent();
}


void MyoGaming::GamePage::submit(int value) {
	if (locked) return;

	ExitStoryboard->Begin();
	String^ path;
	if (value == abs(code_direction)) {	 //verify the answer
		score++;
		nb_right++;
		path = "ms-appx:Assets/right.png";
	}
	else {
		nb_wrong++;
		path = "ms-appx:Assets/wrong.png";
	}
	txt_score->Text = "Score: " + score;
	txt_rw->Text = "R/W: " + nb_right + "/" + nb_wrong;
	code_direction = rand() % 4 + 1; //generate next direction  range: 1 to 4
	int sign = rand() % 2; //random sign :  0 - negative , 1 - positive
	if (sign == 0) {
		code_direction = -code_direction;
	}
		  
	//replace display image.
	uri = ref new Windows::Foundation::Uri(path);
	bitmapImage = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(uri);
	img_display->Source = bitmapImage;
	EnterStoryboard->Begin();
	locked = true;
}


void MyoGaming::GamePage::ctr_up_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	submit(1);
}



void MyoGaming::GamePage::ctr_down_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	submit(2);
}


void MyoGaming::GamePage::ctr_left_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	submit(3);
}


void MyoGaming::GamePage::ctr_right_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	submit(4);
}


void MyoGaming::GamePage::pnl_display_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	Sleep(300);
	locked = false;
	//code interpretation.
	String^ path;
	switch (code_direction)
	{
	case 1: 	//up blue
		path = "ms-appx:Assets/arrow_blue_up.png";
		break;
	case 2:	    //down blue
		path = "ms-appx:Assets/arrow_blue_down.png";
		break;
	case 3:	    //left blue
		path = "ms-appx:Assets/arrow_blue_left.png";
		break;
	case 4:	    //right blue
		path = "ms-appx:Assets/arrow_blue_right.png";
		break;
	case -2:	    //up red
		path = "ms-appx:Assets/arrow_red_up.png";
		break;
	case -1:	    //down red
		path = "ms-appx:Assets/arrow_red_down.png";
		break;
	case -4:		//left red
		path = "ms-appx:Assets/arrow_red_left.png";
		break;
	case -3:		//right red
		path = "ms-appx:Assets/arrow_red_right.png";
		break;
	}
	//replace display image.
	uri = ref new Windows::Foundation::Uri(path);
	bitmapImage = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(uri);
	img_display->Source = bitmapImage;
}
