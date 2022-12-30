#pragma once
#include "BlankUserControl.h"
#include "DaysUserControl.h"
#include "PosterPlanning.h"
#include "Movie.h"
#include "Serie.h"
#include "DataBaseOperations.h"
#include "WatchLater_UC.h"
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
	/// Description résumée de Calendar_uc
	/// </summary>
	public ref class Calendar_uc : public System::Windows::Forms::UserControl
	{
		static int month = DateTime::Now.Month;
		static int days = DateTime::Now.Day;
	private: System::Windows::Forms::FlowLayoutPanel^ listPanel;
	private: System::Windows::Forms::Button^ addSerie;

	private: System::Windows::Forms::Button^ addMv;


		   static int year = DateTime::Now.Year;
		   Panel^ content;
	public:
		Calendar_uc(Panel^ content)
		{
			InitializeComponent();
			this->content = content;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Calendar_uc()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ calendarPan;
	private: System::Windows::Forms::Button^ prevBtn;
	private: System::Windows::Forms::Button^ nextBtn;
	protected:

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
			this->calendarPan = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->prevBtn = (gcnew System::Windows::Forms::Button());
			this->nextBtn = (gcnew System::Windows::Forms::Button());
			this->listPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->addMv = (gcnew System::Windows::Forms::Button());
			this->addSerie = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// calendarPan
			// 
			this->calendarPan->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->calendarPan->Location = System::Drawing::Point(-1, 61);
			this->calendarPan->Name = L"calendarPan";
			this->calendarPan->Size = System::Drawing::Size(1059, 675);
			this->calendarPan->TabIndex = 0;
			// 
			// prevBtn
			// 
			this->prevBtn->Location = System::Drawing::Point(24, 13);
			this->prevBtn->Name = L"prevBtn";
			this->prevBtn->Size = System::Drawing::Size(99, 38);
			this->prevBtn->TabIndex = 1;
			this->prevBtn->Text = L"<";
			this->prevBtn->UseVisualStyleBackColor = true;
			this->prevBtn->Click += gcnew System::EventHandler(this, &Calendar_uc::prevBtn_Click);
			// 
			// nextBtn
			// 
			this->nextBtn->Location = System::Drawing::Point(138, 13);
			this->nextBtn->Name = L"nextBtn";
			this->nextBtn->Size = System::Drawing::Size(99, 38);
			this->nextBtn->TabIndex = 2;
			this->nextBtn->Text = L">";
			this->nextBtn->UseVisualStyleBackColor = true;
			this->nextBtn->Click += gcnew System::EventHandler(this, &Calendar_uc::nextBtn_Click);
			// 
			// listPanel
			// 
			this->listPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->listPanel->ForeColor = System::Drawing::Color::Coral;
			this->listPanel->Location = System::Drawing::Point(1058, 61);
			this->listPanel->Name = L"listPanel";
			this->listPanel->Size = System::Drawing::Size(302, 675);
			this->listPanel->TabIndex = 3;
			// 
			// addMv
			// 
			this->addMv->Location = System::Drawing::Point(1195, 8);
			this->addMv->Name = L"addMv";
			this->addMv->Size = System::Drawing::Size(130, 48);
			this->addMv->TabIndex = 1;
			this->addMv->Text = L"Add a movie";
			this->addMv->UseVisualStyleBackColor = true;
			this->addMv->Click += gcnew System::EventHandler(this, &Calendar_uc::addMv_Click);
			// 
			// addSerie
			// 
			this->addSerie->Location = System::Drawing::Point(1058, 7);
			this->addSerie->Name = L"addSerie";
			this->addSerie->Size = System::Drawing::Size(131, 48);
			this->addSerie->TabIndex = 0;
			this->addSerie->Text = L"add A TV Show";
			this->addSerie->UseVisualStyleBackColor = true;
			this->addSerie->Click += gcnew System::EventHandler(this, &Calendar_uc::addSerie_Click);
			// 
			// Calendar_uc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->addSerie);
			this->Controls->Add(this->addMv);
			this->Controls->Add(this->listPanel);
			this->Controls->Add(this->nextBtn);
			this->Controls->Add(this->prevBtn);
			this->Controls->Add(this->calendarPan);
			this->Name = L"Calendar_uc";
			this->Size = System::Drawing::Size(1360, 736);
			this->Load += gcnew System::EventHandler(this, &Calendar_uc::Calendar_uc_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void loadCalendar()
	{
		DateTime start = DateTime(year, month, 1);
		int days = DateTime::DaysInMonth(year, month);
		int daysOfWeek = Convert::ToInt32(start.DayOfWeek.ToString("d")) + 1;
		for (int i = 1;i < daysOfWeek;i++)
		{
			BlankUserControl^ bk = gcnew BlankUserControl();
			this->calendarPan->Controls->Add(bk);
		}
		for (int i = 1;i <= days;i++)
		{
			DaysUserControl^ uc = gcnew DaysUserControl(i, month, year);
			this->calendarPan->Controls->Add(uc);
			uc->setPanel(this->listPanel);
			uc->setPanelList(this->content);
		}
	}
	private: System::Void Calendar_uc_Load(System::Object^ sender, System::EventArgs^ e) {
		loadCalendar();
	}
	private: System::Void prevBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (month == 1)
		{
			month = 13;
			year--;
		}
		month--;
		//first day of month : 
		this->calendarPan->Controls->Clear();
		DateTime start = DateTime(year, month, 1);
		int days = DateTime::DaysInMonth(year, month);
		int daysOfWeek = Convert::ToInt32(start.DayOfWeek.ToString("d")) +1;
		if (daysOfWeek == 0)
			daysOfWeek = 7;
		for (int i = 1;i < daysOfWeek;i++)
		{
			BlankUserControl^ bk = gcnew BlankUserControl();
			this->calendarPan->Controls->Add(bk);
		}
		for (int i = 1;i <= days;i++)
		{
			DaysUserControl^ uc = gcnew DaysUserControl(i,month,year);
			this->calendarPan->Controls->Add(uc);
			uc->setPanel(this->listPanel);
			uc->setPanelList(this->content);
		}
	}
private: System::Void nextBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (month == 12)
		{
			month = 0;
			year++;
		}
		month++;
		//first day of month : 
		this->calendarPan->Controls->Clear();
		DateTime start = DateTime(year, month, 1);
		int days = DateTime::DaysInMonth(year, month);
		int daysOfWeek = Convert::ToInt32(start.DayOfWeek.ToString("d")) + 1;
		if (daysOfWeek == 0)
			daysOfWeek = 7;
		for (int i = 1;i < daysOfWeek;i++)
		{
			BlankUserControl^ bk = gcnew BlankUserControl();
			this->calendarPan->Controls->Add(bk);
		}
		for (int i = 1;i <= days;i++)
		{
			DaysUserControl^ uc = gcnew DaysUserControl(i, month, year);
			this->calendarPan->Controls->Add(uc);
			uc->setPanel(this->listPanel);
			uc->setPanelList(this->content);
		}
}
	private: void retrieveDataMovies()
	{
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "SELECT *FROM MOVIE ;";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		int index = 0;
		calendarPan->Controls->Clear();
		//for movies : 
		while (sqlReader->Read())
		{
			//creating an instance for every movie : 
			Movie^ movie_ = gcnew Movie();
			movie_->SetIdMovie(Convert::ToInt32(sqlReader[0]->ToString()));
			movie_->SetIdApi(Convert::ToInt32(sqlReader["ID_API"]->ToString()));
			movie_->SetTitle(sqlReader["TITLE"]->ToString());
			movie_->SetOverview(sqlReader["OVERVIEW"]->ToString());
			movie_->SetRealease_Date(Convert::ToDateTime(sqlReader["RELEASE_DATE"]->ToString()));
			movie_->SetRating((float)Convert::ToDouble(sqlReader["Rating"]->ToString()));

			// Create a MemoryStream to hold the image data
			MemoryStream^ ms = gcnew MemoryStream(sqlReader->GetSqlBinary(6).Value);
			// Load the image data into a Bitmap object
			Bitmap^ image = gcnew Bitmap(ms);
			movie_->SetPoster(image);

			ms = gcnew MemoryStream(sqlReader->GetSqlBinary(7).Value);
			// Load the image data into a Bitmap object
			image = gcnew Bitmap(ms);
			movie_->SetBakcDrop(image);
			movie_->SetExist(DataBaseOperations::Search_Movie(movie_->GetIdApi()));
			//creating a user control for it : 
			WatchLater_UC^ movie_userc = gcnew WatchLater_UC(movie_);
			calendarPan->Controls->Add(movie_userc);
		}
		conx.Close();
	}
	private: void retrieveTvShows()
	{
		String^ Query2 = "SELECT *FROM SERIE ;";
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		conx.Open();
		int index = 0;
		SqlCommand Cmd2(Query2, % conx);
		SqlDataReader^ sqlReader2 = Cmd2.ExecuteReader();
		//for series: 
		while (sqlReader2->Read())
		{
			//creating an instance for every movie : 
			Serie^ serie_ = gcnew Serie();
			serie_->SetIdSerie(Convert::ToInt32(sqlReader2[0]->ToString()));
			serie_->SetIdApi(Convert::ToInt32(sqlReader2["ID_API"]->ToString()));
			serie_->SetName(sqlReader2["TITLE"]->ToString());
			serie_->SetOverview(sqlReader2["OVERVIEW"]->ToString());
			serie_->SetRealease_Date(Convert::ToDateTime(sqlReader2["RELEASE_DATE"]->ToString()));
			serie_->SetRating((float)Convert::ToDouble(sqlReader2["Rating"]->ToString()));

			// Create a MemoryStream to hold the image data
			MemoryStream^ ms = gcnew MemoryStream(sqlReader2->GetSqlBinary(4).Value);
			// Load the image data into a Bitmap object
			Bitmap^ image = gcnew Bitmap(ms);
			serie_->SetPoster(image);

			ms = gcnew MemoryStream(sqlReader2->GetSqlBinary(5).Value);
			// Load the image data into a Bitmap object
			image = gcnew Bitmap(ms);
			serie_->SetBakcDrop(image);
			serie_->SetExist(DataBaseOperations::Search_Serie(serie_->GetIdApi()));
			//creating a user control for it : 
			WatchLater_UC^ serie_userc = gcnew WatchLater_UC(serie_);
			calendarPan->Controls->Add(serie_userc);
		}
		conx.Close();
	}
private: System::Void addMv_Click(System::Object^ sender, System::EventArgs^ e) {
	this->calendarPan->Controls->Clear();
	retrieveDataMovies();
}
private: System::Void addSerie_Click(System::Object^ sender, System::EventArgs^ e) {
	this->calendarPan->Controls->Clear();
	retrieveTvShows();

}
};
}
