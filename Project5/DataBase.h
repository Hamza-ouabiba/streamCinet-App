#pragma once
 
#include "DataBaseConnection.h"    

using namespace System;
using namespace::std;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;
 
ref class DataBase
{

	static SqlConnection^ conx = DataBaseConnection::Connection();

	static bool ExistInDataBase(int id_Api, String^ Query) {
		try {
			SqlConnection conx(DataBaseConnection::ConnectionString());
			conx.Open();
			SqlCommand Command(Query, % conx);
			Command.Parameters->AddWithValue("@ID_API", id_Api);
			SqlDataReader^ Read = Command.ExecuteReader();
			if (Read->HasRows) {
				return true;
			}
			return false;
			conx.Close();
		}
		catch (Exception^ ex) {
			return false;
			MessageBox::Show(ex->Message);

		}
	}
public:
	DataBase() {
	}
	// Search Movie :
	static bool Exist_Movie(int id_Api) {
		String^ Query = "select TITLE from MOVIE where ID_API = @ID_API";
		return ExistInDataBase(id_Api, Query);
	}

	// Search Serie :
	static bool Exist_Serie(int id_Api) {
		String^ Query = "select TITLE from SERIE where ID_API = @ID_API";
		return ExistInDataBase(id_Api, Query);
	}
};

 
