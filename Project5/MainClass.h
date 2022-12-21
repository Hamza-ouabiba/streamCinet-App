#pragma once
#include <string>
 
ref class MainClass
{
public:
	MainClass() {

	}
	static std::string ConnectionString()
	{
		return "Data Source = HB\\SQLEXPRESS; Initial Catalog = DataBase_StreamCinet; Integrated Security = True";
	}
};

 