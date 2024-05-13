#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;

//void FormThread() {
//	Application::SetCompatibleTextRenderingDefault(false);
//	Application::EnableVisualStyles();
//	Laba6Client::MyForm form;
//	Application::Run(% form);
//}

[STAThreadAttribute]
int main(array<String^>^ args) {
	//Thread^ FThread = gcnew Thread(gcnew ThreadStart(&FormThread));
	//FThread->Start();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Laba6Client::MyForm form;
	Application::Run(% form);
}