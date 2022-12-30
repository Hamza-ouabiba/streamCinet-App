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
		Panel^ panelContent;
		Panel^ list;
	public:
		DaysUserControl(int index,Panel^ show)
		{
			InitializeComponent();
			this->dayOfweek = index;
			this->panelContent = show;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		DaysUserControl(int index,int month,int year)
		{
			InitializeComponent();
			this->dayOfweek = index;
			this->mo = month;
			this->year = year;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		void setPanel(Panel^ panel)
		{
			this->panelContent = panel;
		}
		void setPanelList(Panel^ panel)
		{
			this->list = panel;
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
		System::ComponentModel::Container ^components;

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
			this->days->Dock = System::Windows::Forms::DockStyle::Fill;
			this->days->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->days->Location = System::Drawing::Point(0, 0);
			this->days->Name = L"days";
			this->days->Size = System::Drawing::Size(194, 111);
			this->days->TabIndex = 0;
			this->days->Text = L"1";
			this->days->UseVisualStyleBackColor = true;
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
	private: void loadDataMovies()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "select ID_API,TITLE,OVERVIEW,RELEASE_DATE,RATING,POSTER,BACKDROP from MOVIE join PLANNING_MOVIE on MOVIE.ID_MOVIE = PLANNING_MOVIE.ID_MOVIE join PLANNING on PLANNING_MOVIE.ID = PLANNING.ID where PLANNING.date = '" + this->dayOfweek + "-" + this->mo + "-" + this->year + "'";
		MessageBox::Show(Query);
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		while (sqlReader->Read())
		{
			MessageBox::Show(sqlReader[0]->ToString());
			////creating an instance for every movie : 
			Movie^ movie_ = gcnew Movie();
			movie_->SetIdMovie(Convert::ToInt32(sqlReader[0]->ToString()));
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
			movie_->SetExist(DataBaseOperations::Search_Movie(movie_->GetIdApi()));
			//creating a user control for it : 
			PosterPlanning^ movie_userc = gcnew PosterPlanning(movie_,list);
			panelContent->Controls->Add(movie_userc);
		}
	}
	private: void loadDataSeries()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "select ID_API,TITLE,OVERVIEW,RELEASE_DATE,RATING,POSTER,BACKDROP from SERIE join PLANNING_SERIE on SERIE.ID_SERIE = PLANNING_SERIE.ID_SERIE join PLANNING on PLANNING_SERIE.ID = PLANNING.ID where PLANNING.date = '" + this->dayOfweek + "-" + this->mo + "-" + this->year + "'";
		MessageBox::Show(Query);
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		while (sqlReader->Read())
		{
			//creating an instance for every movie : 
			Serie^ serie_ = gcnew Serie();
			serie_->SetIdApi(Convert::ToInt32(sqlReader[0]->ToString()));
			serie_->SetName(sqlReader["TITLE"]->ToString());
			serie_->SetOverview(sqlReader["OVERVIEW"]->ToString());
			serie_->SetRealease_Date(Convert::ToDateTime(sqlReader["RELEASE_DATE"]->ToString()));
			serie_->SetRating((float)Convert::ToDouble(sqlReader["Rating"]->ToString()));

			// Create a MemoryStream to hold the image data
			MemoryStream^ ms = gcnew MemoryStream(sqlReader->GetSqlBinary(5).Value);
			// Load the image data into a Bitmap object
			Bitmap^ image = gcnew Bitmap(ms);
			serie_->SetPoster(image);

			ms = gcnew MemoryStream(sqlReader->GetSqlBinary(6).Value);
			// Load the image data into a Bitmap object
			image = gcnew Bitmap(ms);
			serie_->SetBakcDrop(image);
			serie_->SetExist(DataBaseOperations::Search_Serie(serie_->GetIdApi()));
			//creating a user control for it : 
			PosterPlanning^ serie_userc = gcnew PosterPlanning(serie_,list);
			panelContent->Controls->Add(serie_userc);
		}
	}
#pragma endregion
		private: System::Void DaysUserControl_Load(System::Object^ sender, System::EventArgs^ e) {
			this->days->Text = this->dayOfweek.ToString();
		}
		private: bool checkValidityDate()
		{
			SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
			String^ Query = "SELECT * from PLANNING where date = '"+this->dayOfweek + "-" + this->mo + "-" + this->year+ "'";
			MessageBox::Show(Query);
			SqlCommand Cmd(Query, % conx);
			conx.Open();
			SqlDataReader^ sqlReader = Cmd.ExecuteReader();
			return sqlReader->HasRows;
		}
		private: int getLastDateInserted()
		{
			SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
			String^ Query = "select id from planning where date = '" + this->dayOfweek + "-" + this->mo + "-" + this->year + "'";
			MessageBox::Show(Query);
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
			String^ Query = "insert into planning(date) values('"+this->dayOfweek+"-"+this->mo+"-"+this->year+"')";
			MessageBox::Show(Query);
			SqlCommand Cmd(Query, % conx);
			conx.Open();
			SqlDataReader^ sqlReader = Cmd.ExecuteReader();
			conx.Close();
			MessageBox::Show("last index is : " + getLastDateInserted().ToString());
		}
	private: System::Void days_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("today is : " + this->dayOfweek + "/" + this->mo + "/" + this->year);
			WatchLater_UC::month = this->mo;
			WatchLater_UC::day = this->dayOfweek;
			WatchLater_UC::year = this->year;
			WatchLater_UC::idPlanning = getLastDateInserted();
			if (checkValidityDate())
			{
				this->panelContent->Controls->Clear();
				loadDataMovies();
				loadDataSeries();
			}
			else
			{
				insertDate();
				MessageBox::Show("you can add a movie or a serie to this date : ");
			}
	}
	};
}
