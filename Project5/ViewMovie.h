#pragma once
#include "Movie.h"
#include "Serie.h"
#include<string>
#include<iostream>
#include "DataBaseOperations.h"
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


namespace Project5 {

	/// <summary>
	/// Description résumée de ViewMovie
	/// </summary>
	public ref class ViewMovie : public System::Windows::Forms::UserControl
	{
	private:
		
	private: System::Windows::Forms::Panel^ panelImage;
	private: System::Windows::Forms::Panel^ blur;
	private: System::Windows::Forms::Button^ addLibraryBtn;

	private: System::Windows::Forms::Label^ title;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ idapi;
		   Movie^ movie_;
		   Serie^ serie_;
	public:
		ViewMovie(Movie^ movie)
		{
			InitializeComponent();
			this->movie_ = movie;
			serie_ = gcnew Serie();
			serie_->SetName("");
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		ViewMovie(Serie^ serie)
		{
			InitializeComponent();
			this->serie_ = serie;
			movie_ = gcnew Movie();
			movie_->SetTitle("");
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ViewMovie()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelImage = (gcnew System::Windows::Forms::Panel());
			this->blur = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->addLibraryBtn = (gcnew System::Windows::Forms::Button());
			this->title = (gcnew System::Windows::Forms::Label());
			this->idapi = (gcnew System::Windows::Forms::Label());
			this->panelImage->SuspendLayout();
			this->blur->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelImage
			// 
			this->panelImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panelImage->Controls->Add(this->blur);
			this->panelImage->Location = System::Drawing::Point(0, 0);
			this->panelImage->Name = L"panelImage";
			this->panelImage->Size = System::Drawing::Size(1266, 610);
			this->panelImage->TabIndex = 0;
			// 
			// blur
			// 
			this->blur->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->blur->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->blur->Controls->Add(this->idapi);
			this->blur->Controls->Add(this->panel1);
			this->blur->Controls->Add(this->addLibraryBtn);
			this->blur->Controls->Add(this->title);
			this->blur->Location = System::Drawing::Point(0, 0);
			this->blur->Name = L"blur";
			this->blur->Size = System::Drawing::Size(1266, 610);
			this->blur->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(901, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(365, 610);
			this->panel1->TabIndex = 2;
			// 
			// addLibraryBtn
			// 
			this->addLibraryBtn->Location = System::Drawing::Point(155, 214);
			this->addLibraryBtn->Name = L"addLibraryBtn";
			this->addLibraryBtn->Size = System::Drawing::Size(261, 69);
			this->addLibraryBtn->TabIndex = 1;
			this->addLibraryBtn->Text = L"Add to library";
			this->addLibraryBtn->UseVisualStyleBackColor = true;
			this->addLibraryBtn->Click += gcnew System::EventHandler(this, &ViewMovie::addLibraryBtn_Click);
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::SystemColors::Control;
			this->title->Location = System::Drawing::Point(138, 103);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(92, 25);
			this->title->TabIndex = 0;
			this->title->Text = L"Du texte";
			// 
			// idapi
			// 
			this->idapi->AutoSize = true;
			this->idapi->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->idapi->Location = System::Drawing::Point(451, 61);
			this->idapi->Name = L"idapi";
			this->idapi->Size = System::Drawing::Size(44, 16);
			this->idapi->TabIndex = 3;
			this->idapi->Text = L"label1";
			// 
			// ViewMovie
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->Controls->Add(this->panelImage);
			this->Name = L"ViewMovie";
			this->Size = System::Drawing::Size(1266, 610);
			this->Load += gcnew System::EventHandler(this, &ViewMovie::ViewMovie_Load);
			this->panelImage->ResumeLayout(false);
			this->blur->ResumeLayout(false);
			this->blur->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ViewMovie_Load(System::Object^ sender, System::EventArgs^ e) {
		if (movie_->GetTitle() != "")
		{
			//this->overview->Text = movie_->GetOverview();
			if (movie_->GetExist())
			{
				this->addLibraryBtn->Text = "Delete from library";
			}
			else
			{
				this->addLibraryBtn->Text = "Add to library";
			}
			this->title->Text = movie_->GetTitle();
			this->panelImage->BackgroundImage = movie_->GetBakcDrop();
		}
		else
		{
			if (serie_->GetExist())
			{
				this->addLibraryBtn->Text = "Delete from library";
			}
			else
			{
				this->addLibraryBtn->Text = "Add to library";
			}
			this->title->Text = serie_->GetName();
			this->panelImage->BackgroundImage = serie_->GetBakcDrop();
		}
	}
	private: void RemoveFromDataBase() 
	{
		try 
		{

			SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
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
	private: void RemoveFromDataBase_serie()
	{
		try
		{

			SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
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
	private: void addToDataBase_movie()
	{
		try
		{
			SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
			conx.Open();
			String^ Query = "INSERT INTO MOVIE(ID_API,TITLE,rating,RELEASE_DATE,OVERVIEW,POSTER,BACKDROP) VALUES(@ID_API,@TITLE,@rating,@RELEASE_DATE,@OVERVIEW,@POSTER,@BACKDROP); ";
			SqlCommand Command(Query, % conx);
			Command.Parameters->AddWithValue("@TITLE", movie_->GetTitle());
			Command.Parameters->AddWithValue("@ID_API", movie_->GetIdApi());
			Command.Parameters->AddWithValue("@rating", movie_->GetRating());
			Command.Parameters->AddWithValue("@RELEASE_DATE", movie_->GetRealease_Date());
			Command.Parameters->AddWithValue("@OVERVIEW", movie_->GetOverview());
			MemoryStream^ ms;
			try 
			{
				ms = gcnew MemoryStream();
				movie_->GetPoster()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
				Command.Parameters->AddWithValue("@POSTER", ms->ToArray());

				ms = gcnew MemoryStream();
				movie_->GetBakcDrop()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
				Command.Parameters->AddWithValue("@BACKDROP", ms->ToArray());
				cout << "added to library";
				Command.ExecuteNonQuery();
				conx.Close();
				movie_->SetExist(true);
				cout << movie_->GetExist();
			}
			finally 
			{
				ms->Close();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: void addToDataBase_serie()
	{
		try
		{
			SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
			conx.Open();
			String^ Query = "INSERT INTO SERIE(ID_API,TITLE,rating,RELEASE_DATE,OVERVIEW,POSTER,BACKDROP,COUNTRY) VALUES(@ID_API,@TITLE,@rating,@RELEASE_DATE,@OVERVIEW,@POSTER,@BACKDROP,@COUNTRY); ";
			SqlCommand Command(Query, % conx);
			Command.Parameters->AddWithValue("@TITLE", serie_->GetName());
			Command.Parameters->AddWithValue("@ID_API", serie_->GetIdApi());
			Command.Parameters->AddWithValue("@rating", serie_->GetRating());
			Command.Parameters->AddWithValue("@RELEASE_DATE", serie_->GetRealease_Date());
			Command.Parameters->AddWithValue("@OVERVIEW", serie_->GetOverview());
			Command.Parameters->AddWithValue("@COUNTRY", serie_->GetCountry());
			MemoryStream^ ms;
			try
			{
				ms = gcnew MemoryStream();
				serie_->GetPoster()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
				Command.Parameters->AddWithValue("@POSTER", ms->ToArray());

				ms = gcnew MemoryStream();
				serie_->GetBakcDrop()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
				Command.Parameters->AddWithValue("@BACKDROP", ms->ToArray());
				cout << "added to library";
				Command.ExecuteNonQuery();
				conx.Close();
				serie_->SetExist(true);
				cout << serie_->GetExist();
			}
			finally
			{
				ms->Close();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void addLibraryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		//which means that the movie is displayed to the user : 
		if (movie_->GetTitle() != "")
		{
			if (movie_->GetExist())
			{
				RemoveFromDataBase();
				this->addLibraryBtn->Text = "Add to library";
			}
			else
			{
				addToDataBase_movie();
				this->addLibraryBtn->Text = "Delete from library";
			}
			//this->overview->Text = movie_->GetOverview();
		}
		else
		{
			if (serie_->GetExist())
			{
				RemoveFromDataBase_serie();
				this->addLibraryBtn->Text = "Add to library";
			}
			else
			{
				addToDataBase_serie();
				this->addLibraryBtn->Text = "Delete from library";
			}
			
		}
	}
};
}
