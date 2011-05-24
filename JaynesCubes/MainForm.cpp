#include "stdafx.h"
#include "MainForm.h"
#include <windows.h>

using namespace JaynesCubes;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	System::Threading::Thread::CurrentThread->ApartmentState = System::Threading::ApartmentState::STA;
	Application::Run(gcnew MainForm());
	return 0;
}
