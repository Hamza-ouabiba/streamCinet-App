#pragma once
#include <string>
#include"ClassData.h"
#include"MainClass.h"


using namespace::std;
using namespace System;
using namespace Drawing;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;



	public ref class Class_Movie
	{
	private:
		bool Exist;//Exists In DataBase
		int id_Movie;
		int id_Api;
		float Rating;
		String^ title;
		String^ Overview;
		DateTime Realease_Date;
		Image^ Poster;
		Image^ BakcDrop;

	public:
		Class_Movie() {
		 
		}
		Class_Movie(Class_Movie ^MV) {

			this->id_Movie = MV->id_Movie;
			this->id_Api = MV->id_Api;
			this->title = MV->title;
			this->Overview = MV->Overview;
			this->Rating = MV->Rating;
			this->Realease_Date = MV->Realease_Date;
			this->Poster = MV->Poster;
			this->BakcDrop = MV->BakcDrop;

			this->Exist = ExistInDataBase(MV->id_Api, "select TITLE from MOVIE where ID_API = @ID_API ;");
		}
		Class_Movie(int id_Movie, int id_Api, String^ title, String^ Overview, float Rating, DateTime Realease_Date, Image^ Poster, Image^ BakcDrop)
		{
			this->id_Movie = id_Movie;
			this->id_Api = id_Api;
			this->title = title;
			this->Overview = Overview;
			this->Rating = Rating;
			this->Realease_Date = Realease_Date;
			this->Poster = Poster;
			this->BakcDrop = BakcDrop;
	
			this->Exist = ExistInDataBase(this->id_Api,"select TITLE from MOVIE where ID_API = @ID_API ;");
		}
		bool  ExistInDataBase(int id_Api, String^ Query) {
			try {
				SqlConnection conx("Data Source = HB\\SQLEXPRESS; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
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
		~Class_Movie() {
		}
		//Get
		int GetIdMovie() {
			return this->id_Movie;
		}
		int GetIdApi() {
			return this->id_Api;
		}
		float GetRating() {
			return this->Rating;
		}
		
		bool GetExist() {
			return this->Exist;
		}

		String^ GetTitle() {
			return this->title;
		}
		String^ GetOverview() {
			return Overview;
		}
		
		DateTime GetRealease_Date() {
			return this->Realease_Date;
		}
		Image^ GetPoster() {
			return this->Poster;
		}
		Image^ GetBakcDrop() {
			return this->BakcDrop;
		}

		//Set
		void SetIdMovie(int id) {
			this->id_Movie = id;
		}
		void SetIdApi(int id) {
			this->id_Api = id;
			this->Exist = ExistInDataBase(this->id_Api, "select TITLE from MOVIE where ID_API = @ID_API");
		}
		void SetRating(float rating) {
			this->Rating = rating;
		}
		void SetTitle(String^ title) {
			this->title = title;
		}
		void SetOverview(String^ Overview) {
			this->Overview = Overview;
		}
		void SetRealease_Date(DateTime Date) {
			this->Realease_Date = Date;
		}
		void SetPoster(Image^ img){
			this->Poster = img;
		}
		void SetBakcDrop(Image^ img) {
			this->BakcDrop = img;
		}
		void SetExist(bool Exits) {
			this->Exist = Exits;
		}
	};

	public ref class Class_Serie
	{
	private:
		bool Exist;//Exists In DataBase
		int id_Serie;
		int id_Api;
		String^ Name;
		String^ Overview;
		String^ Country;
		float Rating;
		DateTime Realease_Date;
		Image^ Poster;
		Image^ BakcDrop;

	public:

		Class_Serie() {
		}
		Class_Serie(Class_Serie^ Serie) {

			this->id_Serie = Serie->id_Serie;
			this->id_Api = Serie->id_Api;
			this->Name = Serie->Name;
			this->Overview = Serie->Overview;
			this->Rating = Serie->Rating;
			this->Realease_Date = Serie->Realease_Date;
			this->Poster = Serie->Poster;
			this->BakcDrop = Serie->BakcDrop;

			this->Exist = ExistInDataBase(Serie->id_Api, "select TITLE from SERIE where ID_API = @ID_API ;");
		}
		Class_Serie(int id_Serie, int id_Api, String^ Name, String^ Overview, String^ Country, float Rating, DateTime Realease_Date, Image^ Poster, Image^ BakcDrop)
		{
			this->id_Serie = id_Serie;
			this->id_Api = id_Api;
			this->Name = Name;
			this->Country = Country;
			this->Overview = Overview;
			this->Rating = Rating;
			this->Realease_Date = Realease_Date;
			this->Poster = Poster;
			this->BakcDrop = BakcDrop;

			this->Exist = ExistInDataBase(this->id_Api, "select TITLE from SERIE where ID_API = @ID_API");
		}
		bool  ExistInDataBase(int id_Api, String^ Query) {
			try {
				SqlConnection conx("Data Source = HB\\SQLEXPRESS; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
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
		~Class_Serie() {
		}

		//Get
		int GetIdSerie() {
			return this->id_Serie;
		}
		int GetIdApi() {
			return this->id_Api;
		}
		float GetRating() {
			return this->Rating;
		}

		bool GetExist() {
			return this->Exist;
		}

		String^ GetTitle() {
			return this->Name;
		}
		String^ GetOverview() {
			return Overview;
		}

		DateTime GetRealease_Date() {
			return this->Realease_Date;
		}
		Image^ GetPoster() {
			return this->Poster;
		}
		Image^ GetBakcDrop() {
			return this->BakcDrop;
		}

		//Set
		void SetIdMovie(int id_Serie) {
			this->id_Serie = id_Serie;
		}
		void SetIdApi(int id_Api) {
			this->id_Api = id_Api;
			this->Exist = ExistInDataBase(this->id_Api, "select TITLE from SERIE where ID_API = @ID_API");
		}
		void SetExist(bool Exits) {
			this->Exist = Exits;
		}
		void SetRating(float rating) {
			this->Rating = rating;
		}
		void SetTitle(String^ Name) {
			this->Name = Name;
		}
		void SetOverview(String^ Overview) {
			this->Overview = Overview;
		}
		void SetRealease_Date(DateTime Date) {
			this->Realease_Date = Date;
		}
		void SetPoster(Image^ img) {
			this->Poster = img;
		}
		void SetBakcDrop(Image^ img) {
			this->BakcDrop = img;
		}

	};
 

	
