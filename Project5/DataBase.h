#pragma once
#include <string> 
#include"MainClass.h"
#include <msclr/marshal_cppstd.h>

using namespace::std;
using namespace System;
using namespace Drawing;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;
ref class DataBase
{
private :
	static bool ExistInDataBase(int id_Api, String^ Query) {
		try {
			SqlConnection conx(MainClass::ConnectionString());
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
	static bool  Search_Movie(int id_Api) {
		String^ Query = "select TITLE from MOVIE where ID_API = @ID_API" ;
		return ExistInDataBase( id_Api, Query);
	}

	static bool  Search_Serie(int id_Api) {
		String^ Query = "select TITLE from SERIE where ID_API = @ID_API";
		return ExistInDataBase(id_Api, Query);
	}


};

