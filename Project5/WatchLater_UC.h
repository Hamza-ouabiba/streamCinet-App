#pragma once
#include "Serie.h"
#include "Movie.h"
#include "PosterPlanning.h"

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
	/// Description résumée de WatchLater_UC
	/// </summary>
	public ref class WatchLater_UC : public System::Windows::Forms::UserControl
	{
	public:
		Movie^ movie_;
		Serie^ serie_;
		Panel^ panelMovies;
		Panel^ panelSeries;
		Panel^ panelContent;
		static int day;
		static int month;
		static int year;
		static int idPlanning;
		WatchLater_UC(Movie^ movie)
		{
			InitializeComponent();
			this->movie_ = movie;
			this->button1->BackgroundImage = movie->GetPoster();
			this->button1->Text = movie->GetTitle();
			serie_ = gcnew Serie();
			serie_->SetName("");
			this->day = day;
			this->month = month;
			this->year = year;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		WatchLater_UC(Serie^ serie)
		{
			InitializeComponent();
			this->serie_ = serie;
			this->button1->BackgroundImage = serie_->GetPoster();
			this->button1->Text = serie_->GetName();
			this->day = day;
			this->month = month;
			this->year = year;
			movie_ = gcnew Movie();
			movie_->SetTitle("");
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		void setPanelMovies(Panel^ panelMovies)
		{
			this->panelMovies = panelMovies;
		}
		void setPanelSeries(Panel^ panelSeries)
		{
			this->panelSeries = panelSeries;
		}
		void setPanelContent(Panel^ panelContent)
		{
			this->panelContent = panelContent;
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~WatchLater_UC()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(267, 357);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &WatchLater_UC::button1_Click);
			// 
			// WatchLater_UC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->button1);
			this->Name = L"WatchLater_UC";
			this->Size = System::Drawing::Size(267, 357);
			this->ResumeLayout(false);

		}
	private: bool checkDataMovie()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "select * from planning_movie where id_movie = " + movie_->GetIdMovie() + "and" + " id = " + idPlanning;
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		return sqlReader->HasRows;
	}
	private: bool checkDataSerie()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "select * from planning_serie where id_serie = " + serie_->GetIdSerie() + "and" + " id = " + idPlanning;
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		return sqlReader->HasRows;
	}
	private: void loadDataMovies()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "select MOVIE.ID_MOVIE,ID_API,TITLE,OVERVIEW,RELEASE_DATE,RATING,POSTER,BACKDROP from MOVIE join PLANNING_MOVIE on MOVIE.ID_MOVIE = PLANNING_MOVIE.ID_MOVIE join PLANNING on PLANNING_MOVIE.ID = PLANNING.ID where PLANNING.date = '" + this->day + "-" + this->month + "-" + this->year + "' and planning_movie.id_user = " + Login::User->GetIdUser();
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
			PosterPlanning^ movie_userc = gcnew PosterPlanning(movie_, this->panelContent, getIdPlanning());
			panelMovies->Controls->Add(movie_userc);
		}
	}
	private: int getIdPlanning()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "SELECT ID from PLANNING WHERE DATE =  '" + this->day + "-" + this->month + "-" + this->year + "'";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		if (sqlReader->Read())
			return Convert::ToInt32(sqlReader[0]->ToString());
	}
	private: void loadDataSeries()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "select SERIE.ID_SERIE,ID_API,TITLE,OVERVIEW,RELEASE_DATE,RATING,POSTER,BACKDROP from SERIE join PLANNING_SERIE on SERIE.ID_SERIE = PLANNING_SERIE.ID_SERIE join PLANNING on PLANNING_SERIE.ID = PLANNING.ID where PLANNING.date = '" + this->day + "-" + this->month + "-" + this->year + "' and PLANNING_SERIE.ID_USER = " + Login::User->GetIdUser();
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
			PosterPlanning^ serie_userc = gcnew PosterPlanning(serie_, this->panelContent, getIdPlanning());
			panelSeries->Controls->Add(serie_userc);
		}
	}
#pragma endregion
	private: void addDataBaseMovie()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "insert into planning_movie(ID,ID_MOVIE,id_user) values(" + idPlanning + "," + movie_->GetIdMovie() + "," + Login::User->GetIdUser() + ")";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
	}
	private: void addDataBaseSerie()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "insert into planning_serie(ID,ID_serie,id_user) values(" + idPlanning + "," + serie_->GetIdSerie() + "," + Login::User->GetIdUser() + ")";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (movie_->GetTitle() != "")
		{
			if (day && month && year)
			{
				if (checkDataMovie())
					MessageBox::Show("movie already existed in this Planification try another thing");
				else
				{
					MessageBox::Show("movie set to watch in specified date" + day + month + year);
					panelMovies->Controls->Clear();
					addDataBaseMovie();
					loadDataMovies();
				}
			}
			else MessageBox::Show("specify a day in the calendar section ");
		}
		else if (serie_->GetName() != "")
		{
			if (day && month && year)
			{
				if (checkDataSerie())
					MessageBox::Show("serie already Plannified in this date");
				else
				{
					panelSeries->Controls->Clear();
					addDataBaseSerie();
					loadDataSeries();

					//MessageBox::Show("serie in : " + serie_->GetIdSerie());
					MessageBox::Show("serie set to watch in specified date" + day + month + year);
				}
			}
			else MessageBox::Show("specify a day in the calendar section ");
		}
	}
	};
}
