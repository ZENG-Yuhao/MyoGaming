#include "pch.h"
#include "gamepage_var.h"

int nb_right = 0;
int nb_wrong = 0;
int score = 0;
int code_direction =1;
bool locked = true;
Windows::Foundation::Uri^ uri = nullptr;
Windows::UI::Xaml::Media::Imaging::BitmapImage^ bitmapImage = nullptr;
void clear() {
	nb_right = 0;
	nb_wrong = 0;
	score = 0;
	code_direction = 1;
	locked = true;
	if (uri != nullptr)
		delete(uri);
	if (bitmapImage != nullptr)
		delete(bitmapImage);
}
