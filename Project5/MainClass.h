#pragma once

 
ref class MainClass
{
public:
	MainClass() {

	}
	static System::String^ ConnectionString()
	{
		return "Data Source = HB\\SQLEXPRESS; Initial Catalog = DataBase_StreamCinet; Integrated Security = True";
	}
};

 