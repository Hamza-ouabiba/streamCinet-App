#pragma once
 
using namespace System::Data::SqlClient;
public ref class DataBaseConnection
{
public:
	DataBaseConnection() {

	}
	static System::String^ ConnectionString()
	{
		return "Data Source = HB\\SQLEXPRESS; Initial Catalog = DataBase_StreamCinet; Integrated Security = True";
	}
	static SqlConnection^ Connection() {
		SqlConnection^ conx = gcnew SqlConnection(ConnectionString());
		return conx;
	}
};

