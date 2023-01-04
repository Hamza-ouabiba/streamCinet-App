#pragma once
#include <string> 
#include "DataBaseConnection.h"   
#include <msclr/marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;

ref class DataBaseOperations
{
private:


	static int GetIdCategory(String^ Query) {

		int id = -1;
		try {
			SqlConnection conx(DataBaseConnection::ConnectionString());
			SqlCommand^ command = gcnew SqlCommand(Query, % conx);

			conx.Open();

			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				id = Convert::ToInt32(reader[0]->ToString());
			}
			return id;
			conx.Close();
		}
		catch (Exception^ ex) {
			return id;
			MessageBox::Show(ex->Message);
		}
	}
	static String^ GetCategory(String^ Query) {

		String^ Category;
		try {
			SqlConnection conx(DataBaseConnection::ConnectionString());
			SqlCommand^ command = gcnew SqlCommand(Query, % conx);

			conx.Open();

			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				Category = reader[0]->ToString();
			}
			return Category;
			conx.Close();
		}
		catch (Exception^ ex) {
			return Category;
			MessageBox::Show(ex->Message);
		}
	}

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
	/// 
	static int GetIdByQuery(String^ Query) {
		try {

			SqlConnection conx(DataBaseConnection::ConnectionString());
			conx.Open();
			SqlCommand Command(Query, % conx);

			int id = -1;
			SqlDataReader^ reader = Command.ExecuteReader();
			while (reader->Read())
			{
				id = Convert::ToInt32(reader[0]->ToString());
			}
			return id;
			conx.Close();
		}
		catch (Exception^ ex) {
			return false;
			MessageBox::Show(ex->Message);

		}
	}
public:
	/// 
	static int GetIdSerieByApi(int ID_API) {

		String^ Query = "select ID_SERIE from SERIE where ID_API = " + ID_API;
		return GetIdByQuery(Query);
	}
	/// 
	static int GetIdMovieByApi(int ID_API) {///lah

		String^ Query = "select ID_MOVIE from MOVIE where ID_API = " + ID_API;
		return GetIdByQuery(Query);
	}

	///
	static bool Exist_Serie(int id_Api , int ID_USER) {

        String^ Query3 = "Select ID_SERIE from Library_Serie where ID_USER = " + ID_USER;
        String^ Query = "select TITLE from SERIE where ID_API = @ID_API and ID_SERIE = any(" + Query3 + ")";
        return ExistInDataBase(id_Api, Query);
    }
    static bool Exist_Movie(int id_Api, int ID_USER) {
        String^ Query3 = "Select ID_MOVIE from Library_Movie where ID_USER = " + ID_USER;
        String^ Query = "select TITLE from MOVIE where ID_API = @ID_API and ID_MOVIE = any(" + Query3 + ")";
        return ExistInDataBase(id_Api, Query);
    }
	static int LastInsertedMovie() {
		int id = -1;
		try {

			SqlConnection conx(DataBaseConnection::ConnectionString());
			String^ Query = "select max(ID_MOVIE) from MOVIE;";
			// select CATEGORY from CATEGORY where ID_CATEGORY = any(SELECT ID_CATEGORY FROM MOVIECATEGORY where ID_MOVIE = 109)
			SqlCommand^ command = gcnew SqlCommand(Query, % conx);

			conx.Open();

			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				id = Convert::ToInt32(reader[0]->ToString());
			}
			return id;
			conx.Close();
		}
		catch (Exception^ ex) {
			return id;
			MessageBox::Show(ex->Message);
		}
	}

	static String^ CategoryMovie_ByIdApiCategory(int ID_API) {
		String^ Query = "Select CATEGORY from CATEGORY where ID_API = " + ID_API + ";";
		return GetCategory(Query);
	}

	static String^ CategoryMovie_ByIdCategory(int id) {

		String^ Query = "Select CATEGORY from CATEGORY where ID_CATEGORY = " + id + ";";
		return GetCategory(Query);
	}
	static int GetIdCategory_MovieByCategory(String^ category) {

		String^ Query = "select ID_CATEGORY from CATEGORY where CATEGORY like '" + category + "%' ;";

		return GetIdCategory(Query);
	}
	static int GetIdCategory_Movie(int ID_API) {
		String^ Query = "Select ID_CATEGORY from CATEGORY where ID_API = " + ID_API + ";";
		return GetIdCategory(Query);
	}

	////////////////////////// Serie ////////////////////////////////:::::::
			// Search Serie :
	

	static int LastInsertedSerie() {
		int id = -1;
		try {

			SqlConnection conx(DataBaseConnection::ConnectionString());
			String^ Query = "select max(ID_SERIE) from SERIE;";
			// select CATEGORY from CATEGORY where ID_CATEGORY = any(SELECT ID_CATEGORY FROM MOVIECATEGORY where ID_MOVIE = 109)
			SqlCommand^ command = gcnew SqlCommand(Query, % conx);

			conx.Open();

			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				id = Convert::ToInt32(reader[0]->ToString());
			}
			return id;
			conx.Close();
		}
		catch (Exception^ ex) {
			return id;
			MessageBox::Show(ex->Message);
		}
	}

	static String^ CategorySerie_ByIdApiCategory(int ID_API) {
		String^ Query = "Select CATEGORY from CATEGORY_SERIE where ID_API = " + ID_API + ";";
		return GetCategory(Query);
	}

	static String^ CategorySerie_ByIdCategory(int id) {
		String^ Query = "Select CATEGORY from CATEGORY_SERIE where ID_CATEGORY = " + id + ";";
		return GetCategory(Query);
	}
	static int GetIdCategory_SerieByCategory(String^ category) {

		String^ Query = "select ID_CATEGORY from CATEGORY_SERIE where CATEGORY like '" + category + "%' ;";

		return GetIdCategory(Query);
	}

	static int GetIdCategory_Serie(int ID_API) {
		String^ Query = "Select ID_CATEGORY from CATEGORY_SERIE where ID_API = " + ID_API + ";";
		return GetIdCategory(Query);
	}

	////////////User operation////

	static int LastIdUser() {
		int id = -1;
		try {
			SqlConnection conx(DataBaseConnection::ConnectionString());
			SqlCommand^ command = gcnew SqlCommand("SELECT MAX(ID_USER) from Users;", % conx);

			conx.Open();

			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				id = Convert::ToInt32(reader[0]->ToString());
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}

		return id;

	} 


		 

};

