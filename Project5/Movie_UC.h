#pragma once

#include "DataBaseConnection.h"  
#include "ClassData.h"  
#include<string>   
#include <msclr/marshal_windows.h>
#include"json/json.h"  
#using <System.Net.Http.dll>
#using <mscorlib.dll>
#using <System.Runtime.InteropServices.dll>

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
using namespace System::Net::Http;

namespace Project5 {

	 
	public ref class Movie_UC : public System::Windows::Forms::UserControl
	{
	 
	public:
	 
		Class_Movie^ Movie = nullptr;
		Class_Serie^ Serie = nullptr;
		Movie_UC(Class_Movie^ MV)
		{
			InitializeComponent();
			Movie = MV;
			this->Title_label->Text = Movie->GetTitle();
			this->Overview_label->Text = Movie->GetOverview();
			this->Rating_label->Text = Movie->GetRating().ToString();
			this->Date_label->Text = Movie->GetRealease_Date().ToString();
			this->panel1->BackgroundImage = Movie->GetBakcDrop();
			//
			//TODO: Add the constructor code here
			//
		}
		Movie_UC(Class_Serie^ Serie)
		{
			InitializeComponent();
			this->Serie = Serie;
			this->Title_label->Text = Serie->GetTitle();
			this->Overview_label->Text = Serie->GetOverview();
			this->Rating_label->Text = Serie->GetRating().ToString();
			this->Date_label->Text = Serie->GetRealease_Date().ToString();
			this->panel1->BackgroundImage = Serie->GetBakcDrop();
			//
			//TODO: Add the constructor code here
			//
		}
		void RemoveFromDataBase_Serie() {
			try {
				
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "DELETE FROM SERIE where ID_API = @ID_API;";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_API", Serie->GetIdApi());
				Command.ExecuteNonQuery();
				conx.Close();

				Movie->SetExist(false);
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		void AddToDataBase_Serie() {
			/*
			Image^ Img = Movie->GetPoster();
			FileStream^ File = gcnew FileStream(Img->ToString(), FileMode::Open, FileAccess::Read);
			BinaryReader^ Br = gcnew BinaryReader(File);
			MessageBox::Show(Br->ReadBytes((int)File->Length)->ToString());
			*/
			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO SERIE(ID_API,TITLE,RATING,RELEASE_DATE,OVERVIEW,POSTER,BACKDROP,COUNTRY) VALUES(@ID_API,@TITLE,@RATING,@RELEASE_DATE,@OVERVIEW,@POSTER,@BACKDROP,@COUNTRY); ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@TITLE", Serie->GetTitle());
				Command.Parameters->AddWithValue("@ID_API", Serie->GetIdApi());
				Command.Parameters->AddWithValue("@RATING", Serie->GetRating());
				Command.Parameters->AddWithValue("@RELEASE_DATE", Serie->GetRealease_Date());
				Command.Parameters->AddWithValue("@OVERVIEW", Serie->GetOverview());
				Command.Parameters->AddWithValue("@POSTER", Serie->GetPoster());
				Command.Parameters->AddWithValue("@BACKDROP", Serie->GetBakcDrop());
				Command.Parameters->AddWithValue("@COUNTRY", Serie->GetCountry());

				MemoryStream^ ms ;
				try {
					ms = gcnew MemoryStream();
					Serie->GetPoster()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
					Command.Parameters->AddWithValue("@POSTER", ms->ToArray());

					ms = gcnew MemoryStream();
					Serie->GetBakcDrop()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
					Command.Parameters->AddWithValue("@BACKDROP", ms->ToArray());

				}
				finally {
					ms->Close();
				}
				

				Command.ExecuteNonQuery();
				conx.Close();
				Serie->SetExist(true);
				/*
				* 
				unsigned char  data [length];
					ms->Read(data, 0, length);
				Bitmap^ bitmap = gcnew Bitmap(Movie->GetPoster());
				Command.Parameters->AddWithValue("@POSTER", bitmap);
				bitmap = gcnew Bitmap(Movie->GetBakcDrop());
				Command.Parameters->AddWithValue("@BACKDROP",bitmap);
				*/

				
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
				Command.Parameters->AddWithValue("@ID_API", Movie->GetIdApi());
				Command.ExecuteNonQuery();
				conx.Close();

				Movie->SetExist(false);
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
	 
		///:::::::::://////:::::::::://////:::::::::://////::::::::::///

		void AddCategory(int idApiCategory) {
			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO MOVIECATEGORY(ID_CATEGORY,ID_MOVIE) VALUES((select ID_CATEGORY from CATEGORY where ID_API=@ID_API),(SELECT MAX(ID_MOVIE) from MOVIE) ); ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_API", idApiCategory); 

				Command.ExecuteNonQuery();
				conx.Close();
				Movie->SetExist(true);

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		void AddCategoryMovie(int idApiMovie) {

			String^ Url = "https://api.themoviedb.org/3/movie/"+ idApiMovie +"?api_key=10f96818301b77e61d73d48aa20d81f9";
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
				stringstream ss;
				string data; 

				Class_Movie^ Movie = gcnew Class_Movie();

				Json::StreamWriterBuilder builder;
				builder["indentation"] = "";


				if (jsonReader.parse(jsonString2, jsonData))
				{
					for (int i = 0; i < 3; i++)
					{
						int idcategory = jsonData["genres"][i]["id"].asInt();
						if (idcategory) {
							AddCategory(idcategory);
						}
						else {
							break;
						}
						
					}
						

				}
			}
			
		}

		///:::::::::://////:::::::::://////:::::::::://////::::::::::///
		void AddToDataBase_Movie() {
		
			 
			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO MOVIE(ID_API,TITLE,RATING,RELEASE_DATE,OVERVIEW,POSTER,BACKDROP) VALUES(@ID_API,@TITLE,@RATING,@RELEASE_DATE,@OVERVIEW,@POSTER,@BACKDROP); ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@TITLE", Movie->GetTitle());
				Command.Parameters->AddWithValue("@ID_API", Movie->GetIdApi());
				Command.Parameters->AddWithValue("@RATING", Movie->GetRating());
				Command.Parameters->AddWithValue("@RELEASE_DATE", Movie->GetRealease_Date());
				Command.Parameters->AddWithValue("@OVERVIEW", Movie->GetOverview());

				MemoryStream^ ms;
				try {
					ms = gcnew MemoryStream();
					Movie->GetPoster()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
					Command.Parameters->AddWithValue("@POSTER", ms->ToArray());

					ms = gcnew MemoryStream();
					Movie->GetBakcDrop()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
					Command.Parameters->AddWithValue("@BACKDROP", ms->ToArray());

				}
				finally {
					ms->Close();
				}
				Command.ExecuteNonQuery();
				AddCategoryMovie(Movie->GetIdApi());

				conx.Close();
				Movie->SetExist(true);

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Movie_UC()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnLibrary_AddRemove;
	protected:
	private: System::Windows::Forms::Button^ BtnTrailer;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::Label^ Duration__label;

	private: System::Windows::Forms::Label^ Date_label;

	private: System::Windows::Forms::Label^ Rating_label;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ Category3_label;

	private: System::Windows::Forms::Label^ Category2_label;

	private: System::Windows::Forms::Label^ Category1_label;



	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ Overview_label;

	private: System::Windows::Forms::Label^ Title_label;
	private: System::Windows::Forms::Panel^ panel1;

	protected:


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
			this->BtnTrailer = (gcnew System::Windows::Forms::Button());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->Duration__label = (gcnew System::Windows::Forms::Label());
			this->Date_label = (gcnew System::Windows::Forms::Label());
			this->Rating_label = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Category3_label = (gcnew System::Windows::Forms::Label());
			this->Category2_label = (gcnew System::Windows::Forms::Label());
			this->Category1_label = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->Overview_label = (gcnew System::Windows::Forms::Label());
			this->Title_label = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
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
			this->BtnLibrary_AddRemove->Location = System::Drawing::Point(184, 104);
			this->BtnLibrary_AddRemove->Name = L"BtnLibrary_AddRemove";
			this->BtnLibrary_AddRemove->Size = System::Drawing::Size(171, 51);
			this->BtnLibrary_AddRemove->TabIndex = 3;
			this->BtnLibrary_AddRemove->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BtnLibrary_AddRemove->UseVisualStyleBackColor = false;
			this->BtnLibrary_AddRemove->Click += gcnew System::EventHandler(this, &Movie_UC::BtnLibrary_AddRemove_Click);
			// 
			// BtnTrailer
			// 
			this->BtnTrailer->BackColor = System::Drawing::Color::Transparent;
			this->BtnTrailer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnTrailer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnTrailer->ForeColor = System::Drawing::Color::White;
			this->BtnTrailer->Location = System::Drawing::Point(44, 104);
			this->BtnTrailer->Name = L"BtnTrailer";
			this->BtnTrailer->Size = System::Drawing::Size(125, 51);
			this->BtnTrailer->TabIndex = 2;
			this->BtnTrailer->Text = L"Watch Trailer";
			this->BtnTrailer->UseVisualStyleBackColor = false;
			this->BtnTrailer->Click += gcnew System::EventHandler(this, &Movie_UC::BtnTrailer_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->linkLabel1->ForeColor = System::Drawing::Color::White;
			this->linkLabel1->Location = System::Drawing::Point(114, 169);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(55, 13);
			this->linkLabel1->TabIndex = 4;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"linkLabel1";
			// 
			// Duration__label
			// 
			this->Duration__label->AutoSize = true;
			this->Duration__label->BackColor = System::Drawing::Color::Transparent;
			this->Duration__label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Duration__label->ForeColor = System::Drawing::Color::White;
			this->Duration__label->Location = System::Drawing::Point(38, 226);
			this->Duration__label->Name = L"Duration__label";
			this->Duration__label->Size = System::Drawing::Size(60, 24);
			this->Duration__label->TabIndex = 5;
			this->Duration__label->Text = L"label1";
			// 
			// Date_label
			// 
			this->Date_label->AutoSize = true;
			this->Date_label->BackColor = System::Drawing::Color::Transparent;
			this->Date_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Date_label->ForeColor = System::Drawing::Color::White;
			this->Date_label->Location = System::Drawing::Point(196, 226);
			this->Date_label->Name = L"Date_label";
			this->Date_label->Size = System::Drawing::Size(50, 24);
			this->Date_label->TabIndex = 6;
			this->Date_label->Text = L"2017";
			// 
			// Rating_label
			// 
			this->Rating_label->AutoSize = true;
			this->Rating_label->BackColor = System::Drawing::Color::Transparent;
			this->Rating_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Rating_label->ForeColor = System::Drawing::Color::White;
			this->Rating_label->Location = System::Drawing::Point(429, 226);
			this->Rating_label->Name = L"Rating_label";
			this->Rating_label->Size = System::Drawing::Size(60, 24);
			this->Rating_label->TabIndex = 7;
			this->Rating_label->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(602, 226);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 24);
			this->label4->TabIndex = 8;
			this->label4->Text = L"label4";
			// 
			// Category3_label
			// 
			this->Category3_label->AutoSize = true;
			this->Category3_label->BackColor = System::Drawing::Color::Transparent;
			this->Category3_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Category3_label->ForeColor = System::Drawing::Color::White;
			this->Category3_label->Location = System::Drawing::Point(292, 306);
			this->Category3_label->Name = L"Category3_label";
			this->Category3_label->Size = System::Drawing::Size(145, 24);
			this->Category3_label->TabIndex = 11;
			this->Category3_label->Text = L"Category1_label";
			// 
			// Category2_label
			// 
			this->Category2_label->AutoSize = true;
			this->Category2_label->BackColor = System::Drawing::Color::Transparent;
			this->Category2_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Category2_label->ForeColor = System::Drawing::Color::White;
			this->Category2_label->Location = System::Drawing::Point(180, 306);
			this->Category2_label->Name = L"Category2_label";
			this->Category2_label->Size = System::Drawing::Size(60, 24);
			this->Category2_label->TabIndex = 10;
			this->Category2_label->Text = L"label6";
			// 
			// Category1_label
			// 
			this->Category1_label->AutoSize = true;
			this->Category1_label->BackColor = System::Drawing::Color::Transparent;
			this->Category1_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Category1_label->ForeColor = System::Drawing::Color::White;
			this->Category1_label->Location = System::Drawing::Point(38, 306);
			this->Category1_label->Name = L"Category1_label";
			this->Category1_label->Size = System::Drawing::Size(60, 24);
			this->Category1_label->TabIndex = 9;
			this->Category1_label->Text = L"label7";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(38, 419);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(89, 24);
			this->label10->TabIndex = 12;
			this->label10->Text = L"Overview";
			// 
			// Overview_label
			// 
			this->Overview_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Overview_label->BackColor = System::Drawing::Color::Transparent;
			this->Overview_label->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Overview_label->ForeColor = System::Drawing::Color::White;
			this->Overview_label->Location = System::Drawing::Point(42, 462);
			this->Overview_label->Name = L"Overview_label";
			this->Overview_label->Size = System::Drawing::Size(1051, 118);
			this->Overview_label->TabIndex = 13;
			this->Overview_label->Text = L"qcssssssssssss";
			// 
			// Title_label
			// 
			this->Title_label->AutoSize = true;
			this->Title_label->BackColor = System::Drawing::Color::Transparent;
			this->Title_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title_label->ForeColor = System::Drawing::Color::White;
			this->Title_label->Location = System::Drawing::Point(56, 43);
			this->Title_label->Name = L"Title_label";
			this->Title_label->Size = System::Drawing::Size(171, 25);
			this->Title_label->TabIndex = 14;
			this->Title_label->Text = L"Game of thrones";
			this->Title_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel1->Controls->Add(this->BtnLibrary_AddRemove);
			this->panel1->Controls->Add(this->Title_label);
			this->panel1->Controls->Add(this->BtnTrailer);
			this->panel1->Controls->Add(this->Overview_label);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->linkLabel1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->Category3_label);
			this->panel1->Controls->Add(this->Duration__label);
			this->panel1->Controls->Add(this->Category2_label);
			this->panel1->Controls->Add(this->Date_label);
			this->panel1->Controls->Add(this->Category1_label);
			this->panel1->Controls->Add(this->Rating_label);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1151, 655);
			this->panel1->TabIndex = 15;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Movie_UC::panel1_Paint);
			// 
			// Movie_UC
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->Name = L"Movie_UC";
			this->Size = System::Drawing::Size(1151, 655);
			this->Load += gcnew System::EventHandler(this, &Movie_UC::Movie_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion



	private: System::Void Movie_Load(System::Object^ sender, System::EventArgs^ e) {
		if (Movie->GetExist()) {

			BtnLibrary_AddRemove->Text = "Remove from Library";
			BtnLibrary_AddRemove->Image = Image::FromFile("icons\\remove.png");

		}
		else {
			BtnLibrary_AddRemove->Text = "Add To Library";
			BtnLibrary_AddRemove->Image = Image::FromFile("icons\\add.png");
		}
	}


	private: System::Void BtnLibrary_AddRemove_Click(System::Object^ sender, System::EventArgs^ e) {

		if (Movie) {

			if (Movie->GetExist()) {
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
		else {
			if (Serie->GetExist()) {
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
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}


    void getInformations()
		   {

			   /// <summary>
			   /// ::::////////////////HttpClient////////////////////////////////////////////////
			   /// 
			   HttpClient^ client = gcnew HttpClient();
			   HttpResponseMessage^ response = client->GetAsync("https://api.themoviedb.org/3/movie/0525/videos?api_key=10f96818301b77e61d73d48aa20d81f9")->Result;

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
				   stringstream ss;
				   string data;
				   string site = "https://image.tmdb.org/t/p/w500";

				   Class_Movie^ Movie = gcnew Class_Movie();

				   Json::StreamWriterBuilder builder;
				   builder["indentation"] = "";

				   
				   if (jsonReader.parse(jsonString2, jsonData))
				   {
					   for (int index = 0; index <= 4; index++)
					   {

						   string type = jsonData["results"][index]["type"].toStyledString();
						   type.erase(remove(type.begin(), type.end(), '"'));

						   MessageBox::Show(msclr::interop::marshal_as<System::String^>(type));
						   if (type == "Trailer") {

							   string key = jsonData["results"][index]["key"].toStyledString();
							   key.erase(remove(key.begin(), key.end(), '"'));

							   Movie->SetTrailer(msclr::interop::marshal_as<System::String^>(key));
							   MessageBox::Show(Movie->GetTrailer());
							   break;
						   }
					   }



				   }
			   }
		   }
	
	private: System::Void BtnTrailer_Click(System::Object^ sender, System::EventArgs^ e) {

	
		if (Movie->GetTrailer() == nullptr) {
			getInformations();
		}
		else {
			MessageBox::Show(Movie->GetTrailer());
		}
	
	}	


};
};