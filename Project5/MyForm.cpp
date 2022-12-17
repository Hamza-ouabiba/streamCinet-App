#include "MyForm.h"

#include <iostream>

using namespace System;
using namespace System::Windows::Forms;
using namespace::std;
void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project5::MyForm form;
    Application::Run(% form);

}
