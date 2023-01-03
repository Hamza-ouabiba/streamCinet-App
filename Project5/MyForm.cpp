#include "MyForm.h"
#include "Login.h"

#include <iostream>

using namespace System;
using namespace System::Windows::Forms;
using namespace::std;
void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
     
    Project5::MyForm fr;
    Application::Run(% fr);
    

}
