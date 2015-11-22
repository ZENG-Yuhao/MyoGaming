//
// GamePage.xaml.cpp
// Implementation of the GamePage class
//

#include "pch.h"
#include "GamePage.xaml.h"
#include "gamepage_var.h"
#include "RecordPage.xaml.h"
#include "timer_var.h"

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
	GameMode = CLASSIC;
	GameDifficulty = NORMAL;
	initPaths(GameDifficulty);
}


void MyoGaming::GamePage::submit(int value)
{
	if (locked || !started) return;

	ExitStoryboard->Begin();
	String^ path;
	if (value == abs(code_direction))
	{	 //verify the answer
		score++;
		nb_right++;
		path = "ms-appx:Assets/right.png";
		if (GameMode = CLASSIC)
		{
			
		}
	}
	else
	{
		nb_wrong++;
		path = "ms-appx:Assets/wrong.png";
		if (GameMode = CLASSIC)
		{
			life--;
			if (life <= 0) GameEnd();
		}
	}


	UI_Update();
	code_direction = rand() % 4 + 1; //generate next direction  range: 1 to 4
	int sign = rand() % 2; //random sign :  0 - negative , 1 - positive
	if (sign == 0)
	{
		code_direction = -code_direction;
	}

	//replace display image.
	Uri = ref new Windows::Foundation::Uri(path);
	BitmapImage = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(Uri);
	img_display->Source = BitmapImage;
	EnterStoryboard->Begin();
	locked = true;
}

void MyoGaming::GamePage::UI_Update()
{
	txt_score->Text = "Score: " + score;
	txt_rw->Text = "R/W: " + nb_right + "/" + nb_wrong;
	txt_life->Text = "Life : " + life;
}

void MyoGaming::GamePage::PointerIsBack()
{
	Sleep(300);
	locked = false;
	//we make the absolute value of those red/blue arrows whose correct geste towards the same direction be the same, but with the oppsite sign.
	String^ path;
	switch (code_direction)
	{
	case 1: 	//up blue
		//path = "ms-appx:Assets/arrow_blue_up.png";
		path = picPaths[0];
		break;
	case 2:	    //down blue
		//path = "ms-appx:Assets/arrow_blue_down.png";
		path = picPaths[1];
		break;
	case 3:	    //left blue
		//path = "ms-appx:Assets/arrow_blue_left.png";
		path = picPaths[2];
		break;
	case 4:	    //right blue
		//path = "ms-appx:Assets/arrow_blue_right.png";
		path = picPaths[3];
		break;
	case -2:	    //up red
		//path = "ms-appx:Assets/arrow_red_up.png";
		path = picPaths[4];
		break;
	case -1:	    //down red
		//path = "ms-appx:Assets/arrow_red_down.png";
		path = picPaths[5];
		break;
	case -4:		//left red
		//path = "ms-appx:Assets/arrow_red_left.png";
		path = picPaths[6];
		break;
	case -3:		//right red
		//path = "ms-appx:Assets/arrow_red_right.png";
		path = picPaths[7];
		break;
	}
	//replace display image.
	Uri = ref new Windows::Foundation::Uri(path);
	BitmapImage = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(uri);
	img_display->Source = BitmapImage;

	
}

void MyoGaming::GamePage::GameStart()
{
	gamepage_var_clear();
	UI_Update();
	started = true;
	initTimer();
}

void MyoGaming::GamePage::initTimer()
{
	timer = ref new Windows::UI::Xaml::DispatcherTimer();
	switch (GameMode)
	{
	case CLASSIC:
		ts.Duration = 30000000;	 //3 sec
		timer->Interval = ts;
		registrationtoken = timer->Tick += ref new EventHandler<Object^>(this, &GamePage::OnTick);
		break;
	case TIME_LIMITED:
		ts.Duration = 600000000;	 //60 sec
		timer->Interval = ts;
		registrationtoken = timer->Tick += ref new EventHandler<Object^>(this, &GamePage::OnTick);
		break;
	default:
		break;
	}
	timer->Start();
}

void MyoGaming::GamePage::OnTick(Object^ sender, Object^ e)
{
	timer->Stop();
	timer->Tick -= registrationtoken;
	switch (GameMode)
	{
	case CLASSIC:
		locked = true;
		life--;
		UI_Update();
		if (life <= 0) GameEnd();
		initTimer();
		break;
	case TIME_LIMITED:

		GameEnd();
		break;
	default:
		break;
	}
}

void MyoGaming::GamePage::GameEnd()
{

	started = false;
	btn_start->Content = "Again.";
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
	PointerIsBack();
}


void MyoGaming::GamePage::btn_exit_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(RecordPage::typeid));
}



void MyoGaming::GamePage::btn_start_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GameStart();
}
