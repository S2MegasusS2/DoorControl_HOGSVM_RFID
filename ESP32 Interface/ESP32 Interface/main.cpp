// #define Debug
#ifndef Debug
#include "ESP32_Login_UI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	ESP32Interface::ESP32_Login_UI^ Login_UI = gcnew ESP32Interface::ESP32_Login_UI();
	Application::Run(Login_UI);
	return 0;
}
#else
#include "Register_UI.h"



using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	ESP32Interface::Register_UI^ Reg_UI = gcnew ESP32Interface::Register_UI();
	Application::Run(Reg_UI);
	return 0;
}

#endif