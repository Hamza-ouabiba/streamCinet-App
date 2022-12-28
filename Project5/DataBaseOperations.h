#pragma once
#include <string> 
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing::Imaging;
using namespace System::Drawing;
using namespace System::Data::SqlClient;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
ref class DataBaseOperations
{
	public:
		static bool ExistInDataBase(int id_Api, String^ Query) {
			try {
				SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
				conx.Open();
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_API", id_Api);
				SqlDataReader^ Read = Command.ExecuteReader();
				if (Read->HasRows == true)
				{
					return true;
				}
				else return false;
				conx.Close();
			}
			catch (Exception^ ex) {
				return false;
				MessageBox::Show(ex->Message);

			}
		}
	public:
		static bool  Search_Movie(int id_Api) {
			String^ Query = "select TITLE from MOVIE where ID_API = @ID_API";
			return ExistInDataBase(id_Api, Query);
		}

		static bool  Search_Serie(int id_Api) {
			String^ Query = "select TITLE from SERIE where ID_API = @ID_API";
			return ExistInDataBase(id_Api, Query);
		}
};

