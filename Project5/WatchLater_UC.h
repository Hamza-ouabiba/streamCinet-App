#pragma once
#include "Serie.h"
#include "Movie.h"
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
			movie_ = gcnew Movie();
			movie_->SetTitle("");
			this->day = day;
			this->month = month;
			this->year = year;
			//
			//TODO: ajoutez ici le code du constructeur
			//
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
		System::ComponentModel::Container ^components;

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
#pragma endregion
	private: void addDataBaseMovie()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		MessageBox::Show("this the id: " + idPlanning);
		String^ Query = "insert into planning_movie(ID,ID_MOVIE) values(" + idPlanning+ "," + movie_->GetIdMovie() + ")";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
	}
	private: void addDataBaseSerie()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "insert into planning_serie(ID,ID_serie) values(" + idPlanning + "," + serie_->GetIdSerie() + ")";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (movie_->GetTitle() != "")
		{
			if (checkDataMovie())
			{
				MessageBox::Show("movie already existed in this Planification try another thing");
			}
			else
			{
				MessageBox::Show("movie set to watch in specified date" + day + month + year);
				addDataBaseMovie();
			}
		}
		else if(serie_->GetName() != "")
		{
			if (checkDataSerie())
			{
				MessageBox::Show("serie already Plannified in this date");
			}
			else
			{
				MessageBox::Show("serie in : " + serie_->GetIdSerie());
				MessageBox::Show("serie set to watch in specified date" + day + month + year);
				addDataBaseSerie();
			}
		}
	}
	};
}
