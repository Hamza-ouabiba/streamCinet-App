#pragma once
#include "DataBaseConnection.h"  
#include "Movie.h"  
#include "Serie.h" 
#include"json/json.h"  
#using <System.Net.Http.dll>
#using <System.Runtime.InteropServices.dll>
#include "Login.h"

using namespace System::Net::Http;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Data::SqlClient;


namespace Project5 {

	/// <summary>
	/// Summary for ViewMovie
	/// </summary>
	public ref class ViewMovie : public System::Windows::Forms::UserControl
	{

	private: System::Windows::Forms::Label^ Category1_label;

	private: System::Windows::Forms::Label^ Category2_label;
	private: System::Windows::Forms::Label^ Category3_label;
	private: System::Windows::Forms::Panel^ panel2;


	public:
		Serie^ serie_;
		Movie^ movie_;
		ViewMovie(Movie^ MV)
		{
			InitializeComponent();
			movie_ = MV;
			serie_ = gcnew Serie();
			serie_->SetName("");
			Title_label->Text = movie_->GetTitle();
			this->Overview_label->Text = movie_->GetOverview();
			this->Rating_label->Text = movie_->GetRating().ToString();
			this->Date_label->Text = movie_->GetRealease_Date().ToString();
			label4->Text = "";
			Category1_label->Text = "";
			Category2_label->Text = "";
			Category3_label->Text = "";
			this->panel2->BackgroundImage = movie_->GetBakcDrop();
			//
			//TODO: Add the constructor code here
			//
		}
		ViewMovie(Serie^ Serie)
		{
			InitializeComponent();
			movie_ = gcnew Movie();
			movie_->SetTitle("");
			this->serie_ = Serie;
			this->Title_label->Text = serie_->GetName();
			this->Overview_label->Text = serie_->GetOverview();
			this->Rating_label->Text = serie_->GetRating().ToString();
			this->Date_label->Text = serie_->GetRealease_Date().ToString();
			this->panel2->BackgroundImage = serie_->GetBakcDrop();
			label10->Text = serie_->GetCountry();
			Category1_label->Text = "";
			Category2_label->Text = "";
			Category3_label->Text = "";

			//TODO: Add the constructor code here
			//
		}


	private: System::Windows::Forms::Button^ BtnLibrary_AddRemove;
	public:
	private: System::Windows::Forms::Label^ Title_label;
	private: System::Windows::Forms::Button^ BtnTrailer;
	private: System::Windows::Forms::Label^ Overview_label;
	private: System::Windows::Forms::Label^ label10;

	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::Label^ Date_label;

	private: System::Windows::Forms::Label^ Rating_label;
	private: System::Windows::Forms::Panel^ panel1;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ViewMovie()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->BtnLibrary_AddRemove = (gcnew System::Windows::Forms::Button());
			this->Title_label = (gcnew System::Windows::Forms::Label());
			this->BtnTrailer = (gcnew System::Windows::Forms::Button());
			this->Overview_label = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Date_label = (gcnew System::Windows::Forms::Label());
			this->Rating_label = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Category1_label = (gcnew System::Windows::Forms::Label());
			this->Category2_label = (gcnew System::Windows::Forms::Label());
			this->Category3_label = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// BtnLibrary_AddRemove
			// 
			this->BtnLibrary_AddRemove->BackColor = System::Drawing::Color::Transparent;
			this->BtnLibrary_AddRemove->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnLibrary_AddRemove->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->BtnLibrary_AddRemove->ForeColor = System::Drawing::Color::White;
			this->BtnLibrary_AddRemove->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BtnLibrary_AddRemove->Location = System::Drawing::Point(213, 101);
			this->BtnLibrary_AddRemove->Name = L"BtnLibrary_AddRemove";
			this->BtnLibrary_AddRemove->Size = System::Drawing::Size(190, 51);
			this->BtnLibrary_AddRemove->TabIndex = 16;
			this->BtnLibrary_AddRemove->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BtnLibrary_AddRemove->UseVisualStyleBackColor = false;
			this->BtnLibrary_AddRemove->Click += gcnew System::EventHandler(this, &ViewMovie::BtnLibrary_AddRemove_Click);
			// 
			// Title_label
			// 
			this->Title_label->AutoSize = true;
			this->Title_label->BackColor = System::Drawing::Color::Transparent;
			this->Title_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title_label->ForeColor = System::Drawing::Color::White;
			this->Title_label->Location = System::Drawing::Point(41, 35);
			this->Title_label->Name = L"Title_label";
			this->Title_label->Size = System::Drawing::Size(171, 25);
			this->Title_label->TabIndex = 27;
			this->Title_label->Text = L"Game of thrones";
			this->Title_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// BtnTrailer
			// 
			this->BtnTrailer->BackColor = System::Drawing::Color::Transparent;
			this->BtnTrailer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnTrailer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnTrailer->ForeColor = System::Drawing::Color::White;
			this->BtnTrailer->Location = System::Drawing::Point(49, 101);
			this->BtnTrailer->Name = L"BtnTrailer";
			this->BtnTrailer->Size = System::Drawing::Size(125, 51);
			this->BtnTrailer->TabIndex = 15;
			this->BtnTrailer->Text = L"Watch Trailer";
			this->BtnTrailer->UseVisualStyleBackColor = false;
			this->BtnTrailer->Click += gcnew System::EventHandler(this, &ViewMovie::BtnTrailer_Click);
			// 
			// Overview_label
			// 
			this->Overview_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Overview_label->BackColor = System::Drawing::Color::Transparent;
			this->Overview_label->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Overview_label->ForeColor = System::Drawing::Color::White;
			this->Overview_label->Location = System::Drawing::Point(25, 455);
			this->Overview_label->Name = L"Overview_label";
			this->Overview_label->Size = System::Drawing::Size(785, 145);
			this->Overview_label->TabIndex = 26;
			this->Overview_label->Text = L"qcssssssssssss";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(26, 414);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(89, 24);
			this->label10->TabIndex = 25;
			this->label10->Text = L"Overview";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(509, 228);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 25);
			this->label4->TabIndex = 21;
			this->label4->Text = L"label4";
			// 
			// Date_label
			// 
			this->Date_label->AutoSize = true;
			this->Date_label->BackColor = System::Drawing::Color::Transparent;
			this->Date_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Date_label->ForeColor = System::Drawing::Color::White;
			this->Date_label->Location = System::Drawing::Point(41, 228);
			this->Date_label->Name = L"Date_label";
			this->Date_label->Size = System::Drawing::Size(60, 25);
			this->Date_label->TabIndex = 19;
			this->Date_label->Text = L"2017";
			// 
			// Rating_label
			// 
			this->Rating_label->AutoSize = true;
			this->Rating_label->BackColor = System::Drawing::Color::Transparent;
			this->Rating_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Rating_label->ForeColor = System::Drawing::Color::White;
			this->Rating_label->Location = System::Drawing::Point(263, 228);
			this->Rating_label->Name = L"Rating_label";
			this->Rating_label->Size = System::Drawing::Size(70, 25);
			this->Rating_label->TabIndex = 20;
			this->Rating_label->Text = L"label3";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel1->Location = System::Drawing::Point(1047, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(204, 710);
			this->panel1->TabIndex = 28;
			// 
			// Category1_label
			// 
			this->Category1_label->AutoSize = true;
			this->Category1_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Category1_label->ForeColor = System::Drawing::Color::White;
			this->Category1_label->Location = System::Drawing::Point(41, 287);
			this->Category1_label->Name = L"Category1_label";
			this->Category1_label->Size = System::Drawing::Size(70, 25);
			this->Category1_label->TabIndex = 29;
			this->Category1_label->Text = L"label1";
			// 
			// Category2_label
			// 
			this->Category2_label->AutoSize = true;
			this->Category2_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Category2_label->ForeColor = System::Drawing::Color::White;
			this->Category2_label->Location = System::Drawing::Point(150, 287);
			this->Category2_label->Name = L"Category2_label";
			this->Category2_label->Size = System::Drawing::Size(70, 25);
			this->Category2_label->TabIndex = 30;
			this->Category2_label->Text = L"label1";
			// 
			// Category3_label
			// 
			this->Category3_label->AutoSize = true;
			this->Category3_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Category3_label->ForeColor = System::Drawing::Color::White;
			this->Category3_label->Location = System::Drawing::Point(274, 287);
			this->Category3_label->Name = L"Category3_label";
			this->Category3_label->Size = System::Drawing::Size(70, 25);
			this->Category3_label->TabIndex = 31;
			this->Category3_label->Text = L"label1";
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel2->Controls->Add(this->Title_label);
			this->panel2->Controls->Add(this->Category3_label);
			this->panel2->Controls->Add(this->Overview_label);
			this->panel2->Controls->Add(this->BtnTrailer);
			this->panel2->Controls->Add(this->label10);
			this->panel2->Controls->Add(this->Category2_label);
			this->panel2->Controls->Add(this->Rating_label);
			this->panel2->Controls->Add(this->Category1_label);
			this->panel2->Controls->Add(this->Date_label);
			this->panel2->Controls->Add(this->BtnLibrary_AddRemove);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1041, 710);
			this->panel2->TabIndex = 32;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ViewMovie::panel2_Paint);
			// 
			// ViewMovie
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"ViewMovie";
			this->Size = System::Drawing::Size(1251, 710);
			this->Load += gcnew System::EventHandler(this, &ViewMovie::ViewMovie_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


		///:::::::::://////:::::::::://////:::::::::://////::::::::::///

		void Insert_Serie_Category(int idApiCategory) {
			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO SERIECATEGORY(ID_CATEGORY,ID_SERIE) VALUES(@ID_API, @ID_SERIE); ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_API", DataBaseOperations::GetIdCategory_Serie(idApiCategory));
				Command.Parameters->AddWithValue("@ID_SERIE", serie_->GetIdSerie());
				Command.ExecuteNonQuery();
				conx.Close();
				movie_->SetExist(true);

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		void AddCategoryToSerie(int idApiMovie) {

			String^ Url = "https://api.themoviedb.org/3/tv/" + idApiMovie + "?api_key=10f96818301b77e61d73d48aa20d81f9";


			HttpClient^ client = gcnew HttpClient();

			HttpResponseMessage^ response = client->GetAsync(Url)->Result;

			String^ jsonString = response->Content->ReadAsStringAsync()->Result;

			std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);

			/// ::::////////////////////////////////////////////////////////////////

			if (response->IsSuccessStatusCode)
			{
				// Response looks good - done using Curl now.  Try to parse the results
				// and print them out.#using <mscorlib.dll>
				//jsonData["results"][i]["original_title"]
				Json::Value jsonData;
				Json::Reader jsonReader;

				Json::StreamWriterBuilder builder;
				builder["indentation"] = "";


				if (jsonReader.parse(jsonString2, jsonData))
				{
					for (int i = 0; i < 3; i++)
					{
						int idcategory = jsonData["genres"][i]["id"].asInt();
						if (idcategory) {
							Insert_Serie_Category(idcategory);
						}
						else {
							break;
						}

					}
				}
			}
		}
		void AddToWatchListSerie(int ID_SERIE) {
			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO WATCHLIST_SERIE(ID_SERIE,ID_WATCH_LIST) VALUES(@ID_SERIE,@ID_WATCH_LIST); ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_WATCH_LIST", Login::User->GetIdWatchList());
				Command.Parameters->AddWithValue("@ID_SERIE", ID_SERIE);

				Command.ExecuteNonQuery();

				conx.Close();

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

		}

		void AddToDataBase_Serie() {

			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO SERIE(ID_API,TITLE,RATING,RELEASE_DATE,OVERVIEW,POSTER,BACKDROP,COUNTRY) VALUES(@ID_API,@TITLE,@RATING,@RELEASE_DATE,@OVERVIEW,@POSTER,@BACKDROP,@COUNTRY); ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@TITLE", serie_->GetName());
				Command.Parameters->AddWithValue("@ID_API", serie_->GetIdApi());
				Command.Parameters->AddWithValue("@RATING", serie_->GetRating());
				Command.Parameters->AddWithValue("@RELEASE_DATE", serie_->GetRealease_Date());
				Command.Parameters->AddWithValue("@OVERVIEW", serie_->GetOverview());
				Command.Parameters->AddWithValue("@COUNTRY", serie_->GetCountry());

				MemoryStream^ ms;
				try {
					ms = gcnew MemoryStream();
					serie_->GetPoster()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
					Command.Parameters->AddWithValue("@POSTER", ms->ToArray());

					ms = gcnew MemoryStream();
					serie_->GetBakcDrop()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
					Command.Parameters->AddWithValue("@BACKDROP", ms->ToArray());

				}
				catch (Exception^ ex) {
					MessageBox::Show(ex->Message);
				}
				finally {
					ms->Close();
				}


				Command.ExecuteNonQuery();

				//
				serie_->SetIdSerie(DataBaseOperations::LastInsertedSerie());

				AddCategoryToSerie(serie_->GetIdApi());
				AddToWatchListSerie(serie_->GetIdSerie());
					
				serie_->SetExist(true);

				conx.Close();


			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}


		}
		void DisplayCategory_Serie_FromDataBase() {
			try {
				int i = 1;
				SqlConnection conx(DataBaseConnection::ConnectionString());
				String^ queryString = "SELECT ID_CATEGORY FROM SERIECATEGORY where ID_SERIE = @ID_SERIE;";
				// select CATEGORY from CATEGORY where ID_CATEGORY = any(SELECT ID_CATEGORY FROM MOVIECATEGORY where ID_MOVIE = 109)
				SqlCommand^ command = gcnew SqlCommand(queryString, % conx);
				command->Parameters->AddWithValue("@ID_SERIE", serie_->GetIdSerie());

				conx.Open();

				SqlDataReader^ reader = command->ExecuteReader();
				while (reader->Read())
				{
					if (i == 1) {

						Category1_label->Text = DataBaseOperations::CategorySerie_ByIdCategory(Convert::ToInt32(reader[0]->ToString()));
					}
					else if (i == 2) {
						Category2_label->Text = DataBaseOperations::CategorySerie_ByIdCategory(Convert::ToInt32(reader[0]->ToString()));
					}
					else if (i == 3) {
						Category3_label->Text = DataBaseOperations::CategorySerie_ByIdCategory(Convert::ToInt32(reader[0]->ToString()));
					}
					i++;
				}
				conx.Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

		}
		void DisplayCategory_Serie_FromApi() {
			try {


				String^ Url = "https://api.themoviedb.org/3/tv/" + serie_->GetIdApi() + "?api_key=10f96818301b77e61d73d48aa20d81f9";
				HttpClient^ client = gcnew HttpClient();


				HttpResponseMessage^ response = client->GetAsync(Url)->Result;

				String^ jsonString = response->Content->ReadAsStringAsync()->Result;

				std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);


				if (response->IsSuccessStatusCode)
				{
					// Response looks good - done using Curl now.  Try to parse the results
					// and print them out.
					//jsonData["results"][i]["original_title"]
					Json::Value jsonData;
					Json::Reader jsonReader;

					Json::StreamWriterBuilder builder;
					builder["indentation"] = "";


					if (jsonReader.parse(jsonString2, jsonData))
					{
						for (int i = 0; i < 3; i++)

							for (int i = 0; i < 3; i++)
							{
								int idcategory = jsonData["genres"][i]["id"].asInt();
								if (idcategory) {
									if (i == 0) {
										Category1_label->Text = DataBaseOperations::CategorySerie_ByIdApiCategory(idcategory);
									}
									else if (i == 1) {
										Category2_label->Text = DataBaseOperations::CategorySerie_ByIdApiCategory(idcategory);
									}
									else if (i == 2) {
										Category3_label->Text = DataBaseOperations::CategorySerie_ByIdApiCategory(idcategory);
									}
								}
								else {
									break;
								}

							}
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		void RemoveFromDataBase_Serie() {
			try {

				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "DELETE FROM SERIE where ID_API = @ID_API;";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_API", serie_->GetIdApi());
				Command.ExecuteNonQuery();
				conx.Close();

				serie_->SetExist(false);
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}


		/////////////////////////////Movie:::::::::////////////////////////////


		void Insert_Movie_Category(int idApiCategory) {
			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO MOVIECATEGORY(ID_CATEGORY,ID_MOVIE) VALUES(@ID_API, @ID_MOVIE) ; ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_API", DataBaseOperations::GetIdCategory_Movie(idApiCategory));
				Command.Parameters->AddWithValue("@ID_MOVIE", movie_->GetIdMovie());
				Command.ExecuteNonQuery();
				conx.Close();
				movie_->SetExist(true);

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		
		void AddCategoryToMovie(int idApiMovie) {

			String^ Url = "https://api.themoviedb.org/3/movie/" + idApiMovie + "?api_key=10f96818301b77e61d73d48aa20d81f9";
			HttpClient^ client = gcnew HttpClient();

			HttpResponseMessage^ response = client->GetAsync(Url)->Result;

			String^ jsonString = response->Content->ReadAsStringAsync()->Result;

			std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);

			/// ::::////////////////////////////////////////////////////////////////

			if (response->IsSuccessStatusCode)
			{
				// Response looks good - done using Curl now.  Try to parse the results
				// and print them out.
				//jsonData["results"][i]["original_title"]
				Json::Value jsonData;
				Json::Reader jsonReader;

				Json::StreamWriterBuilder builder;
				builder["indentation"] = "";


				if (jsonReader.parse(jsonString2, jsonData))
				{
					for (int i = 0; i < 3; i++)
					{
						int idcategory = jsonData["genres"][i]["id"].asInt();
						if (idcategory) {
							Insert_Movie_Category(idcategory);
						}
						else {
							break;
						}

					}
				}
			}
		}
		void AddToWatchListMovie(int ID_MOVIE) {
			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO WATCHLIST_MOVIE(ID_MOVIE,ID_WATCH_LIST) VALUES(@ID_MOVIE,@ID_WATCH_LIST); ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_WATCH_LIST", Login::User->GetIdWatchList());
				Command.Parameters->AddWithValue("@ID_MOVIE", ID_MOVIE);

				Command.ExecuteNonQuery();

				conx.Close();

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

		}
		void AddToDataBase_Movie() {

			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO MOVIE(ID_API,TITLE,RATING,RELEASE_DATE,OVERVIEW,POSTER,BACKDROP) VALUES(@ID_API,@TITLE,@RATING,@RELEASE_DATE,@OVERVIEW,@POSTER,@BACKDROP); ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@TITLE", movie_->GetTitle());
				Command.Parameters->AddWithValue("@ID_API", movie_->GetIdApi());
				Command.Parameters->AddWithValue("@RATING", movie_->GetRating());
				Command.Parameters->AddWithValue("@RELEASE_DATE", movie_->GetRealease_Date());
				Command.Parameters->AddWithValue("@OVERVIEW", movie_->GetOverview());
				MemoryStream^ ms;
				try {
					ms = gcnew MemoryStream();
					movie_->GetPoster()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
					Command.Parameters->AddWithValue("@POSTER", ms->ToArray());

					ms = gcnew MemoryStream();
					movie_->GetBakcDrop()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
					Command.Parameters->AddWithValue("@BACKDROP", ms->ToArray());

				}
				finally {
					ms->Close();
				}
				Command.ExecuteNonQuery();

				movie_->SetIdMovie(DataBaseOperations::LastInsertedMovie());

				AddCategoryToMovie(movie_->GetIdApi());
				AddToWatchListMovie(movie_->GetIdMovie());

				conx.Close();
				movie_->SetExist(true);

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}


		}
		void RemoveFromDataBase_Movie() {
			try {

				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "DELETE FROM MOVIE where ID_API = @ID_API;";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_API", movie_->GetIdApi());
				Command.ExecuteNonQuery();
				conx.Close();

				movie_->SetExist(false);
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		void DisplayCategory_Movie_FromDataBase() {
			try {
				int i = 1;
				SqlConnection conx(DataBaseConnection::ConnectionString());
				String^ queryString = "SELECT ID_CATEGORY FROM MOVIECATEGORY where ID_MOVIE = @ID_MOVIE;";
				// select CATEGORY from CATEGORY where ID_CATEGORY = any(SELECT ID_CATEGORY FROM MOVIECATEGORY where ID_MOVIE = 109)
				SqlCommand^ command = gcnew SqlCommand(queryString, % conx);
				command->Parameters->AddWithValue("@ID_MOVIE", movie_->GetIdMovie());

				conx.Open();

				SqlDataReader^ reader = command->ExecuteReader();
				while (reader->Read())
				{
					if (i == 1) {

						Category1_label->Text = DataBaseOperations::CategoryMovie_ByIdCategory(Convert::ToInt32(reader[0]->ToString()));
					}
					else if (i == 2) {
						Category2_label->Text = DataBaseOperations::CategoryMovie_ByIdCategory(Convert::ToInt32(reader[0]->ToString()));
					}
					else if (i == 3) {
						Category3_label->Text = DataBaseOperations::CategoryMovie_ByIdCategory(Convert::ToInt32(reader[0]->ToString()));
					}
					i++;
				}
				conx.Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

		}
		void DisplayCategory_Movie_FromApi() {
			try {


				String^ Url = "https://api.themoviedb.org/3/movie/" + movie_->GetIdApi() + "?api_key=10f96818301b77e61d73d48aa20d81f9";
				HttpClient^ client = gcnew HttpClient();


				HttpResponseMessage^ response = client->GetAsync(Url)->Result;

				String^ jsonString = response->Content->ReadAsStringAsync()->Result;

				std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);


				if (response->IsSuccessStatusCode)
				{
					// Response looks good - done using Curl now.  Try to parse the results
					// and print them out.
					//jsonData["results"][i]["original_title"]
					Json::Value jsonData;
					Json::Reader jsonReader;

					Json::StreamWriterBuilder builder;
					builder["indentation"] = "";


					if (jsonReader.parse(jsonString2, jsonData))
					{
						for (int i = 0; i < 3; i++)

							for (int i = 0; i < 3; i++)
							{
								int idcategory = jsonData["genres"][i]["id"].asInt();
								if (idcategory) {
									if (i == 0) {
										Category1_label->Text = DataBaseOperations::CategoryMovie_ByIdApiCategory(idcategory);
									}
									else if (i == 1) {
										Category2_label->Text = DataBaseOperations::CategoryMovie_ByIdApiCategory(idcategory);
									}
									else if (i == 2) {
										Category3_label->Text = DataBaseOperations::CategoryMovie_ByIdApiCategory(idcategory);
									}
								}
								else {
									break;
								}

							}
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}

		///:::::::::://///:::::::::://////:::::::::://////::::::::::///



	private: System::Void ViewMovie_Load(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("hna");
		if (movie_->GetTitle() != "") {
			if (movie_->GetExist()) {
				DisplayCategory_Movie_FromDataBase();
				BtnLibrary_AddRemove->Text = "Remove from Library";
				BtnLibrary_AddRemove->Image = Image::FromFile("icons\\remove.png");

			}
			else {
				DisplayCategory_Movie_FromApi();
				BtnLibrary_AddRemove->Text = "Add To Library";
				BtnLibrary_AddRemove->Image = Image::FromFile("icons\\add.png");

			}
		}
		else if (serie_->GetName() != "") {
			if (serie_->GetExist()) {
				DisplayCategory_Serie_FromDataBase();
				BtnLibrary_AddRemove->Text = "Remove from Library";
				BtnLibrary_AddRemove->Image = Image::FromFile("icons\\remove.png");

			}
			else {

				DisplayCategory_Serie_FromApi();
				BtnLibrary_AddRemove->Text = "Add To Library";
				BtnLibrary_AddRemove->Image = Image::FromFile("icons\\add.png");

			}
		}



	}
	private: System::Void BtnLibrary_AddRemove_Click(System::Object^ sender, System::EventArgs^ e) {

		if (movie_->GetTitle() != "") {

			if (movie_->GetExist()) {
				RemoveFromDataBase_Movie();
				BtnLibrary_AddRemove->Text = "Add To Library";
				BtnLibrary_AddRemove->Image = Image::FromFile("icons\\add.png");
			}
			else {
				AddToDataBase_Movie();
				BtnLibrary_AddRemove->Text = "Remove from Library";
				BtnLibrary_AddRemove->Image = Image::FromFile("icons\\remove.png");
			}

			//BtnLibrary_AddRemove->ImageAlign = ImageAlign::MiddleLeft;

		}
		else if (serie_->GetName() != "") {
			if (serie_->GetExist()) {
				RemoveFromDataBase_Serie();
				BtnLibrary_AddRemove->Text = "Add To Library";
				BtnLibrary_AddRemove->Image = Image::FromFile("icons\\add.png");
			}
			else {
				AddToDataBase_Serie();
				BtnLibrary_AddRemove->Text = "Remove from Library";
				BtnLibrary_AddRemove->Image = Image::FromFile("icons\\remove.png");
			}

		}
	}
	private: System::Void BtnTrailer_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	};
}