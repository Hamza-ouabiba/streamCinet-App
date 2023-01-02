#pragma once
#include<string>
#include "PosterPlanning.h"
#include<iostream>
#include "WatchLater_UC.h"
#include "Movie.h"
#include "DataBaseOperations.h"
#include "Serie.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::IO;
using namespace std;


namespace Project5 {

	/// <summary>
	/// Description résumée de DaysUserControl
	/// </summary>
	public ref class DaysUserControl : public System::Windows::Forms::UserControl
	{
	private:
		int dayOfweek;
		int mo;
		int year;
		Panel^ panelMovies;
		Panel^ panelSeries;
		Panel^ list;
	public:
		DaysUserControl(int index, Panel^ movies, Panel^ series, Panel^ list)
		{
			InitializeComponent();
			this->dayOfweek = index;
			this->panelMovies = movies;
			this->list = list;
			this->panelSeries = series;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		DaysUserControl(int index, int month, int year)
		{
			InitializeComponent();
			this->dayOfweek = index;
			this->mo = month;
			this->year = year;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		void setPanelMovies(Panel^ panel)
		{
			this->panelMovies = panel;
		}
		void setPanelList(Panel^ panel)
		{
			this->list = panel;
		}
		void setPanelSeries(Panel^ panel)
		{
			this->panelSeries = panel;
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~DaysUserControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ days;
	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->days = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// days
			// 
			this->days->BackColor = System::Drawing::Color::Gainsboro;
			this->days->Dock = System::Windows::Forms::DockStyle::Fill;
			this->days->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->days->Location = System::Drawing::Point(0, 0);
			this->days->Name = L"days";
			this->days->Size = System::Drawing::Size(194, 111);
			this->days->TabIndex = 0;
			this->days->Text = L"1";
			this->days->UseVisualStyleBackColor = false;
			this->days->Click += gcnew System::EventHandler(this, &DaysUserControl::days_Click);
			// 
			// DaysUserControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->days);
			this->Name = L"DaysUserControl";
			this->Size = System::Drawing::Size(194, 111);
			this->Load += gcnew System::EventHandler(this, &DaysUserControl::DaysUserControl_Load);
			this->ResumeLayout(false);

		}
	private: int getIdPlanning()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "SELECT ID from PLANNING WHERE DATE =  '" + this->dayOfweek + "-" + this->mo + "-" + this->year + "'";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		if (sqlReader->Read())
			return Convert::ToInt32(sqlReader[0]->ToString());
	}
	private: void loadDataMovies()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "select MOVIE.ID_MOVIE,ID_API,TITLE,OVERVIEW,RELEASE_DATE,RATING,POSTER,BACKDROP from MOVIE join PLANNING_MOVIE on MOVIE.ID_MOVIE = PLANNING_MOVIE.ID_MOVIE join PLANNING on PLANNING_MOVIE.ID = PLANNING.ID where PLANNING.date = '" + this->dayOfweek + "-" + this->mo + "-" + this->year + "'";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		while (sqlReader->Read())
		{
			////creating an instance for every movie : 
			Movie^ movie_ = gcnew Movie();
			movie_->SetIdMovie(Convert::ToInt32(sqlReader["ID_MOVIE"]->ToString()));
			movie_->SetIdApi(Convert::ToInt32(sqlReader["ID_API"]->ToString()));
			movie_->SetTitle(sqlReader["TITLE"]->ToString());
			movie_->SetOverview(sqlReader["OVERVIEW"]->ToString());
			movie_->SetRealease_Date(Convert::ToDateTime(sqlReader["RELEASE_DATE"]->ToString()));
			movie_->SetRating((float)Convert::ToDouble(sqlReader["Rating"]->ToString()));

			//// Create a MemoryStream to hold the image data
			MemoryStream^ ms = gcnew MemoryStream(sqlReader->GetSqlBinary(6).Value);
			//// Load the image data into a Bitmap object
			Bitmap^ image = gcnew Bitmap(ms);
			movie_->SetPoster(image);

			ms = gcnew MemoryStream(sqlReader->GetSqlBinary(6).Value);
			// Load the image data into a Bitmap object
			image = gcnew Bitmap(ms);
			movie_->SetBakcDrop(image);
			//creating a user control for it : 
			PosterPlanning^ movie_userc = gcnew PosterPlanning(movie_, list,getIdPlanning());
			panelMovies->Controls->Add(movie_userc);

		}
	}
	
	private: void loadDataSeries()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "select SERIE.ID_SERIE,ID_API,TITLE,OVERVIEW,RELEASE_DATE,RATING,POSTER,BACKDROP from SERIE join PLANNING_SERIE on SERIE.ID_SERIE = PLANNING_SERIE.ID_SERIE join PLANNING on PLANNING_SERIE.ID = PLANNING.ID where PLANNING.date = '" + this->dayOfweek + "-" + this->mo + "-" + this->year + "'";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		while (sqlReader->Read())
		{
			//creating an instance for every movie : 
			Serie^ serie_ = gcnew Serie();
			serie_->SetIdSerie((Convert::ToInt32(sqlReader["ID_SERIE"]->ToString())));
			serie_->SetIdApi(Convert::ToInt32(sqlReader["ID_API"]->ToString()));
			serie_->SetName(sqlReader["TITLE"]->ToString());
			serie_->SetOverview(sqlReader["OVERVIEW"]->ToString());
			serie_->SetRealease_Date(Convert::ToDateTime(sqlReader["RELEASE_DATE"]->ToString()));
			serie_->SetRating((float)Convert::ToDouble(sqlReader["Rating"]->ToString()));

			// Create a MemoryStream to hold the image data
			MemoryStream^ ms = gcnew MemoryStream(sqlReader->GetSqlBinary(6).Value);
			// Load the image data into a Bitmap object
			Bitmap^ image = gcnew Bitmap(ms);
			serie_->SetPoster(image);

			ms = gcnew MemoryStream(sqlReader->GetSqlBinary(7).Value);
			// Load the image data into a Bitmap object
			image = gcnew Bitmap(ms);
			serie_->SetBakcDrop(image);
			//creating a user control for it : 
			PosterPlanning^ serie_userc = gcnew PosterPlanning(serie_, list,getIdPlanning());
			panelSeries->Controls->Add(serie_userc);
		}
	}
#pragma endregion
	private: System::Void DaysUserControl_Load(System::Object^ sender, System::EventArgs^ e) {
		this->days->Text = this->dayOfweek.ToString();
	}
	private: bool checkValidityDate()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "SELECT * from PLANNING where date = '" + this->dayOfweek + "-" + this->mo + "-" + this->year + "'";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		return sqlReader->HasRows;
	}
	private: int getLastDateInserted()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "select id from planning where date = '" + this->dayOfweek + "-" + this->mo + "-" + this->year + "'";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		if (sqlReader->Read())
			return Convert::ToInt32(sqlReader["id"]);
		return -1;
	}
	private: void insertDate()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "insert into planning(date) values('" + this->dayOfweek + "-" + this->mo + "-" + this->year + "')";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		conx.Close();
	}
	private: System::Void days_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkValidityDate()){
				this->panelMovies->Controls->Clear();
				this->panelSeries->Controls->Clear();
				loadDataMovies();
				loadDataSeries();
		}
		else
		{
			insertDate();
			MessageBox::Show("you can add a movie or a serie to this date : ");
		}
		WatchLater_UC::month = this->mo;
		WatchLater_UC::day = this->dayOfweek;
		WatchLater_UC::year = this->year;
		WatchLater_UC::idPlanning = getLastDateInserted();
	}
};
}
