
#include "pch.h"
#include "timer_var.h"
int timerCounter = 0;
Windows::Foundation::TimeSpan ts;
Windows::UI::Xaml::DispatcherTimer^ timer;
Windows::Foundation::EventRegistrationToken registrationtoken;

void timer_var_clear() {
	timerCounter = 0;
	if (timer != nullptr){ 
		timer->Stop();
		timer->Tick -= registrationtoken;
		delete(timer);
	}
}