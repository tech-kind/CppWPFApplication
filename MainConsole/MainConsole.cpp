#include "stdafx.h"
#include "MainWindowViewModel.h"

using namespace System;
using namespace WpfApp;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	MainWindowViewModel ^viewModel = gcnew MainWindowViewModel();
	MainWindow ^main = gcnew MainWindow();
	main->DataContext = viewModel;

	main->ShowDialog();
    return 0;
}
